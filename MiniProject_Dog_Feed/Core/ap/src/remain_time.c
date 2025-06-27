/*
 * remain_time.c
 *
 *  Created on: Jun 27, 2025
 *      Author: kccistc
 */

#include "remain_time.h"

time_TypeDef time_feed_period = {0};   // 설정된 전체 주기
time_TypeDef time_feed_elapsed = {0};  // 현재까지 경과한 시간
time_TypeDef time_feed_remain = {0};   // 남은 시간 (주기 - 경과)


// 내부 함수 
static void Calculate_Elapsed_Time(void);
static void Compare_Time(void);
static uint64_t TimeToSec(time_TypeDef t);



void RemainTime_CallBack()
{
	if (fsm_state == WAIT_MODE) {
		Calculate_Elapsed_Time();
        Compare_Time();

        int total_period_sec  = TimeToSec(time_feed_period);
        int total_elapsed_sec = TimeToSec(time_feed_elapsed);
        int remain_sec = total_period_sec - total_elapsed_sec;
        if (remain_sec < 0) remain_sec = 0;


        time_feed_remain.min = remain_sec / 60;
        time_feed_remain.sec = remain_sec % 60;

    }
    else if (fsm_state == FEED_MODE || fsm_state == INPUT_MODE)
    {
        time_feed_elapsed = (time_TypeDef){0,0,0};
        // feed_time_out = 0; ← 이건 Controller 또는 Output에서 클리어하자
    }
    
}

void Calculate_Elapsed_Time()
{
    if (time_feed_elapsed.msec == 1000 - 1) {
        time_feed_elapsed.msec = 0;

        if (time_feed_elapsed.sec == 60 - 1) {
            time_feed_elapsed.sec = 0;

            if (time_feed_elapsed.min == 60 - 1) {
                time_feed_elapsed.min = 0; 
            } else {
                time_feed_elapsed.min++;
            }

        } else {
            time_feed_elapsed.sec++;
        }

    } else {
        time_feed_elapsed.msec++;
    }
}


uint64_t TimeToSec(time_TypeDef t)
{
    return ((uint64_t)t.min * 60) + t.sec;
}


void Compare_Time()
{
    uint8_t timeout = (TimeToSec(time_feed_elapsed) >= TimeToSec(time_feed_period)) ? 1 : 0;
    SetFeedTimeOutFlag(timeout);  // 내부 상태가 아닌 Controller 상태에 전달
}









































