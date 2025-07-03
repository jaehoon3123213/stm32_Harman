/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: rhoblack
 */

#include "ap_main.h"




int ap_main()
{
   HAL_TIM_Base_Start_IT(&htim2);


   while(1)
   {


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



