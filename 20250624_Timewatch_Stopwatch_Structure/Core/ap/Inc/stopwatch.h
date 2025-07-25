/*
 * stopwatch.h
 *
 *  Created on: Jun 23, 2025
 *      Author: kccistc
 */

#ifndef AP_STOPWATCH_H_
#define AP_STOPWATCH_H_
#include "stm32f4xx_hal.h"
#include "Model_Watch.h"
#include "Presenter.h"
#include "Controller.h"


void stopwatch_IncTimeCallBack(void);
void Stopwatch_Execute(void);
void Stopwatch_stop(void);
void Stopwatch_run(void);
void Stopwatch_clear(void);



#endif /* AP_STOPWATCH_H_ */

