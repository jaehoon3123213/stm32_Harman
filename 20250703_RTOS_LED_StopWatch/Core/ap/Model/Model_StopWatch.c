/*
 * Model.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */


#include "Model_StopWatch.h"





static stopWatchState_e stopWatchState = S_STOPWATCH_STOP;

osMessageQId stopWatchEventMsgBox;
osMessageQDef(stopWatchEventQueue, 4, uint16_t);


osMailQId stopWatchDataMailBox;
osMailQDef (stopWatchDataQueue, 4, stopWatch_t);



void Model_StopWatchInit()
{
	stopWatchEventMsgBox = osMessageCreate(osMessageQ(stopWatchEventQueue), NULL);
	stopWatchDataMailBox = osMailCreate(osMailQ(stopWatchDataQueue), NULL);
}

void Model_SetStopWatchState(stopWatchState_e state)
{
	stopWatchState = state;
}

stopWatchState_e Model_GetStopWatchState()
{
	return stopWatchState;
}




























