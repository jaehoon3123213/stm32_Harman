/*
 * LED_Bar.h
 *
 *  Created on: Jun 18, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_LED_BAR_LED_BAR_H_
#define DRIVER_LED_BAR_LED_BAR_H_

#include <stdint.h>
#include "stm32f411xe.h"
#include "GPIO.h"

void LED_Bar_Write(uint8_t data);
void LED_Bar_init();

#endif /* DRIVER_LED_BAR_LED_BAR_H_ */
