/*
 * Model_Watch.h
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#ifndef AP_INC_MODEL_WATCH_H_
#define AP_INC_MODEL_WATCH_H_

#include "stm32f4xx_hal.h"

enum {TIME_WATCH,STOP_WATCH};

typedef struct 
{
    uint16_t msec;
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t id;
    uint8_t dot;

}watch_t;




#endif /* AP_INC_MODEL_WATCH_H_ */
