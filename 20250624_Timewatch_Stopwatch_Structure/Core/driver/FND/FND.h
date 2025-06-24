/*
 * FND.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_FND_FND_H_
#define DRIVER_FND_FND_H_
#include "stm32f4xx_hal.h"


void FND_WriteData(uint16_t data_1,uint16_t data_2,uint16_t data_3 );
uint16_t FND_ReadData(void);
void FND_Display_Data();

// 아래 함수들은 내부에서만 사용해서 굳이 헤더에 안넣어도 됨.
void FND_DispOff(int fndPos);
void FND_DispOn(int fndPos);
void FND_DispDigitWithDot(uint16_t digit, uint8_t dot);
void FND_DispOff_ALL();



#endif /* DRIVER_FND_FND_H_ */
