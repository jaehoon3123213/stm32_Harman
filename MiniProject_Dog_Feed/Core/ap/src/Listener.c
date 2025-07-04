/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */


#include "Listener.h"
#include "usart.h"
#include "dht11.h"
#include "UltraSonic.h"

static void Listener_CheckButton();
static void Listener_CheckUart();

static uint8_t rcvData = 0;
static Que_TypeDef uartRxQue;



void Listener_Init()
{
	Button_Init(&hBtnMode, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnUp, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnDown, GPIOA, GPIO_PIN_10);
	Button_Init(&hBtnInputDone, GPIOC, GPIO_PIN_13);
	UltraSonic_Init (GPIOA, GPIO_PIN_9, GPIOC, GPIO_PIN_7);

	Que_Init(&uartRxQue);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1); // uart recv interrupt enable
}

void Listener_tempData();

void Listener_Excute()
{
	Listener_CheckButton();
	Listener_CheckUart();
	Listener_tempData();
}

void Listener_CheckButton()
{
	inputData_TypeDef inputData;
	static uint32_t prevChkBtnTime = 0;
	uint32_t curTick = HAL_GetTick();
	if (curTick - prevChkBtnTime < 100) {
		return;
	}
	prevChkBtnTime = curTick;

	if (Button_GetState(&hBtnMode) == ACT_RELEASED) {
		inputData.id = MODE;
		inputData.input_act = 1;
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnUp) == ACT_PUSHED) {
		inputData.id = DATA_UP;
		inputData.input_act = 1;
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnDown) == ACT_PUSHED) {
		inputData.id = DATA_DOWN;
		inputData.input_act = 1;
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnInputDone) == ACT_PUSHED) {
		inputData.id = INPUT_DONE;
		inputData.input_act = 1;
		Controller_SetInputData(inputData);
	}

}

void Listener_CheckUart()
{
    inputData_TypeDef inputData;
    if (isQueEmpty(&uartRxQue)) {
        return;
    }

    int uartRxData = deQue(&uartRxQue);

    switch (uartRxData) {
        case 'm':
            inputData.id = MODE;
            inputData.input_act = 1;
            break;

        case 'u':
            inputData.id = DATA_UP;
            inputData.input_act = 1;
            break;

        case 'd':
            inputData.id = DATA_DOWN;
            inputData.input_act = 1;
            break;

        case 's':
            inputData.id = INPUT_DONE;
            inputData.input_act = 1;
            break;

        default:
            return;  // 정의되지 않은 입력은 무시
    }

    Controller_SetInputData(inputData);
}


void Listener_tempData()
{
   static uint8_t humidity;
   static uint8_t first_flag = 0;
   static uint8_t temperature;
   static uint32_t prevChktempTime = 0;
   static uint32_t prevChkhumiTime = 0;
   static inputData_TypeDef inputData;
   static uint32_t distance;
   uint32_t curTick = HAL_GetTick();
   if ((curTick - prevChkhumiTime > 5000) || !first_flag) {
       distance = UltraSonic_GetDistance();
       inputData.id = US_DIST;
       inputData.US_dist = distance;
       prevChkhumiTime = curTick;
       Controller_SetInputData(inputData);
   }

   if ((curTick - prevChktempTime < 60000)&& first_flag) {
      return;
   }
   prevChktempTime = curTick;
   first_flag = 1;
    DHT11_ReadData(&humidity, &temperature);
    inputData.id = TEMP;
    inputData.temp = temperature;
    Controller_SetInputData(inputData);
    inputData.id = HUMID;
    inputData.humid = humidity;
    Controller_SetInputData(inputData);
}

void Listener_UartCallBack()
{
	enQue(&uartRxQue, rcvData);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1); // interrupt enable
}



















