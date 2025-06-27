/*
 * Controller.c
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */
#include "Controller.h"
#include "sound.h"
inputData_TypeDef controlData = {0};
outputData_TypeDef controlDataOut = {0};
ControlFlag_TypeDef controlFlag = {0};

topfsm_state_t fsm_state = INPUT_MODE;
inputfsm_state_t input_state = PERIOD_IDLE;

// 내부 static 함수 
static void Control_TOP_FSM(void);
static void Control_Input_FSM(void);
static uint8_t Controller_CheckFeedRemainAlarm(void);
static uint8_t Controller_CheckEnvironmentStatus(void);

extern time_TypeDef time_feed_period;

void Controller_Excute()
{
    // 전체 FSM 동작
   Control_TOP_FSM();
    // flag 업데이트
   controlFlag.feedEmptyFlag = (Controller_CheckFeedRemainAlarm() == 1);
   controlFlag.feedEnvironmentFlag = (Controller_CheckEnvironmentStatus() == 1);
   // feed_remain 업데이트
   controlDataOut.feed_remain = MAX_HEIGHT - controlData.US_dist;
}





void Controller_SetInputData(inputData_TypeDef inputData)
{
   // 사용자 입력 데이터 (배급 주기,양)
       if (inputData.id == MODE || inputData.id == DATA_UP || inputData.id == DATA_DOWN)
       {
           controlData.id = inputData.id;
           controlData.input_act = inputData.input_act;
       }
       else if (inputData.id == INPUT_DONE)
       {
           controlData.id = INPUT_DONE;
           controlData.input_act = inputData.input_act;
       }
   // 남은양,온도 등 환경에 대한 데이터
   
      else if (inputData.id == INPUT_DONE)
       {
           controlData.id = INPUT_DONE;
           controlData.input_act = inputData.input_act;
       }
      else if (inputData.id == US_DIST) {
            controlData.US_dist = inputData.US_dist;
      }
      else if (inputData.id == TEMP) {
         controlData.temp = inputData.temp;
      }
      else if (inputData.id == HUMID) {
         controlData.humid = inputData.humid;
      }
   
   
}



// 사용자 입력값 적용함수
// feed_period 주기에 따라 배급하도록 타이머 주기 설정 함수
void Controller_UpdateFeedTimer(void)
{
    if (controlDataOut.feed_period > 0) {
        time_feed_period.min = controlDataOut.feed_period;
    }
}

// feed_amount 값에 따라 모터를 얼마나 쎄게 오래 돌릴건지 결정하는 함수
uint32_t Controller_CalcFeedMotorDuration(void)
{
    // feed_amount에 따라 PWM 또는 duration 변환
    return controlDataOut.feed_amount * 10; // 예시
}

// 환경값에 따라 경보 울리는 함수 
// feed_remain 값에 따라 남아있는 값이 적으면 경보 울리는 신호 데이터 발생 함수
uint8_t Controller_CheckFeedRemainAlarm(void)
{
    const uint32_t THRESHOLD = 3; // 예시
    return (controlDataOut.feed_remain < THRESHOLD) ? 1 : 0;
}

uint8_t Controller_CheckEnvironmentStatus(void)
{
    const uint32_t TEMP_MAX = 3500;
    const uint32_t HUMID_MAX = 8000;
    return ((controlData.temp > TEMP_MAX) || (controlData.humid > HUMID_MAX)) ? 1 : 0;
}



void Control_Input_FSM()
{
   switch (input_state)
   {
   case PERIOD_IDLE:
      if (controlData.id == MODE && controlData.input_act == 1)
      {
         input_state = AMOUNT_IDLE;
         Sound_PowerOn();
         controlData.input_act = 0;
      }
      else if (controlData.id == DATA_UP && controlData.input_act == 1)
      {
         input_state = PERIOD_UP;
         controlData.input_act =0;
      }
      else if (controlData.id == DATA_DOWN && controlData.input_act == 1)
      {
         input_state = PERIOD_DOWN;
         controlData.input_act =0;
      }

      break;

   case PERIOD_UP:
      if (controlDataOut.feed_period <= 10)
      {
         controlDataOut.feed_period++;
      }
      Sound_PowerOn();
      input_state =  PERIOD_IDLE;
      break;

   case PERIOD_DOWN:
      if (controlDataOut.feed_period != 0)
      {
         controlDataOut.feed_period--;
      }
      Sound_PowerOn();
      input_state = PERIOD_IDLE;
      break;

   case AMOUNT_IDLE:
      if (controlData.id == MODE && controlData.input_act == 1)
         {
            input_state = PERIOD_IDLE;
            Sound_PowerOn();
            controlData.input_act = 0;
         }
         else if (controlData.id == DATA_UP && controlData.input_act == 1)
         {
            input_state = AMOUNT_UP;
            Sound_PowerOn();
            controlData.input_act =0;
         }
         else if (controlData.id == DATA_DOWN && controlData.input_act == 1)
         {
            input_state = AMOUNT_DOWN;
            Sound_PowerOn();
            controlData.input_act =0;
         }

      break;

   case AMOUNT_UP:
      if (controlDataOut.feed_amount <=5)
      {
         controlDataOut.feed_amount++;
      }
      Sound_PowerOn();
       input_state = AMOUNT_IDLE;
       break;

   case AMOUNT_DOWN:
       if (controlDataOut.feed_amount != 0)
      {
         controlDataOut.feed_amount--;
      }
       Sound_PowerOn();
       input_state = AMOUNT_IDLE;
       break;


   }
}







void Control_TOP_FSM()
{
   switch (fsm_state)
   {
      case INPUT_MODE:
          if (controlData.input_act == 1 && controlData.id == INPUT_DONE) {
              fsm_state = WAIT_MODE;
              Sound_ModeStart();
            Controller_UpdateFeedTimer();
              controlData.input_act = 0;
          }
          else {
              Control_Input_FSM(); // 항상 입력 FSM은 동작
          }
       break;


      case WAIT_MODE:
          if (controlFlag.feedtimeoutFlag == 1) {
              fsm_state = FEED_MODE;
              Sound_ModeStart();
          }
         if (controlData.input_act == 1 && controlData.id == INPUT_DONE) {
              fsm_state = INPUT_MODE;
              controlData.input_act = 0;
          }
       break;

      case FEED_MODE:
          if (controlFlag.feedtimeoutFlag == 0) {
              fsm_state = WAIT_MODE;
          }
          break;

   }

}

void SetFeedTimeOutFlag(uint8_t flag) // remain_time.c에서 호출
{
    controlFlag.feedtimeoutFlag = flag;
}


const char *FSM_StateToString(topfsm_state_t state)
{
    switch(state)
    {
        case INPUT_MODE: return "INPUT";
        case WAIT_MODE: return "WAIT";
        case FEED_MODE: return "FEED";
        default: return "UNKNOWN";
    }
}


outputData_TypeDef* Controller_GetOutput(void) {
    return &controlDataOut;
}


ControlFlag_TypeDef* Controller_GetFlags(void)
{
    return &controlFlag;
}


uint32_t Read_Temp()
{
   return controlData.temp;
}

uint32_t Read_Humid()
{
   return controlData.humid;
}




















