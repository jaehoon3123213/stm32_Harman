/*
 * Presenter_TempHumi.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_PRESENTER_PRESENTER_TEMPHUMI_H_
#define AP_PRESENTER_PRESENTER_TEMPHUMI_H_

#include "cmsis_os.h"
#include "FND.h"
#include "lcd.h"
#include "Model_TempHumi.h"
#include <stdio.h>
#include <string.h>
#include "stm32f4xx_hal.h"

void Presenter_TempHumiInit();
void Presenter_TempHumiExecute();
void Presenter_TempHumi_FND(TempHumi_t TempHumiData);
void Presenter_TempHumi_LCD(TempHumi_t TempHumiData);

#endif /* AP_PRESENTER_PRESENTER_TEMPHUMI_H_ */
