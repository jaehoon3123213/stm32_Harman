/*
 * stopwatch.c
 *
 *  Created on: Jun 23, 2025
 *      Author: kccistc
 */


#include "stopwatch.h"


typedef enum {STOP=0,RUN,CLEAR}stopwatch_state_t;



extern InputData_TypeDef ControlData;

static watch_t stopwatch={0,0,0,0,STOP_WATCH,0};
static stopwatch_state_t stopwatch_state = STOP;

uint8_t sw_dot_value=0;
static uint16_t dot_count = 0;


void stopwatch_IncTimeCallBack()
{
    if (stopwatch_state == RUN)
    {
        if (stopwatch.msec < 999)
        {
            stopwatch.msec++;
        } 
        else
        {
            stopwatch.msec = 0;

            if (stopwatch.sec < 59)
            {
                stopwatch.sec++;
            }
            else
            {
                stopwatch.sec = 0;

                if (stopwatch.min < 59)
                {
                    stopwatch.min++;
                }
                else
                {
                    stopwatch.min = 0;
                }
            }
        }
    }

    if (dot_count >= 500)
    {
        stopwatch.dot ^= 0x01; ;  // toggle
        dot_count = 0;
    }
    else
    {
        dot_count++;
    }

   

    
}





void Stopwatch_Execute()
{
    switch (stopwatch_state)
    {
    case STOP:
        Stopwatch_stop();
        
        break;

    case RUN:
        Stopwatch_run();
        
        break;

    case CLEAR:
        Stopwatch_clear();
        
        break;
    
    
    }

    Presenter_outData(stopwatch);
}


void Stopwatch_stop()
{
    if (ControlData.id == STOPWATCH_RUN_STOP)
    {
        ControlData.id = NO_CONTROL;
        stopwatch_state = RUN;
    }
    else if (ControlData.id == STOPWATCH_CLEAR)
    {
        ControlData.id = NO_CONTROL;
        stopwatch_state = CLEAR;
    }

}

void Stopwatch_run()
{
    if (ControlData.id == STOPWATCH_RUN_STOP)
    {
        ControlData.id = NO_CONTROL;
        stopwatch_state = STOP;
    }
}

void Stopwatch_clear()
{
    stopwatch_state = STOP;
    stopwatch.msec=0;
    stopwatch.sec=0;
    stopwatch.min=0;
}










