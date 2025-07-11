/*
 * Controller.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */
#include "Controller.h"

typedef enum {TIME_WATCH_MODE, STOP_WATCH_MODE} watch_state_t;


void Controller_Mode();
watch_state_t modstate = STOP_WATCH_MODE;

inputData_TypeDef controlData = {0,0};

void Controller_execute()
{
	Controller_Mode();
}

void Controller_Mode()
{
    switch (modstate)
    {
    case TIME_WATCH_MODE:
        if(controlData.id == MODE)
       {	controlData.id = NO_CONTROL;
            modstate = STOP_WATCH_MODE;
        }
        Timewatch_excute();   // 함수 이름 정확히 맞추기
        break;

    case STOP_WATCH_MODE:
        if(controlData.id == MODE)
        {
        	controlData.id = NO_CONTROL;
        	modstate = TIME_WATCH_MODE;
        }
        Stopwatch_excute();  // 함수 이름 정확히 맞추기
        break;
    }
}


void Controller_SetInputData(inputData_TypeDef inputData)
{
	if(inputData.id == MODE) {
		controlData.id =  MODE;
		controlData.data = 	MODE_ACT;
	}

	else if(inputData.id == STOPWATCH_RUN_STOP) {
		controlData.id =  STOPWATCH_RUN_STOP;
		controlData.data = 	MODE_ACT;
	}

	else if(inputData.id == STOPWATCH_CLEAR) {
		controlData.id =  STOPWATCH_CLEAR;
		controlData.data = 	MODE_ACT;
	}

}
