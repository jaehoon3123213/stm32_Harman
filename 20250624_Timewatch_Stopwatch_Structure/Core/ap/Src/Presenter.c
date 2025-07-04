/*
 * Presenter.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */


#include "Presenter.h"
#include <string.h>
#include <stdio.h>
#include "usart.h"

static watch_t dispData = {0,0,0,12,TIME_WATCH,0};

static void Presenter_DispTimeWatch(watch_t watchData);
static void Presenter_DispStopWatch(watch_t watchData);
static void Presnter_DispMonitorTimeWatch(watch_t watchData);
static void Presnter_DispMonitorStopWatch(watch_t watchData);

void Presenter_outData(watch_t watchData)
{
    memcpy(&dispData, &watchData, sizeof(watch_t));
}

void Presenter_Execute()
{
    if (dispData.id == TIME_WATCH)
    {
        Presenter_DispTimeWatch(dispData);
    }
    else // STOP_WATCH
    {
        Presenter_DispStopWatch(dispData);
    }
}


void Presenter_DispTimeWatch(watch_t watchData)
{
    FND_WriteData(watchData.hour*100+watchData.min,0x04,watchData.dot);
    Presnter_DispMonitorTimeWatch(watchData);

}



void Presenter_DispStopWatch(watch_t watchData)
{
    FND_WriteData((watchData.min % 10 * 1000) + (watchData.sec * 10) + (watchData.msec/100),0x0a,watchData.dot);
    Presnter_DispMonitorStopWatch(watchData);
}


void Presnter_DispMonitorTimeWatch(watch_t watchData)
{
	char str[50];
	sprintf(str,"Time Watch : %02d:%02d:%02d.%03d\n", watchData.hour, watchData.min, watchData.sec, watchData.msec);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, strlen(str), 1000);
}


void Presnter_DispMonitorStopWatch(watch_t watchData)
{
	char str[50];
	sprintf(str,"Stop Watch : %02d:%02d:%02d.%03d\n", watchData.hour, watchData.min, watchData.sec, watchData.msec);
	HAL_UART_Transmit(&huart2, (uint8_t*) str, strlen(str), 1000);
}












