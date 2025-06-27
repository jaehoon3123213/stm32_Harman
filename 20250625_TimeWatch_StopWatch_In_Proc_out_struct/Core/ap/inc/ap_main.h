/*
 * ap_main.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#ifndef AP_AP_MAIN_H_
#define AP_AP_MAIN_H_

#include "stm32f4xx_hal.h"
#include "Listener.h"
#include "Presenter.h"
#include "Controller.h"
#include "tim.h"

int ap_main();
void ap_init();

#endif /* AP_AP_MAIN_H_ */
