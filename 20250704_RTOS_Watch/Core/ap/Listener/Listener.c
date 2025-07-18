/*
 * Listener.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */
#include "Listener.h"

Button_Handler_t hbtnMode;

void Listener_CheckButton();

void Listener_Init()
{
	Listener_StopWatchInit();
	Listener_TimeWatchInit();
	Button_Init(&hbtnMode, GPIOA, GPIO_PIN_10);
	Listener_DistanceInit();


}


void Listener_Excute()
{
	eModestate_t state = Model_GetModeState();
	Listener_CheckButton();
	switch(state)
	{
	case S_TIME_WATCH_MODE:
		Listener_TimeWatchExcute();
		break;
	case S_STOP_WATCH_MODE:
       	Listener_StopWatchExcute();
       	break;
	case S_DISTANCE_MODE:
		Listener_DistanceExcute();
	}

}



void Listener_CheckButton()
{
 if (Button_GetState(&hbtnMode) == ACT_RELEASED) {
	 osMessagePut(modeEventMsgBox, EVENT_MODE, 0);
 }


}



