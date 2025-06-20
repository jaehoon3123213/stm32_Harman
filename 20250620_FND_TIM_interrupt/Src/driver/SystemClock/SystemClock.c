/*
 * SystemClock.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */


#include "SystemClock.h"




void SysyemClock_init()
{
	RCC -> AHB1ENR |= (1U << 0);//  RCC_AHB1ENR 해당위치의 비트만 1로 만들겠다
	RCC -> AHB1ENR |= (1U << 1);//  RCC_AHB1ENR 해당위치의 비트만 1로 만들겠다
	RCC -> AHB1ENR |= (1U << 2);//  RCC_AHB1ENR 해당위치의 비트만 1로 만들겠다
	RCC -> APB1ENR |= (1U << 0);
	RCC -> APB1ENR |= RCC_APB1ENR_TIM5EN;
};


void delay(int loop)
{
	for (int j=0; j<loop; j++){
	for(int i = 0; i<1000; i++){}
	}
}
