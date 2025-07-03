/*
 * FND.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */
#include "stm32f4xx_hal.h"

#ifndef DRIVER_FND_FND_H_
#define DRIVER_FND_FND_H_
#define FND_DP_1    0x01
#define FND_DP_10   0x02
#define FND_DP_100  0x04
#define FND_DP_1000 0x08
#define FND_DP_ON   1
#define FND_DP_OFF  0


void FND_writeData(uint16_t data);
uint16_t FND_readData();
void FND_DispDigit(uint16_t digit);
void FND_DispDataCallBack();
void FND_WriteDp(uint8_t dpData, uint8_t dpState);

#endif /* DRIVER_FND_FND_H_ */
