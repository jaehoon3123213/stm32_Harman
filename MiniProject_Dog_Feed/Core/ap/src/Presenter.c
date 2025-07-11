/*
 * Presenter.c
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */
#include "Presenter.h"
#include <string.h>
#include <stdio.h>
#include "usart.h"

// 수업시간에 만든 함수
static void Presenter_DispTimeWatch(watch_t watchData);
static void Presenter_DispStopWatch(watch_t watchData);
static void Presenter_DispFndTimeWatch(watch_t watchData);
static void Presenter_DispFndStopWatch(watch_t watchData);
static void Presenter_DispMonitorTimeWatch(watch_t watchData);
static void Presenter_DispMonitorStopWatch(watch_t watchData);
static watch_t dispData = {TIME_WATCH, 12, 0, 0, 0};

// 프로젝트 함수
void Presenter_DispFeedStateFND(void);
void Presenter_DispFeedStateLCD(void);
void Presenter_DispFeedStateUART(void);

extern time_TypeDef time_feed_remain;
extern ControlFlag_TypeDef controlFlag;

outputData_TypeDef feed_Output_Data = {0};
ControlFlag_TypeDef feed_Output_Flag = {0};

uint32_t temp_output = 0;
uint32_t humid_output = 0;



void Presenter_Excute()
{
   feed_Output_Data = *Controller_GetOutput();  
   feed_Output_Flag = *Controller_GetFlags();    
   temp_output = Read_Temp();
   humid_output = Read_Humid();

   Presenter_DispFeedStateFND();
   Presenter_DispFeedStateLCD();
   Presenter_DispFeedStateUART();

   if (fsm_state == FEED_MODE)
   {
      motor_Start();
      HAL_Delay(feed_Output_Data.feed_amount * 2000);
      motor_Stop();
      controlFlag.feedtimeoutFlag = 0;
   }
   else if(fsm_state == WAIT_MODE)
   {
      uint8_t scaled_remain = (feed_Output_Data.feed_remain * 255) / 15;
      LedBar_Write(0x01);
   }
   
}


void Presenter_DispFeedStateFND()
{
   switch (fsm_state)
   {
   case INPUT_MODE:
      if (input_state == PERIOD_IDLE) {
         FND_WriteData(feed_Output_Data.feed_period); // 단위: 분
      }
      else if (input_state == AMOUNT_IDLE) {
         FND_WriteData(feed_Output_Data.feed_amount); // 단위: g
      }
      break;

   case WAIT_MODE:
      FND_WriteData(time_feed_remain.min * 100 + time_feed_remain.sec);
      break;

   case FEED_MODE:
      FND_WriteData(8888); // 사료 배급 중이라는 표시
      break;
   }
}

void Presenter_DispFeedStateLCD()
{
    static char last_str0[17] = "";
    static char last_str1[17] = "";

    char temp0[32], temp1[32];
    char line0[17], line1[17];

    switch (fsm_state)
    {
    case INPUT_MODE:
        sprintf(temp0, "TIME: %2lu min", feed_Output_Data.feed_period);
        sprintf(temp1, "AMOUNT: %2lu mode", feed_Output_Data.feed_amount);
        break;

    case WAIT_MODE:
        sprintf(temp0, "T:%02d:%02dM:%1luR:%2lu", time_feed_remain.min, time_feed_remain.sec, feed_Output_Data.feed_amount, feed_Output_Data.feed_remain);
        sprintf(temp1, "T/H: %02d / %02d", temp_output, humid_output);
        break;

    case FEED_MODE:
        sprintf(temp0, "   FEED TIME!!  ");
        sprintf(temp1, "     YUMMY~~    ");
        break;
    }

    // 고정 길이로 포맷
    snprintf(line0, sizeof(line0), "%-16s", temp0);
    snprintf(line1, sizeof(line1), "%-16s", temp1);

    if (strcmp(last_str0, line0) != 0) {
        strcpy(last_str0, line0);
        LCD_writeStringXY(0, 0, line0);
    }

    if (strcmp(last_str1, line1) != 0) {
        strcpy(last_str1, line1);
        LCD_writeStringXY(1, 0, line1);
    }
}




