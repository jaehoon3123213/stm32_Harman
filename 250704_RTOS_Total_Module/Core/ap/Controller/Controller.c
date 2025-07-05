/*
 * Controller.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */

#include "Controller.h"

void Controller_Init()
{
	TimeWatch_Init();
	StopWatch_Init();
	Distance_Init();
	TempHumi_Init();
}

void Controller_Execute()
{
	eModeState_t state = Model_GetModeState();

	switch (state)
	{
	case S_TIME_WATCH_MODE : TimeWatch_Execute();
		break;
	case S_STOP_WATCH_MODE : StopWatch_Execute();
		break;
	case S_DISTANCE_MODE : Distance_Execute();
		break;
	case S_TEMP_HUMI_MODE : TempHumi_Execute();
		break;
	}
	Controller_CheckEventMode();
}

void Controller_CheckEventMode()
{
	osEvent evt = osMessageGet(modeEventMsgBox, 0);
	uint16_t evtState;

	if (evt.status == osEventMessage) {
		evtState = evt.value.v;
		if (evtState != EVENT_MODE) {
			return;
		}

		eModeState_t state = Model_GetModeState();

		if (state == S_TIME_WATCH_MODE) {
			Model_SetModeState(S_STOP_WATCH_MODE);

			stopWatch_t *pStopWatchData = osMailAlloc(stopWatchDataMailBox, 0);
			memcpy(pStopWatchData, &stopWatchData, sizeof(stopWatch_t));
			osMailPut(stopWatchDataMailBox, pStopWatchData);
		}
		else if (state == S_STOP_WATCH_MODE) {
			Model_SetModeState(S_DISTANCE_MODE);

			timeWatch_t *pTimeWatchData = osMailAlloc(timeWatchDataMailBox, 0);
			memcpy(pTimeWatchData, &timeWatchData, sizeof(timeWatch_t));
			osMailPut(timeWatchDataMailBox, pTimeWatchData);
		}
		else if (state == S_DISTANCE_MODE) {
			Model_SetModeState(S_TEMP_HUMI_MODE);

			Distance_t *pDistanceData = osMailAlloc(DistanceDataMailBox, 0);
			memcpy(pDistanceData, &distanceData, sizeof(Distance_t));
			osMailPut(DistanceDataMailBox, pDistanceData);
		}
		else if (state == S_TEMP_HUMI_MODE) {
			Model_SetModeState(S_TIME_WATCH_MODE);

			TempHumi_t *pTempHumiData = osMailAlloc(TempHumiDataMailBox, 0);
			memcpy(pTempHumiData, &TempHumiData, sizeof(TempHumi_t));
			osMailPut(TempHumiDataMailBox, pTempHumiData);
		}
	}
}
