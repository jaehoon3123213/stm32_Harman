/*
 * GPIO.c
 *
 *  Created on: Jun 18, 2025
 *      Author: kccistc
 */
#include "GPIO.h"
#include <stdint.h>





void GPIO_Init(GPIO_TypeDef *GPIOx, uint32_t pinNum, pinMode pin_Mode)
{
	if(pin_Mode == OUTPUT)
	{
		GPIOx -> MODER  |=  (0x01U << (pinNum*2));
		GPIOx -> MODER  &= ~(0x02U << (pinNum*2));
	}
	else {
		GPIOx -> MODER  &= ~(0x03U << (pinNum*2));
	}
}



void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t pinNum, pinState pin_State)
{
	if(pin_State == PIN_SET) {
	GPIOx -> ODR |= (1U<<pinNum);
	}
	else {
		GPIOx-> ODR &= ~(1U<<pinNum);
	}
}




uint32_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t pinNum)
{
return ((GPIOx->IDR & (1<<pinNum)) ? 1 : 0); // 1bit만 내보내기 위한

}



void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t pinNum)
{
    (GPIOx->ODR ^= 1<<pinNum) ; // 1bit만 내보내기 위한
}
