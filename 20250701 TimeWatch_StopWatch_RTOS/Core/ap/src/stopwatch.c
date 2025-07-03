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

extern inputData_TypeDef controlData;

Watch_t stopWatch = {STOP_WATCH,0,0,0,0};
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
	Presenter_outData(stopWatch);
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
//	 FND_WriteDp(0b0110, FND_DP_OFF);
	if(controlData.id == STOPWATCH_RUN_STOP){
		controlData.id = NO_CONTROL;
		stopWatchState = RUN;
	}
	else if(controlData.id == STOPWATCH_CLEAR){
		controlData.id = NO_CONTROL;
		stopWatchState = CLEAR;
	}


}

void StopWatch_Run()
{
	if(controlData.id == STOPWATCH_RUN_STOP){
		controlData.id = NO_CONTROL;
		stopWatchState = STOP;
	}




}

void StopWatch_Clear()
{
	stopWatchState = STOP;
	stopWatch.msec = 0;
	stopWatch.sec = 0;
	stopWatch.min = 0;
	stopWatch.hour = 0;

//	FND_writeData((stopWatch.min % 10 * 1000) + (stopWatch.sec *10) + (stopWatch.msec/100));
}
