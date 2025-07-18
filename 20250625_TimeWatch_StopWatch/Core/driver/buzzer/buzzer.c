


#include "buzzer.h"

static TIM_HandleTypeDef *hbuzzerTim;
static uint32_t hbuzzerTimChannel;

void Buzzer_Init(TIM_HandleTypeDef *hTim,uint32_t Channel)
{
	hbuzzerTim = hTim;
	hbuzzerTimChannel = Channel;
}


void Buzzer_SetFreq(uint32_t freq)
{
	if(freq < 100) freq = 100;
	else if (freq > 10000) freq = 10000;
	__HAL_TIM_SET_AUTORELOAD(hbuzzerTim,1000000/freq-1);
	__HAL_TIM_SET_COMPARE(hbuzzerTim,hbuzzerTimChannel,1000000/freq/2-1);
}

void Buzzer_Start()
{
	HAL_TIM_PWM_Start(hbuzzerTim, hbuzzerTimChannel);
}

void Buzzer_Stop()
{
	HAL_TIM_PWM_Stop(hbuzzerTim, hbuzzerTimChannel);
}
