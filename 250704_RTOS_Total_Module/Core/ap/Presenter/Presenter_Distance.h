/*
 * Presenter_Distance.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_PRESENTER_PRESENTER_DISTANCE_H_
#define AP_PRESENTER_PRESENTER_DISTANCE_H_

#include "cmsis_os.h"
#include "FND.h"
#include "lcd.h"
#include "Model_Distance.h"
#include <stdio.h>
#include <string.h>
#include "stm32f4xx_hal.h"

void Presenter_DistanceInit();
void Presenter_DistanceExecute();
void Presenter_Distance_FND(Distance_t distanceData);
void Presenter_Distance_LCD(Distance_t distanceData);


#endif /* AP_PRESENTER_PRESENTER_DISTANCE_H_ */
