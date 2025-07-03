/*
 * Presenter.h
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#ifndef AP_PRESENTER_H_
#define AP_PRESENTER_H_

#include "Model_Watch.h"
#include "FND.h"
#include "stm32f4xx_hal.h"
#include "stopwatch.h"
#include "timewatch.h"


void Presenter_outData(Watch_t Watchdata);
void Presenter_Excute();

#endif /* AP_PRESENTER_H_ */
