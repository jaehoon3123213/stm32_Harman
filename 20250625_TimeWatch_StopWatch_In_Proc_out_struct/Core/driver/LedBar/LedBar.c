/*
 * LED_Bar.c
 *
 *  Created on: Jun 18, 2025
 *      Author: kccistc
 */

#include "LEDBar.h"

typedef struct{
   GPIO_TypeDef *GPIOx;
   uint32_t pinNum;
} LED_Bar_TypeDef;

LED_Bar_TypeDef ledBar[8] = {
      {GPIOA, GPIO_PIN_0},
      {GPIOA, GPIO_PIN_1},
      {GPIOA, GPIO_PIN_4},
      {GPIOB, GPIO_PIN_0},
      {GPIOC, GPIO_PIN_1},
      {GPIOC, GPIO_PIN_0},
      {GPIOC, GPIO_PIN_2},
      {GPIOC, GPIO_PIN_3}
};



void LED_Bar_Write(uint8_t data)
{
   for (int i=0; i<8; i++){
      if ((data&(1<<i))==0){
         HAL_GPIO_WritePin(ledBar[i].GPIOx, ledBar[i].pinNum, RESET);
      }
      else {
         HAL_GPIO_WritePin(ledBar[i].GPIOx, ledBar[i].pinNum, SET);
      }
   }
}
