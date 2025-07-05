/*
 * Distance.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_CONTROLLER_DISTANCE_H_
#define AP_CONTROLLER_DISTANCE_H_

#include <stdint.h>
#include "cmsis_os.h"
#include "Model_Distance.h"
#include "UltraSonic.h"

extern Distance_t distanceData;

void Distance_Init();
void Distance_Execute();
void Distance_Measurement();

#endif /* AP_CONTROLLER_DISTANCE_H_ */
