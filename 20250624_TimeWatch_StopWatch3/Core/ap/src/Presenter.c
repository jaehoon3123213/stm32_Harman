/*
 * Presenter.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */
#include "Presenter.h"
#include <string.h>

static void Presenter_DispTimeWatch(watch_t watchData);
static void Presenter_DispStopWatch(watch_t watchData);

static watch_t dispData = {TIME_WATCH,12,0,0,0};

void Presenter_OutData(watch_t watchData)
{
	memcpy(&dispData, &watchData, sizeof(watch_t)); // data copy (watchData -> dispData)
}

void Presenter_Excute()
{
	if (dispData.id == TIME_WATCH) {
		Presenter_DispTimeWatch(dispData);
	} else {
		Presenter_DispStopWatch(dispData);
	}
}

void Presenter_DispTimeWatch(watch_t watchData)
{
	FND_WriteData(watchData.hour*100 + watchData.min);

	FND_WriteDp(FND_DP_1000|FND_DP_1|FND_DP_10, FND_DP_OFF);

	if(watchData.msec < 500){
		FND_WriteDp(FND_DP_100, FND_DP_ON);
	} else {
	    FND_WriteDp(FND_DP_100, FND_DP_OFF);
	}
}

void Presenter_DispStopWatch(watch_t watchData)
{
	FND_WriteData((watchData.min %10 * 1000) + (watchData.sec*10)+(watchData.msec/100));

	FND_WriteDp(FND_DP_100|FND_DP_1, FND_DP_OFF);

	if (watchData.msec%100 < 50){            //
	   FND_WriteDp(FND_DP_10, FND_DP_ON);
	} else {
	   FND_WriteDp(FND_DP_10, FND_DP_OFF);
	}

	if (watchData.msec < 500){
	   FND_WriteDp(FND_DP_1000, FND_DP_ON);
	} else {
	   FND_WriteDp(FND_DP_1000, FND_DP_OFF);
	}
}