void Presenter_DispFeedStateUART()
{
   char str[100];
   

   switch (fsm_state)
   {
   case INPUT_MODE:
      if (input_state == PERIOD_IDLE) {
         sprintf(str, "TIME: %lu \n", feed_Output_Data.feed_period);
      }
      else if (input_state == AMOUNT_IDLE) {
         sprintf(str, "AMOUNT: %lu g\n", feed_Output_Data.feed_amount);
      }
      break;

   case WAIT_MODE:
      sprintf(str, "WAITMODE: %02d:%02d\n", time_feed_remain.min, time_feed_remain.sec);
      break;

   case FEED_MODE:
      sprintf(str, "FEED_MODE\n");
      break;
   }

   HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), 1000);
}














void Presenter_Init()
{
   LCD_Init(&hi2c1);
   Sound_Init();
   motor_Init(&htim1, TIM_CHANNEL_1);
   motor_SetDuty(80);
}

void Presenter_OutData(watch_t watchData)
{
   memcpy(&dispData, &watchData, sizeof(watch_t));
}




void Presenter_DispTimeWatch(watch_t watchData)
{
   Presenter_DispFndTimeWatch(watchData);
   Presenter_DispMonitorTimeWatch(watchData);
}

void Presenter_DispStopWatch(watch_t watchData)
{
   Presenter_DispFndStopWatch(watchData);
   Presenter_DispMonitorStopWatch(watchData);
}



void Presenter_DispFndTimeWatch(watch_t watchData)
{
   FND_WriteData(watchData.hour*100 + watchData.min);

   FND_WriteDp(FND_DP_1000|FND_DP_10|FND_DP_1, FND_DP_OFF);

   if (watchData.msec < 500) {
      FND_WriteDp(FND_DP_100, FND_DP_ON);
   }
   else {
      FND_WriteDp(FND_DP_100, FND_DP_OFF);
   }
}

void Presenter_DispFndStopWatch(watch_t watchData)
{
   FND_WriteData((watchData.min % 10 * 1000) + (watchData.sec * 10) + (watchData.msec/100));

   FND_WriteDp(FND_DP_100|FND_DP_1, FND_DP_OFF);

   if (watchData.msec%100 < 50) {
      FND_WriteDp(FND_DP_10, FND_DP_ON);
   }
   else {
      FND_WriteDp(FND_DP_10, FND_DP_OFF);
   }

   if (watchData.msec < 500) {
      FND_WriteDp(FND_DP_1000, FND_DP_ON);
   }
   else {
      FND_WriteDp(FND_DP_1000, FND_DP_OFF);
   }
}

void Presenter_DispMonitorTimeWatch(watch_t watchData)
{
   char str[50];
   sprintf(str,"Time Watch : %02d:%02d:%02d.%03d\n", watchData.hour, watchData.min, watchData.sec, watchData.msec);
   HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
}

void Presenter_DispMonitorStopWatch(watch_t watchData)
{
   char str[50];
   sprintf(str,"Stop Watch : %02d:%02d:%02d.%03d\n", watchData.hour, watchData.min, watchData.sec, watchData.msec);
   HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
}

void Presenter_DispLCDStopWatch(watch_t watchData)
{
   char str[50];
   sprintf(str, "SW : %02d:%02d:%02d.%03d\n", watchData.hour, watchData.min, watchData.sec, watchData.msec);
   LCD_writeStringXY(0,  0, str);
}

void Presenter_DispLCDTimeWatch(watch_t watchData)
{
   char str[50];
   sprintf(str, "TW : %02d:%02d:%02d.%03d\n", watchData.hour, watchData.min, watchData.sec, watchData.msec);
   LCD_writeStringXY(1,  0, str);
}








