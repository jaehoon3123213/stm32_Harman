/*
 * Listener_TempHumi.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_LISTENER_LISTENER_TEMPHUMI_H_
#define AP_LISTENER_LISTENER_TEMPHUMI_H_

#include <stdint.h>
#include "cmsis_os.h"
#include "Model_TempHumi.h"
#include "Button.h"
#include "DHT11.h"

void Listener_TempHumiInit();
void Listener_TempHumiExecute();
void Listener_TempHumi_CheckButton();

#endif /* AP_LISTENER_LISTENER_TEMPHUMI_H_ */
