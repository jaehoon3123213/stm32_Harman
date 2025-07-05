/*
 * Model_TempHumi.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_MODEL_MODEL_TEMPHUMI_H_
#define AP_MODEL_MODEL_TEMPHUMI_H_

#include <stdint.h>
#include "cmsis_os.h"

typedef enum {EVENT_TEMPHUMI} eTempHumiEvent_t;

typedef struct {
	uint16_t TempHumi;
}TempHumi_t;

extern osMessageQId TempHumiEventMsgBox;
extern osMailQId TempHumiDataMailBox;

void Model_TempHumiInit();

#endif /* AP_MODEL_MODEL_TEMPHUMI_H_ */
