


#include "motor.h"

static TIM_HandleTypeDef *hmotorTim;
static uint32_t hmotorTimChannel;

void motor_Init(TIM_HandleTypeDef *hTim,uint32_t Channel)
{
	hmotorTim = hTim;
	hmotorTimChannel = Channel;
}


void motor_SetDuty(uint32_t Duty)
{
	if(Duty > 100) Duty = 100;
	__HAL_TIM_SET_COMPARE(hmotorTim,hmotorTimChannel,Duty);
}

void motor_Start()
{
	HAL_TIM_PWM_Start(hmotorTim, hmotorTimChannel);
}

void motor_Stop()
{
	HAL_TIM_PWM_Stop(hmotorTim, hmotorTimChannel);
}
