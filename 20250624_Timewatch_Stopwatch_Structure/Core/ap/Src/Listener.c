/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#include "Listener.h"
#include "usart.h"

static void Listener_CheckButton(); // 외부에서 못부르게 하겠다!
void Listener_CheckUart();

uint8_t rx_buffer =0;

void Listener_Init()
{
    Button_Init(&hBtnMode,  GPIOB, GPIO_PIN_5);
    Button_Init(&hBtnRunStop,   GPIOB, GPIO_PIN_3);
    Button_Init(&hBtnClear, GPIOA, GPIO_PIN_10);
}

void Listener_Execute()
{
    Listener_CheckButton();
    Listener_CheckUart();
}


void Listener_CheckButton()
{
	InputData_TypeDef inputData;
    if (Button_GetState(&hBtnMode) == ACT_RELEASED) // 모드 버튼
    {
        inputData.id = MODE;
        inputData.data = MODE_ACT;
        Controller_SetInputData(inputData);
    }
    else if (Button_GetState(&hBtnRunStop) == ACT_PUSHED) // 런스탑 버튼
    {
        inputData.id = STOPWATCH_RUN_STOP;
        inputData.data = MODE_ACT;
        Controller_SetInputData(inputData);
    }
    else if (Button_GetState(&hBtnClear) == ACT_PUSHED) // 클리어 버튼
    {
        inputData.id = STOPWATCH_CLEAR;
        inputData.data = MODE_ACT;
        Controller_SetInputData(inputData);
    }
    
}

void Listener_CheckUart()
{
	InputData_TypeDef inputData;
    if (HAL_UART_Receive(&huart2, &rx_buffer,1, 1) == HAL_OK)
    { if (rx_buffer == 'm')
    {
        inputData.id = MODE;
        inputData.data = MODE_ACT;
        Controller_SetInputData(inputData);
    }
    else if (rx_buffer == 'r') // 런스탑 버튼
    {
        inputData.id = STOPWATCH_RUN_STOP;
        inputData.data = MODE_ACT;
        Controller_SetInputData(inputData);
    }
    else if (rx_buffer == 's') // 클리어 버튼
    {
        inputData.id = STOPWATCH_CLEAR;
        inputData.data = MODE_ACT;
        Controller_SetInputData(inputData);
    }
    }
}
















