/*
 * stopwatch.c
 *
 *  Created on: Jun 23, 2025
 *      Author: kccistc
 */


#include "stopwatch.h"

typedef enum {STOP, RUN, CLEAR} stopWatchState_t;
void StopWatch_IncTime();
void StopWatch_Stop();
void StopWatch_Run();
void StopWatch_Clear();

extern Button_Handler_t hBtnClear;
extern Button_Handler_t hBtnRunStop;
extern Button_Handler_t hBtnMode;

stopWatch_t stopWatch = {0};
stopWatchState_t stopWatchState = STOP;



void  Stopwatch_excute()
{
	switch (stopWatchState)
	{
	case STOP:
		StopWatch_Stop();
		break;
	case RUN:
		StopWatch_Run();
		break;
	case CLEAR:
		StopWatch_Clear();
		break;
	}
}



void StopWatch_IncTimeCallBack()
{
	if(stopWatchState == RUN){
		StopWatch_IncTime();

	}
}

void StopWatch_IncTime()
{

	if(stopWatch.msec < 1000 - 1) {
		stopWatch.msec ++;
		return;
	}
	stopWatch.msec = 0;

	if (stopWatch.sec < 60 -1)
	{
		stopWatch.sec++;
		return;
	}
	stopWatch.sec = 0;

	if (stopWatch.min < 60 - 1) {
		stopWatch.min++;
		return;
	}
	stopWatch.min = 0;


	if (stopWatch.hour < 24 - 1) {
		stopWatch.hour++;
		return;
	}
	stopWatch.hour = 0;

}

void StopWatch_Stop()
{
	 FND_WriteDp(0b0110, FND_DP_OFF);
	if(Button_GetState(&hBtnRunStop) == ACT_PUSHED){
		stopWatchState = RUN;
	}
	else if(Button_GetState(&hBtnClear) == ACT_PUSHED){
		stopWatchState = CLEAR;
	}
	FND_writeData((stopWatch.min % 10 * 1000) + (stopWatch.sec *10) + (stopWatch.msec/100));

}

void StopWatch_Run()
{
	if(Button_GetState(&hBtnRunStop) == ACT_PUSHED){
		stopWatchState = STOP;
	}

	 FND_WriteDp(0b0110, FND_DP_OFF);
	FND_writeData((stopWatch.min % 10 * 1000) + (stopWatch.sec *10) + (stopWatch.msec/100));
	if(stopWatch.msec%100 <50)
	{
		FND_WriteDp(FND_DP_10, FND_DP_ON);
	}
	else {
		FND_WriteDp(FND_DP_10, FND_DP_OFF);
	}

	if(stopWatch.msec <500)
	{
		FND_WriteDp(FND_DP_1000, FND_DP_ON);
	}
	else {
		FND_WriteDp(FND_DP_1000, FND_DP_OFF);
	}

}

void StopWatch_Clear()
{
	stopWatchState = STOP;
	stopWatch.msec = 0;
	stopWatch.sec = 0;
	stopWatch.min = 0;
	stopWatch.hour = 0;
	FND_writeData((stopWatch.min % 10 * 1000) + (stopWatch.sec *10) + (stopWatch.msec/100));
}
