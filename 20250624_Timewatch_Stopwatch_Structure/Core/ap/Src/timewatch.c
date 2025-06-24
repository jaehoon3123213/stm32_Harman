/*
 * timewatch.c
 *
 *  Created on: Jun 23, 2025
 *      Author: kccistc
 */


#include "timewatch.h"


static uint16_t dot_count = 0;

static watch_t timewatch = {0,0,0,12,TIME_WATCH,0};

uint8_t clk_dot_value=0;

void Timewatch_IncTimeCallBack()
{
    if (timewatch.msec < 999)
    {
        timewatch.msec++;
    }
    else
    {
        timewatch.msec = 0;

        if (timewatch.sec < 59)
        {
            timewatch.sec++;
        }
        else
        {
            timewatch.sec = 0;

            if (timewatch.min < 59)
            {
                timewatch.min++;
            }
            else
            {
                timewatch.min = 0;

                if (timewatch.hour < 23)
                {
                    timewatch.hour++;
                }
                else
                {
                    timewatch.hour = 0;
                }
            }
        }
    }

    if (dot_count == 499)
    {
        timewatch.dot ^= (1 << 0);  // toggle
        dot_count = 0;
    }
    else
    {
        dot_count++;
    }
}





void Timewatch_Execute() 
{

    Presenter_outData(timewatch);

//    FND_WriteData(timewatch.hour*100+timewatch.min,0x04,clk_dot_value);
}
















