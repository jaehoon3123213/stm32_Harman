/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */


#include "Listener.h"
#include "usart.h"
#include "queue.h"



Que_TypeDef uartRxQue;

static void Listener_CheckButton();
static void Listener_CheckUart();


static uint8_t rcvData = 0;


void Listener_Init()
{
	Button_Init(&hBtnMode, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnClear, GPIOA, GPIO_PIN_10);
	HAL_UART_Receive_IT(&huart2, &rcvData,1);
	LCD_Init(&hi2c1);
	Que_Init(&uartRxQue);
}

void Listener_execute()
{

	Listener_CheckButton();
	Listener_CheckUart();

}


void Listener_CheckButton()
{
	static uint32_t prevChkTBtnTime = 0;
	uint32_t curTick = HAL_GetTick();
	if (curTick - prevChkTBtnTime <100) {
		return;
	}
	prevChkTBtnTime = curTick;

	inputData_TypeDef inputData;
	if (Button_GetState(&hBtnMode) == ACT_RELEASED){
		inputData.id = MODE;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnRunStop) == ACT_PUSHED){
		inputData.id = STOPWATCH_RUN_STOP;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnClear) == ACT_PUSHED){
		inputData.id = STOPWATCH_CLEAR;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);

	}
}

void Listener_CheckUart()
{


	if (isQueEmpty(&uartRxQue)) {
		return;
	}
	rcvData = deQue(&uartRxQue);
	inputData_TypeDef inputData;


	if (rcvData == 'm'){
		inputData.id = MODE;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);
	}
	else if (rcvData == 'r'){
		inputData.id = STOPWATCH_RUN_STOP;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);
	}
	else if (rcvData == 'c'){
		inputData.id = STOPWATCH_CLEAR;
		inputData.data = MODE_ACT;
		Controller_SetInputData(inputData);

	}
}


void Listener_UartCallBack()
{
	enQue(&uartRxQue, rcvData);
	HAL_UART_Receive_IT(&huart2, &rcvData,1); //interrupt enable
}
