/*
 * sound.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#include "sound.h"

void Sound_Init()
{
 Buzzer_Init(&htim3, TIM_CHANNEL_1);
}

void Sound_PowerOn()
{
	Buzzer_SetFreq(1047);
	Buzzer_Start();
	HAL_Delay(100);
	Buzzer_SetFreq(1319);
	HAL_Delay(100);
	Buzzer_SetFreq(1568);
	HAL_Delay(100);
	Buzzer_SetFreq(2039);
	HAL_Delay(100);
	Buzzer_Stop();
}

void Sound_PowerOff()
{

}

void Sound_ChangeMode()
{

}


void Sound_Alarm()
{

}
