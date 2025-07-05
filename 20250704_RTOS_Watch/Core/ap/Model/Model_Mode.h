/*
 * Model_Mode.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_MODEL_MODEL_MODE_H_
#define AP_MODEL_MODEL_MODE_H_

#include <stdint.h>
#include "cmsis_os.h"

extern osMessageQId modeEventMsgBox;

typedef enum {S_TIME_WATCH_MODE, S_STOP_WATCH_MODE, S_DISTANCE_MODE} eModestate_t;

typedef enum {EVENT_MODE} eModeEvent_t;

void Model_modeInit();
void Model_SetModeState(eModestate_t state);

eModestate_t Model_GetModeState();


#endif /* AP_MODEL_MODEL_MODE_H_ */
