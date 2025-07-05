/*
 * UltraSonic.h
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_ULTRASONIC_ULTRASONIC_H_
#define DRIVER_ULTRASONIC_ULTRASONIC_H_

#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "tim.h"

typedef struct {
   GPIO_TypeDef *Trig_GPIOx;
   uint16_t Trig_pinNum;
   GPIO_TypeDef *Echo_GPIOx;
   uint16_t Echo_pinNum;
} UltraSonic_TypeDef;

int UltraSonic();


void delay_us(uint16_t us);
void UltraSonic_Init( GPIO_TypeDef *Trig_GPIOx, uint16_t Trig_pinNum,  GPIO_TypeDef *Echo_GPIOx, uint16_t Echo_pinNum);

//uint32_t UltraSonic_Wait_Echo(UltraSonic_TypeDef *hultra);
//uint16_t UltraSonic_Calculate(UltraSonic_TypeDef *hultra);


#endif /* DRIVER_ULTRASONIC_ULTRASONIC_H_ */
