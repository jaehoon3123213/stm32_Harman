/*
 * Controller.c
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */
#include "Controller.h"

typedef enum {TIME_WATCH, STOP_WATCH} watchMode_state_t;


static watchMode_state_t mode_state = TIME_WATCH;
InputData_TypeDef ControlData ={0};

void Controller_Execute()
{
    Controller_Mode();
}

void Controller_Mode()
{
     switch (mode_state)
        {
        case TIME_WATCH:
            if (ControlData.id == MODE)
            {
                ControlData.id = NO_CONTROL;
                mode_state = STOP_WATCH;
            }
            Timewatch_Execute();
            break;
        
        case STOP_WATCH:
            if (ControlData.id == MODE)
            {
                ControlData.id = NO_CONTROL;
                mode_state = TIME_WATCH;
            }
            Stopwatch_Execute();
            break;
        
        }
}


void Controller_SetInputData(InputData_TypeDef inputData)
{
    if (inputData.id == MODE)
    {
        ControlData.id = MODE;
        ControlData.data = MODE_ACT ;
    }
    else if (inputData.id == STOPWATCH_RUN_STOP)
    {
        ControlData.id = STOPWATCH_RUN_STOP;
        ControlData.data = STOPWATCH_ACT ;
    }
    else if (inputData.id == STOPWATCH_CLEAR)
    {
        ControlData.id = STOPWATCH_CLEAR;
        ControlData.data = STOPWATCH_ACT ;
    }
    

}































