/*
 * Listener_StopWatch.c
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */


#include "Listener_TimeWatch.h"

Button_Handler_t hBtnTimeModify;
Button_Handler_t hBtnTimeSet;

void Listener_TimeWatch_CheckButton();


void Listener_TimeWatchInit()
{
	  Button_Init(&hBtnTimeModify, GPIOB, GPIO_PIN_5);
	  Button_Init(&hBtnTimeSet, GPIOB, GPIO_PIN_3);


}



void Listener_TimeWatchExcute()
{

	Listener_TimeWatch_CheckButton();


}

void Listener_TimeWatch_CheckButton()
{
 if (Button_GetState(&hBtnTimeModify) == ACT_RELEASED) {
	 osMessagePut(timeWatchEventMsgBox, EVENT_TIME_MODIFY, 0);
 }
 else if (Button_GetState(&hBtnTimeSet) == ACT_RELEASED) {
	 osMessagePut(timeWatchEventMsgBox, EVENT_TIME_SET, 0);
 }



}
