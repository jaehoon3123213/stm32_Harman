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

      TimeWatch_IncTimeCallBack();
      StopWatch_IncTimeCallBack();
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

   uint8_t humidity = 0, temperature = 0;
   while(1)
   {


      DHT11_ReadData(&humidity, &temperature);
      HAL_Delay(2000);  // DHT11 최소 주기 보장
      //      Listener_Excute();
      //      Controller_Excute();
      //      Presenter_Excute();
   }

   return 0;
}

void ap_init()
{
   MX_TIM4_Init();
   Listener_Init();
   Presenter_Init();
   Sound_Init();
   Sound_PowerOn();

}



