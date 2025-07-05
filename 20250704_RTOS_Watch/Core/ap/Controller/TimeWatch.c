/*
 * TimeWatch.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#include "TimeWatch.h"
#include  <string.h>

timeWatch_t timeWatchData;

void TimeWatch_Normal();
void TimeWatch_Modify_Sec();
void TimeWatch_Modify_Min();
void TimeWatch_Modify_Hour();



void TimeWatch_Init()
{
	timeWatchData.hour = 12;
	timeWatchData.min = 0;
	timeWatchData.sec = 0;
	timeWatchData.msec = 0;


	timeWatch_t *ptimeWatchData = osMailAlloc(timeWatchDataMailBox, 0);
	memcpy(ptimeWatchData, &timeWatchData, sizeof(timeWatch_t));
	osMailPut(timeWatchDataMailBox, ptimeWatchData);

}

void TimeWatch_Excute()
{
	timeWatchState_t state = Model_GetTimeWatchState();

	switch(state)
	{
	case S_TIMEWATCH_NORMAL:
		TimeWatch_Normal();
		break;
	case S_TIMEWATCH_SEC:
		TimeWatch_Modify_Sec();
		break;
	case S_TIMEWATCH_MIN:
		TimeWatch_Modify_Min();
		break;
	case S_TIMEWATCH_HOUR:
		TimeWatch_Modify_Hour();
		break;
	default:
		break;
	}



}


void TimeWatch_Normal()
{
	static uint16_t prevSec = 0;
	osEvent evt = osMessageGet(timeWatchEventMsgBox, 0);
	uint16_t evtState;

	if(evt.status == osEventMessage) {
		evtState = evt.value.v;

		if (evtState == EVENT_TIME_MODIFY) {
			Model_SetTimeWatchState(S_TIMEWATCH_SEC);
	}


	}


	if(prevSec == timeWatchData.msec) {
		return;
	}

	prevSec = timeWatchData.msec;

	timeWatch_t *ptimeWatchData = osMailAlloc(timeWatchDataMailBox, 0);
	memcpy(ptimeWatchData, &timeWatchData, sizeof(timeWatch_t));
	osMailPut(timeWatchDataMailBox, ptimeWatchData);
}

void TimeWatch_Modify_Sec()
{
	osEvent evt = osMessageGet(timeWatchEventMsgBox, 0);
	uint16_t evtState;

	if(evt.status == osEventMessage) {
		evtState = evt.value.v;

		if(evtState == EVENT_TIME_SET) {
			timeWatchData.sec++;
			timeWatchData.msec++;
			timeWatch_t *ptimeWatchData = osMailAlloc(timeWatchDataMailBox, 0);
			memcpy(ptimeWatchData, &timeWatchData, sizeof(timeWatch_t));
			osMailPut(timeWatchDataMailBox, ptimeWatchData);

		}
		else if (evtState == EVENT_TIME_MODIFY) {
			Model_SetTimeWatchState(S_TIMEWATCH_MIN);
		}
	}
}

void TimeWatch_Modify_Min()
{
	osEvent evt = osMessageGet(timeWatchEventMsgBox, 0);
	uint16_t evtState;

	if(evt.status == osEventMessage) {
		evtState = evt.value.v;

		if(evtState == EVENT_TIME_SET) {
			timeWatchData.min++;
			if(timeWatchData.min == 60) {
				timeWatchData.min = 0;
			}
			timeWatch_t *ptimeWatchData = osMailAlloc(timeWatchDataMailBox, 0);
			memcpy(ptimeWatchData, &timeWatchData, sizeof(timeWatch_t));
			osMailPut(timeWatchDataMailBox, ptimeWatchData);
		}
		else if (evtState == EVENT_TIME_MODIFY) {
			Model_SetTimeWatchState(S_TIMEWATCH_HOUR);
		}
	}
}

void TimeWatch_Modify_Hour()
{
	osEvent evt = osMessageGet(timeWatchEventMsgBox, 0);
	uint16_t evtState;

	if(evt.status == osEventMessage) {
		evtState = evt.value.v;

		if(evtState == EVENT_TIME_SET) {
			timeWatchData.hour++;
			timeWatch_t *ptimeWatchData = osMailAlloc(timeWatchDataMailBox, 0);
			memcpy(ptimeWatchData, &timeWatchData, sizeof(timeWatch_t));
			osMailPut(timeWatchDataMailBox, ptimeWatchData);
		}
		else if (evtState == EVENT_TIME_MODIFY) {
			Model_SetTimeWatchState(S_TIMEWATCH_NORMAL);
		}
	}
}

void timeWatch_IncTimeCallBack()
{

	if (timeWatchData.msec != 1000-1){
		timeWatchData.msec++;
		return;
	}
	timeWatchData.msec = 0;

	if (timeWatchData.sec != 60-1){
		timeWatchData.sec++;
		return;
	}
	timeWatchData.sec = 0;

	if (timeWatchData.min != 60-1){
		timeWatchData.min++;
		return;
	}
	timeWatchData.min = 0;

	if (timeWatchData.hour != 24-1){
		timeWatchData.hour++;
		return;
	}
	timeWatchData.hour = 0;


}


