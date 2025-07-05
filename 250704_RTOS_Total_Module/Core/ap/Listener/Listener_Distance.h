/*
 * Listener_Distance.h
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#ifndef AP_LISTENER_LISTENER_DISTANCE_H_
#define AP_LISTENER_LISTENER_DISTANCE_H_

#include <stdint.h>
#include "cmsis_os.h"
#include "Model_Distance.h"
#include "Button.h"
#include "UltraSonic.h"

void Listener_DistanceInit();
void Listener_DistanceExecute();
void Listener_Distance_CheckButton();

#endif /* AP_LISTENER_LISTENER_DISTANCE_H_ */
