/*
 * Listener_TempHumi.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */


#include "Listener_TempHumi.h"

Button_TypeDef hbtnTempHumi;
DHT11_TypeDef dht;

void Listener_TempHumiInit()
{
	Button_Init(&hbtnTempHumi, GPIOB, GPIO_PIN_3);
	DHT11_Init(&dht, GPIOB, GPIO_PIN_6);
}

void Listener_TempHumiExecute()
{
	Listener_TempHumi_CheckButton();
}

void Listener_TempHumi_CheckButton()
{
	if (Button_GetState(&hbtnTempHumi) == ACT_RELEASED) {
		osMessagePut(TempHumiEventMsgBox, EVENT_TEMPHUMI, 0);
	}
}
