/*
 * sys_clk.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */


#include "sys_clk.h"

void system_clk_Init()
{
    RCC->AHB1ENR |= (0x07U << 0);// RCC_AHB1ENR , clk enable
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

}

void delay(int loop){

    for (int j = 0; j < loop; j++)
    {
        for (int i = 0; i < 1000; i++){}
    }
    
}
