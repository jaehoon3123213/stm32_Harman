/*
 * Presenter.h
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#ifndef AP_PRESENTER_H_
#define AP_PRESENTER_H_

#include "stm32f4xx_hal.h"
#include "Model_Watch.h"


void Presenter_outData(watch_t watchData);
void Presenter_Execute();


#endif /* AP_PRESENTER_H_ */
