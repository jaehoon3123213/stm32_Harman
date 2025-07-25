/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */


#include "ap_main.h"
#include  "LCD.h"
#include "i2c.h"




uint32_t tick_count;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
		FND_DispDataCallBack();



	    TimeWatch_IncTimeCallBack();
	    StopWatch_IncTimeCallBack();
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart -> Instance == USART2)
	{
		Listener_UartCallBack();

	}

}


int ap_main()
{
    HAL_TIM_Base_Start_IT(&htim2);



    while(1)
    {

    	Listener_execute();
    	Presenter_Excute();
    	Controller_execute();
    }

    return 0;
}


void ap_init()
{
	Listener_Init();
}


