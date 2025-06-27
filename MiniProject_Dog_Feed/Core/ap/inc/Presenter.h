/*
 * Presenter.h
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */

#ifndef AP_PRESENTER_H_
#define AP_PRESENTER_H_
#include "stm32f4xx_hal.h"
#include "Model_Watch.h"
#include "FND.h"
#include "lcd.h"
#include "LedBar.h"
#include "Controller.h"
#include "remain_time.h"
#include "sound.h"
#include "motor.h"

void Presenter_Init();
void Presenter_OutData(watch_t watchData);
void Presenter_Excute();



#endif /* AP_PRESENTER_H_ */