/*
 * remain_time.h
 *
 *  Created on: Jun 27, 2025
 *      Author: kccistc
 */

#ifndef AP_INC_REMAIN_TIME_H_
#define AP_INC_REMAIN_TIME_H_

#include "stm32f4xx_hal.h"
#include "Controller.h"
#include "Presenter.h"




typedef struct 
{
    uint16_t min;
    uint16_t sec;
    uint16_t msec;

}time_TypeDef;


void RemainTime_CallBack();



#endif /* AP_INC_REMAIN_TIME_H_ */
