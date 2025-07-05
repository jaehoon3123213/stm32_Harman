/*
 * TimeWatch.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_CONTROLLER_TIMEWATCH_H_
#define AP_CONTROLLER_TIMEWATCH_H_

#include "Model_TimeWatch.h"
#include "cmsis_os.h"

extern timeWatch_t timeWatchData;

void TimeWatch_Init();
void TimeWatch_Excute();\
void timeWatch_IncTimeCallBack();


#endif /* AP_CONTROLLER_TIMEWATCH_H_ */
