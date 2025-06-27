/*
 * Controller.h
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */

#ifndef AP_CONTROLLER_H_
#define AP_CONTROLLER_H_

#include "stopWatch.h"
#include "timeWatch.h"
#include "Model_Watch.h"
#include "remain_time.h"

#define MAX_HEIGHT 15
 
typedef enum {INPUT_MODE,WAIT_MODE,FEED_MODE}topfsm_state_t;
typedef enum {PERIOD_IDLE,PERIOD_UP,PERIOD_DOWN,AMOUNT_IDLE,AMOUNT_UP,AMOUNT_DOWN}inputfsm_state_t;

enum {NO_CONTROL,MODE,DATA_UP,DATA_DOWN,INPUT_DONE,US_DIST,TEMP,HUMID}; // id 목록

extern inputfsm_state_t input_state;
extern topfsm_state_t fsm_state;



typedef struct {
   int id; // 어떤 데이터 인지
   uint8_t input_act;
   uint32_t US_dist;            // 초음파로 입력받은 거리값
   uint32_t temp;               // 사료통 내부 온도 (예: 25℃ → 2500)
   uint32_t humid;              // 사료통 내부 습도 (예: 55% → 5500)
}inputData_TypeDef;

typedef struct 
{
   uint32_t feed_period;     // 전체 사료 배급 주기 설정 (밀리초 단위)
   uint32_t feed_amount;     // 한 번에 배급할 사료 양 (단위: g 등) 
   uint32_t feed_remain;     // MAX_HEIGHT - US_dist
}outputData_TypeDef;


typedef struct{
   uint8_t feedEmptyFlag;
   uint8_t feedEnvironmentFlag;
   uint8_t feedtimeoutFlag;
}ControlFlag_TypeDef;


void Controller_SetInputData(inputData_TypeDef inputData);
void Controller_Excute();
void SetFeedTimeOutFlag(uint8_t flag);

outputData_TypeDef* Controller_GetOutput(void);
ControlFlag_TypeDef* Controller_GetFlags(void);

uint32_t Read_Temp();
uint32_t Read_Humid();




#endif /* AP_CONTROLLER_H_ */
