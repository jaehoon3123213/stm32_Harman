#include "Button.h"

enum {PUSHED=0, RELEASED};


void Button_Init(Button_Handler_t *hbtn,GPIO_TypeDef *GPIOx, uint32_t pinNum )
{
    hbtn->GPIOx = GPIOx;
    hbtn->pinNum = pinNum;
    hbtn->prevState = RELEASED;
    GPIO_Init(hbtn->GPIOx, hbtn->pinNum, INPUT);
}


button_state_t Button_GetState(Button_Handler_t *hbtn){

    uint32_t curState;
    curState = GPIO_ReadPin(hbtn->GPIOx, hbtn->pinNum); // normal state is 1

    if ((hbtn->prevState == RELEASED) && (curState == PUSHED)) // 버튼 눌렀을 때
    {
        delay(2); // debounce
        hbtn->prevState = PUSHED;
        return ACT_PUSHED;
    }
    else if ((hbtn->prevState == PUSHED) && (curState == RELEASED)) // 버튼 땠을 때
    {
        delay(2); // debounce
        hbtn->prevState = RELEASED;
        return ACT_RELEASED;
    }

    return NO_ACT;

}
