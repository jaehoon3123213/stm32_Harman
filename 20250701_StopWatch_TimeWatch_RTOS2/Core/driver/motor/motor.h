/*
 * motor.h
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_MOTOR_MOTOR_H_
#define DRIVER_MOTOR_MOTOR_H_

#include "stm32f4xx_hal.h"
#include "tim.h"

void motor_Init(TIM_HandleTypeDef *hTim,uint32_t Channel);
void motor_SetDuty(uint32_t Duty);
void motor_Start();
void motor_Stop();

#endif /* DRIVER_MOTOR_MOTOR_H_ */
