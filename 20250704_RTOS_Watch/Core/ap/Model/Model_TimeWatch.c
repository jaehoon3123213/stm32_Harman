/*
 * Model_TimeWatch.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */


#include "Model_timeWatch.h"





static timeWatchState_t timeWatchState = S_TIMEWATCH_NORMAL;

osMessageQId timeWatchEventMsgBox;
osMessageQDef(timeWatchEventQueue, 4, uint16_t);


osMailQId timeWatchDataMailBox;
osMailQDef (timeWatchDataQueue, 4, timeWatch_t);



void Model_timeWatchInit()
{
	timeWatchEventMsgBox = osMessageCreate(osMessageQ(timeWatchEventQueue), NULL);
	timeWatchDataMailBox = osMailCreate(osMailQ(timeWatchDataQueue), NULL);
}



void Model_SetTimeWatchState(timeWatchState_t state)
{
	timeWatchState = state;
}

timeWatchState_t Model_GetTimeWatchState()
{
	return timeWatchState;
}

