/*
 * Listener_distance.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */


#include "Listener_distnace.h"


Button_Handler_t hbtndis;

void Listener_DistanceExcute()
{

}


void Listener_DistanceInit()
{
	UltraSonic_Init (GPIOA, GPIO_PIN_9, GPIOC, GPIO_PIN_7);
	Button_Init(&hbtndis, GPIOB, GPIO_PIN_5);
}


void Listener_Distance_CheckButton()
{
 if (Button_GetState(&hbtndis) == ACT_PUSHED) {
	 osMessagePut(stopWatchEventMsgBox, EVENT_DIS, 0);
 }


}
