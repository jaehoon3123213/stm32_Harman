/*
 * Controller.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */


#include "Controller.h"
#include <string.h>


void Controller_CheckEventMode();

void Controller_Init()
{
	StopWatch_Init();
	TimeWatch_Init();
	Distance_Init();
}


void Controller_Excute()
{
	eModestate_t state = Model_GetModeState();
	Controller_CheckEventMode();

	switch (state)
	{
	case S_TIME_WATCH_MODE:
		TimeWatch_Excute();
	case S_STOP_WATCH_MODE:
		StopWatch_Excute();
	case S_DISTANCE_MODE:
		Distance_Excute();
	}


}


void Controller_CheckEventMode()
{
	osEvent evt = osMessageGet(modeEventMsgBox, 0);
	uint16_t evtState = 0;
	eModestate_t state = Model_GetModeState();

	  if(evt.status == osEventMessage) {
	    	evtState = evt.value.v;
	    	if(evtState != EVENT_MODE){
	    		return;
	    	}

	    if(state == S_STOP_WATCH_MODE) {
		   Model_SetModeState(S_TIME_WATCH_MODE);
			stopWatch_t *pstopWatchData = osMailAlloc(stopWatchDataMailBox, 0);
			memcpy(pstopWatchData, &stopWatchData, sizeof(stopWatch_t));
			osMailPut(stopWatchDataMailBox, pstopWatchData);
		 }

	    else if(state == S_TIME_WATCH_MODE) {
		   Model_SetModeState(S_STOP_WATCH_MODE);
			timeWatch_t *ptimeWatchData = osMailAlloc(timeWatchDataMailBox, 0);
			memcpy(ptimeWatchData, &timeWatchData, sizeof(timeWatch_t));
			osMailPut(timeWatchDataMailBox, ptimeWatchData);
		 }
	  }


}
