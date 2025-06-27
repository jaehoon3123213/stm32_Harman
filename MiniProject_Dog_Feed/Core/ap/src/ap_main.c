/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: rhoblack
 */

#include "ap_main.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2) {
		FND_DispDataCallBack();
		// 남은 시간 계산하기
		RemainTime_CallBack();

	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART2) {
		Listener_UartCallBack();
	}
}


int ap_main()
{
	HAL_TIM_Base_Start_IT(&htim2);

	HAL_TIM_Base_Start(&htim4);
	while(1)
	{
		Listener_Excute();
		Controller_Excute();
		Presenter_Excute();
	}

	return 0;
}

void ap_init()
{
	Listener_Init();
	Presenter_Init();
	Sound_Init();
	motor_Init(&htim1, TIM_CHANNEL_1);
	motor_SetDuty(80);

}



