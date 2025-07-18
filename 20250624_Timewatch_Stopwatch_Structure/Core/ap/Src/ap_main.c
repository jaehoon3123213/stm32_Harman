#include "ap_main.h"
#include "usart.h"


void ap_init()
{
    //입력부 초기세팅
    Listener_Init();
    
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        FND_Display_Data();
        Timewatch_IncTimeCallBack();
        stopwatch_IncTimeCallBack();
    }
    
}





int ap_main()
{

    HAL_TIM_Base_Start_IT(&htim2);


    while (1)
    {
       Listener_Execute();
       Controller_Execute();
       Presenter_Execute();
            
    }
    
    return 0;
   
}









