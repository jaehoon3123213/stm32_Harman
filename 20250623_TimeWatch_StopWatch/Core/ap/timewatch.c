/*
 * timewatch.c
 *
 *  Created on: Jun 23, 2025
 *      Author: kccistc
 */


#include "timewatch.h"


timeWatch_t timeWatch = {0};

void TimeWatch_IncTimeCallBack()
{

	if(timeWatch.msec < 1000 - 1) {
		timeWatch.msec ++;
		return;
	}
	timeWatch.msec = 0;

	if (timeWatch.sec < 60 -1)
	{
		timeWatch.sec++;
		return;
	}
timeWatch.sec = 0;

	if (timeWatch.min < 60 - 1) {
		timeWatch.min++;
		return;
	}
	timeWatch.min = 0;


	if (timeWatch.hour < 24 - 1) {
		timeWatch.hour++;
		return;
	}
	timeWatch.hour = 0;

};


void Timewatch_excute()
{
	FND_writeData(timeWatch.hour*100 + timeWatch.min);
}


