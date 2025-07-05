/*
 * TempHumi.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_CONTROLLER_TEMPHUMI_H_
#define AP_CONTROLLER_TEMPHUMI_H_

#include <stdint.h>
#include "cmsis_os.h"
#include "Model_TempHumi.h"
#include "DHT11.h"

extern TempHumi_t TempHumiData;

void TempHumi_Init();
void TempHumi_Execute();
void TempHumi_Measurement();


#endif /* AP_CONTROLLER_TEMPHUMI_H_ */
