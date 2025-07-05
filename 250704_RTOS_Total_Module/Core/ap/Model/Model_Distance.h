/*
 * Model_Distance.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_MODEL_MODEL_DISTANCE_H_
#define AP_MODEL_MODEL_DISTANCE_H_

#include <stdint.h>
#include "cmsis_os.h"

typedef enum {EVENT_DISTANCE} eDistanceEvent_t;

typedef struct {
	uint16_t distance;
}Distance_t;

extern osMessageQId DistanceEventMsgBox;
extern osMailQId DistanceDataMailBox;

void Model_DistanceInit();
//void Model_SetDistanceState(eDistanceState_t state);
//eDistanceState_t Model_GetDistanceState();

#endif /* AP_MODEL_MODEL_Distance_H_ */
