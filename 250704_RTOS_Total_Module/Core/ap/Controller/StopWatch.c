/*
 * StopWatch.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */
#include "StopWatch.h"
#include <string.h>

stopWatch_t stopWatchData;

void StopWatch_Init()
{
	stopWatchData.hour = 0;
	stopWatchData.min = 0;
	stopWatchData.sec = 0;
	stopWatchData.msec = 0;

	stopWatch_t *pStopWatchData = osMailAlloc(stopWatchDataMailBox, 0);
	memcpy(pStopWatchData, &stopWatchData, sizeof(stopWatch_t));
	osMailPut(stopWatchDataMailBox, pStopWatchData);
}

void StopWatch_Execute()
{
	eStopWatchState_t state = Model_GetStopWatchState();

	switch(state)
	{
	case S_STOPWATCH_STOP:
		StopWatch_Stop();
		break;
	case S_STOPWATCH_RUN:
		StopWatch_Run();
		break;
	case S_STOPWATCH_CLEAR:
		StopWatch_Clear();
		break;
	default:
		break;
	}
}

void StopWatch_Stop()
{
	osEvent evt = osMessageGet(stopWatchEventMsgBox, 0);
	uint16_t evtState;

	if (evt.status == osEventMessage) {
		evtState = evt.value.v; // 메세지가 들어있다면 값을 받아오겠다.

		if (evtState == EVENT_RUN_STOP) {
			Model_SetStopWatchState(S_STOPWATCH_RUN);
		}
		else if (evtState == EVENT_CLEAR) {
			Model_SetStopWatchState(S_STOPWATCH_CLEAR);
		}
	}
}

void StopWatch_Run()
{
	osEvent evt = osMessageGet(stopWatchEventMsgBox, 0);
	uint16_t evtState;

	if (evt.status == osEventMessage) {
		evtState = evt.value.v;

		if (evtState == EVENT_RUN_STOP) {
			Model_SetStopWatchState(S_STOPWATCH_STOP);
		}
	}
	static stopWatch_t prevStopWatchData;
	// RUN은 메모리가 계속 바뀌니까 값이 바뀔때마다 읽어주기
	if (memcmp(&stopWatchData, &prevStopWatchData,sizeof(stopWatch_t))) {
		memcpy(&prevStopWatchData, &stopWatchData, sizeof(stopWatch_t));
		stopWatch_t *pStopWatchData = osMailAlloc(stopWatchDataMailBox, 0);
		memcpy(pStopWatchData, &stopWatchData, sizeof(stopWatch_t));
		osMailPut(stopWatchDataMailBox, pStopWatchData);
	}
}

void StopWatch_Clear()
{
	Model_SetStopWatchState(S_STOPWATCH_STOP);

	stopWatchData.hour = 0;
	stopWatchData.min = 0;
	stopWatchData.sec = 0;
	stopWatchData.msec = 0;

	stopWatch_t *pStopWatchData = osMailAlloc(stopWatchDataMailBox, 0);
	memcpy(pStopWatchData, &stopWatchData, sizeof(stopWatch_t));
	osMailPut(stopWatchDataMailBox, pStopWatchData);
}

void StopWatch_IncTimeCallBack()
{
	if (Model_GetStopWatchState() != S_STOPWATCH_RUN) {
		return;
	}

	if (stopWatchData.msec != 1000-1) {
		stopWatchData.msec++;
		return;
	}
	stopWatchData.msec = 0;

	if (stopWatchData.sec != 60-1) {
		stopWatchData.sec++;
		return;
	}
	stopWatchData.sec = 0;

	if (stopWatchData.min != 60-1) {
		stopWatchData.min++;
		return;
	}
	stopWatchData.min = 0;

	if (stopWatchData.hour != 24-1) {
		stopWatchData.hour++;
		return;
	}
	stopWatchData.hour = 0;
}
