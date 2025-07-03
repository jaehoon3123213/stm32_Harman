/*
 * StopWatch.h
 *
 *  Created on: Jul 3, 2025
 *      Author: kccistc
 */

#ifndef AP_CONTROLLER_STOPWATCH_H_
#define AP_CONTROLLER_STOPWATCH_H_

#include "Model_StopWatch.h"
#include "cmsis_os.h"


void StopWatch_Init();
void StopWatch_Excute();
void StopWatch_IncTimeCallBack();

#endif /* AP_CONTROLLER_STOPWATCH_H_ */
