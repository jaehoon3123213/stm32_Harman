/*
 * FND.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#include "FND.h"


enum {DIGIT_1000=0, DIGIT_100, DIGIT_10, DIGIT_1};

typedef struct {
    GPIO_TypeDef *GPIOx;
    uint32_t pinNum;
}FND_TypeDef;

FND_TypeDef fndPin[8] =  {  {GPIOA,GPIO_PIN_11}, //a
                            {GPIOB,GPIO_PIN_12}, //b
                            {GPIOB,GPIO_PIN_2}, // c
                            {GPIOB,GPIO_PIN_1}, // d
                            {GPIOB,GPIO_PIN_15}, // e
                            {GPIOB,GPIO_PIN_14}, // f
                            {GPIOB,GPIO_PIN_13}, // g
                            {GPIOC,GPIO_PIN_4}   // dp 
                        };

FND_TypeDef fndDigitCom[4] = {
                           {GPIOC,GPIO_PIN_8}, // digit_1
                           {GPIOC,GPIO_PIN_6}, // digit_10
                           {GPIOC,GPIO_PIN_5}, // digit_100
                           {GPIOA,GPIO_PIN_12} // digit_1000
};



static uint16_t fndDisNum = 0; // fnd main data
static uint8_t dot_on_location  = 0; // dot 켤 위치 지정 (4비트로 지정)
static uint8_t dot = 0; // dot 켤지말지 선택 1,0



// Write fndDisNum
void FND_WriteData(uint16_t data_1,uint16_t data_2,uint16_t data_3 )
{   
    fndDisNum = data_1;
    dot_on_location = data_2;
    dot = data_3;
}

// Read fndDisNum
uint16_t FND_ReadData()
{
    return fndDisNum;
}

// display fndDisNum
void FND_Display_Data()
{
    static int digitPos = 0;

    
    // interrupt가 발생하면 한자리 씩 출력
    digitPos = (digitPos+1) % 4;

    switch (digitPos)
    {
        case DIGIT_1:
            FND_DispOff_ALL();
            dot_on_location & (1<<0) ? FND_DispDigitWithDot(fndDisNum%10,dot) : FND_DispDigitWithDot(fndDisNum%10,0) ;
            FND_DispOn(digitPos);
            break;
        
        case DIGIT_10:
            FND_DispOff_ALL();
            dot_on_location & (1<<1) ?  FND_DispDigitWithDot(fndDisNum/10%10,dot) : FND_DispDigitWithDot(fndDisNum/10%10,0);
            FND_DispOn(digitPos);
        break;

        case DIGIT_100:
            FND_DispOff_ALL();
            dot_on_location & (1<<2) ? FND_DispDigitWithDot(fndDisNum/100%10,dot) : FND_DispDigitWithDot(fndDisNum/100%10,0);
            FND_DispOn(digitPos);
        break;

        case DIGIT_1000:
            FND_DispOff_ALL();
            dot_on_location & (1<<3) ? FND_DispDigitWithDot(fndDisNum/1000%10,dot) : FND_DispDigitWithDot(fndDisNum/1000%10,0);
            FND_DispOn(digitPos);
        break;  

    }

    

}

void FND_DispOff_ALL(){
    // GPIO_Write(GPIOx, Pin, SET);
    for (int i = 0; i < 4; i++)
    {
        HAL_GPIO_WritePin(fndDigitCom[i].GPIOx, fndDigitCom[i].pinNum, SET);
    }
    
}


void FND_DispOff(int fndPos){
    // GPIO_Write(GPIOx, Pin, SET);

    HAL_GPIO_WritePin(fndDigitCom[fndPos].GPIOx, fndDigitCom[fndPos].pinNum, SET);
    
}


void FND_DispOn(int fndPos){
    // GPIO_Write(GPIOx, Pin, RESET);
    HAL_GPIO_WritePin(fndDigitCom[fndPos].GPIOx, fndDigitCom[fndPos].pinNum, RESET);
}



void FND_DispDigitWithDot(uint16_t digit, uint8_t dot)
{
    const uint8_t seg_pattern[10] = {
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4
        0x6D, // 5
        0x7D, // 6
        0x07, // 7
        0x7F, // 8
        0x6F  // 9
    };

    uint8_t pattern = seg_pattern[digit];

    if (dot) {
        pattern |= (1 << 7); // DP 위치 비트 활성화 (MSB)
    }

    for (int i = 0; i < 8; i++) {
        if (!(pattern & (1 << i))) {
            HAL_GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, RESET);
        } else {
            HAL_GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, SET);
        }
    }
}


