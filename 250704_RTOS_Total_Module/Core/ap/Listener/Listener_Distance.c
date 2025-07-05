/*
 * Listener_Distance.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */


#include "Listener_Distance.h"

Button_TypeDef hbtnDistance;
UltraSonic_TypeDef sensor;

void Listener_DistanceInit()
{
	Button_Init(&hbtnDistance, GPIOB, GPIO_PIN_3);
	UltraSonic_Init(&sensor, GPIOC, GPIO_PIN_7, GPIOA, GPIO_PIN_9);
}

void Listener_DistanceExecute()
{
	Listener_Distance_CheckButton();
}

void Listener_Distance_CheckButton()
{
	if (Button_GetState(&hbtnDistance) == ACT_RELEASED) {
		osMessagePut(DistanceEventMsgBox, EVENT_DISTANCE, 0);
	}
}
