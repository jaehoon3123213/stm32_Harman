/*
 * Model.h
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */

#ifndef AP_MODEL_MODEL_STOPWATCH_H_
#define AP_MODEL_MODEL_STOPWATCH_H_
#include <stdint.h>
#include "cmsis_os.h"



typedef enum {EVENT_DISTANCE} distanceState_t;

extern osMessageQId DistanceEventMsgBox;
extern osMessageQId DistanceDataMsgBox;


void Model_DistanceInit();


#endif /* AP_MODEL_MODEL_STOPWATCH_H_ */
