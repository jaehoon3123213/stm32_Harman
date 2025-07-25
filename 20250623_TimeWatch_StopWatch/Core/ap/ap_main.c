/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */


#include "ap_main.h"


Button_Handler_t hBtnClear;
Button_Handler_t hBtnRunStop;
Button_Handler_t hBtnMode;

typedef enum {TIME_WATCH, STOP_WATCH} watch_state_t;

uint32_t tick_count;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
		tick_count ++;
		if(tick_count % 1000 < 500)
		{
	    FND_DispData_DOT(0b0100);
		}
		else
		{
		FND_DispData();
		}


	    TimeWatch_IncTimeCallBack();
	    StopWatch_IncTimeCallBack();
	}
}


int ap_main()
{
    HAL_TIM_Base_Start_IT(&htim2);
    watch_state_t modstate = STOP_WATCH;

    while(1)
    {
        switch (modstate)
        {
        case TIME_WATCH:
            if(Button_GetState(&hBtnMode) == ACT_RELEASED)
                modstate = STOP_WATCH;
            Timewatch_excute();   // 함수 이름 정확히 맞추기
            break;

        case STOP_WATCH:
            if(Button_GetState(&hBtnMode) == ACT_RELEASED)
                modstate = TIME_WATCH;
            Stopwatch_excute();  // 함수 이름 정확히 맞추기
            break;
        }
    }

    return 0;
}


void ap_init()
{
	Button_Init(&hBtnMode, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnClear, GPIOA, GPIO_PIN_10);
}


