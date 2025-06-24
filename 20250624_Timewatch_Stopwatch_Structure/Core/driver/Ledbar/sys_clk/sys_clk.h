/*
 * sys_clk.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_LEDBAR_SYS_CLK_SYS_CLK_H_
#define DRIVER_LEDBAR_SYS_CLK_SYS_CLK_H_

#include <stdint.h>
#include "stm32f411xe.h"

void system_clk_Init();
void delay(int loop);

#endif /* DRIVER_LEDBAR_SYS_CLK_SYS_CLK_H_ */
