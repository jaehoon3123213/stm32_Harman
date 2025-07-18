/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */


#include "ap_main.h"


Button_Handler_t hBtnLeft;
Button_Handler_t hBtnRight;
Button_Handler_t hBtnOnOff;
Button_Handler_t hBtnmode;



enum {OFF,LEFT, RIGHT};

enum{STOPWATCH,CLOCK};

typedef struct
{
	uint32_t min;
	uint32_t second;
	uint32_t msecond;
} stopwatch_t;


typedef struct
{
	uint32_t min;
	uint32_t hour;
} clock_t;




void STOPWATCH_COUNT(uint32_t count,stopwatch_t* stopwatchx);
void CLOCK_COUNT(uint32_t count,clock_t* clockx);

uint32_t mode_dot = 0;
int ap_main()

{
	uint8_t data = 1;
	uint32_t count = 0;
	uint32_t countClock = 0;
	uint32_t prevCounterTime = 0;
	uint32_t prevCounterTimeClock = 0;
	uint32_t mode_state = 0;
	uint32_t stopwatch_state = 0;
	uint32_t clock_state = 0;









	stopwatch_t stopwatch;
	clock_t clock;

	while(1)
	{


		switch (mode_state)
		{
	      case STOPWATCH:
	    	  mode_dot = 0b0101;
	         if (Button_GetState(&hBtnmode) == ACT_RELEASED) mode_state = CLOCK;
	         FND_writeData(stopwatch.min*1000+stopwatch.second*10+stopwatch.msecond);

			if(getTick()- prevCounterTimeClock >= 1000){
					prevCounterTimeClock = getTick();
				CLOCK_COUNT(countClock,&clock);
				countClock ++;
	 			}

	 		switch (stopwatch_state)
	 		{
	 	          case LEFT:
	 	         if (Button_GetState(&hBtnRight) == ACT_RELEASED) stopwatch_state = RIGHT;
	 	         else if (Button_GetState(&hBtnOnOff) == ACT_RELEASED) stopwatch_state = OFF;
	 	         data = 0;

	 	      break;

	 	      case RIGHT:
	 	         if (Button_GetState(&hBtnLeft) == ACT_RELEASED) stopwatch_state = LEFT;
	 	         else if (Button_GetState(&hBtnOnOff) == ACT_RELEASED) stopwatch_state = OFF;


				if(getTick()- prevCounterTime >= 100){
					prevCounterTime = getTick();
				STOPWATCH_COUNT(count,&stopwatch);
				count ++;
	 			}

	 	      break;

	 	      case OFF:
	 	         if (Button_GetState(&hBtnLeft) == ACT_RELEASED) stopwatch_state = LEFT;
	 	         else if (Button_GetState(&hBtnRight) == ACT_RELEASED) stopwatch_state = RIGHT;
	 	         	 count = 0;
	 	         	STOPWATCH_COUNT(count,&stopwatch);


	 	      break;

	 	      }


	      break;

	      case CLOCK:
	    	  mode_dot = 0b0100;
	         if (Button_GetState(&hBtnmode) == ACT_RELEASED) mode_state = STOPWATCH;

				if(getTick()- prevCounterTimeClock >= 1000){
					prevCounterTimeClock = getTick();
				CLOCK_COUNT(countClock,&clock);
				countClock ++;
				FND_writeData(clock.hour*100 + clock.min);
	 			}


			if (stopwatch_state == RIGHT)
			{
				if(getTick()- prevCounterTime >= 100){
					prevCounterTime = getTick();
				STOPWATCH_COUNT(count,&stopwatch);
				count ++;
	 			}
			}


		 	      break;

		}
	      }


	return 0;
	}



void STOPWATCH_COUNT(uint32_t count,stopwatch_t* stopwatchx)
{
	stopwatchx-> msecond = count % 10;
	stopwatchx -> second = count / 10 % 60;
	stopwatchx -> min = count / 600;
}


void CLOCK_COUNT(uint32_t count,clock_t* clockx)
{
	clockx -> min = count / 60 % 60;
	clockx -> hour = count / 3600;
}



void TIM2_IRQHandler(void)
{
	static uint32_t tick_count;
	incTick();
	tick_count ++;

	if(tick_count % 1000 < 500)
	{
    FND_DispData_DOT(mode_dot);
	}
	else
	{
		FND_DispData();
	}

	TIM_ClearUIF(TIM2);
}

void ap_init()
{
	SysyemClock_init();
	LED_Bar_init();
	Button_Init(&hBtnRight, GPIOB, 3);
	Button_Init(&hBtnmode, GPIOC, 13);
	Button_Init(&hBtnLeft, GPIOB, 5);
	Button_Init(&hBtnOnOff, GPIOA, 10);
	FND_init();
	TIM_Init(TIM2, 16-1, 1000-1);
	TIM_CntStart(TIM2);
	TIM_UIEnable(TIM2);
	NVIC_EnableIRQ(TIM2_IRQn);

}


