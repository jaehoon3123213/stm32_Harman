/*
 * FND.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */
#include <stdint.h>
#include "GPIO.h"
#include "SystemClock.h"

#ifndef DRIVER_FND_FND_H_
#define DRIVER_FND_FND_H_

void FND_init();
void FND_Display(uint32_t data);
void FND(uint32_t data);
void FND0();
void FND10();
void FND100();
void FND1000();
#endif /* DRIVER_FND_FND_H_ */
