

#include "FND.h"

uint16_t fndDispNum = 0; //fnd Display Num 전역변수에 스태틱을 붙이면 외부에서 접근못함
void FND_DispOff(int fndPos);
void FND_DispOn(int fndPos);
void FND_DispOffAll();


//write fndDispNum
void FND_writeData(uint16_t data)
{
	fndDispNum = data;
}
//read fndDispNum
uint16_t FND_readData()
{
	return fndDispNum;
}
//display fnd DispNum

enum{DIGIT_1 = 0,DIGIT_10,DIGIT_100,DIGIT_1000};

typedef struct {
	GPIO_TypeDef *GPIOx;
	uint32_t pinNum;
}FND_TypeDef;




FND_TypeDef fndDigitCom[4] = {{GPIOA,GPIO_PIN_12},{GPIOC,GPIO_PIN_5},{GPIOC,GPIO_PIN_6},{GPIOC,GPIO_PIN_8}};

FND_TypeDef fndPin[8] =
{{GPIOA,GPIO_PIN_11},
{GPIOB,GPIO_PIN_12},
{GPIOB,GPIO_PIN_2},
{GPIOB,GPIO_PIN_1},
{GPIOB,GPIO_PIN_15},
{GPIOB,GPIO_PIN_14},
{GPIOB,GPIO_PIN_13},
{GPIOC,GPIO_PIN_4}
};

void FND_DispData()
{
	static int digitPos = 0;

	digitPos = (digitPos + 1) % 4;
	switch(digitPos)
	{
	case DIGIT_1:
		FND_DispOffAll();
		FND_DispDigit(fndDispNum%10);
		FND_DispOn(digitPos);
	break;
	case DIGIT_10:
		FND_DispOffAll();
		FND_DispDigit(fndDispNum/10 % 10);
		FND_DispOn(digitPos);
	break;
	case DIGIT_100:
		FND_DispOffAll();
		FND_DispDigit(fndDispNum/100%10);
		FND_DispOn(digitPos);
	break;
	case DIGIT_1000:
		FND_DispOffAll();
		FND_DispDigit(fndDispNum/1000%10);
		FND_DispOn(digitPos);
	break;
	}
	//인터럽트가 발생하면 한 자리씩 출력한다.

}

void FND_DispData_DOT(uint32_t digit)
{
	static int digitPos = 0;

	digitPos = (digitPos + 1) % 4;
	switch(digitPos)
	{
	case DIGIT_1:
		FND_DispOffAll();
		if(digit & (1<<0)){
			FND_DispDigit_Dot(fndDispNum%10);
		}
		else {
		FND_DispDigit(fndDispNum%10);
		}
		FND_DispOn(digitPos);
	break;
	case DIGIT_10:
		FND_DispOffAll();
		if(digit & (1<<1)){
			FND_DispDigit_Dot(fndDispNum/10 % 10);
		}
		else {
		FND_DispDigit(fndDispNum/10 % 10);
		}
		FND_DispOn(digitPos);
	break;
	case DIGIT_100:
		FND_DispOffAll();
		if(digit & (1<<2)){
			FND_DispDigit_Dot(fndDispNum/100%10);
		}
		else {
		FND_DispDigit(fndDispNum/100%10);
		}
		FND_DispOn(digitPos);
	break;
	case DIGIT_1000:
		FND_DispOffAll();
		if(digit & (1<<3)){
			FND_DispDigit_Dot(fndDispNum/1000%10);
		}
		else {
		FND_DispDigit(fndDispNum/1000%10);
		}
		FND_DispOn(digitPos);
	break;
	}
	//인터럽트가 발생하면 한 자리씩 출력한다.

}





void FND_DispOff(int fndPos)
{
	HAL_GPIO_WritePin(fndDigitCom[fndPos].GPIOx, fndDigitCom[fndPos].pinNum, SET);
}

void FND_DispOn(int fndPos)
{
	HAL_GPIO_WritePin(fndDigitCom[fndPos].GPIOx, fndDigitCom[fndPos].pinNum, RESET);
}


void FND_DispOffAll()
{
	for(int i = 0; i<4; i++)
	{
		HAL_GPIO_WritePin(fndDigitCom[i].GPIOx, fndDigitCom[i].pinNum, SET);
	}

}

void FND_DispDigit(uint16_t digit)
{
	 const uint8_t segFont[10] = {
	         0x3F,
	         0x06,
	         0x5B,
	         0x4F,
	         0x66,
	         0x6D,
	         0x7D,
	         0x07,
	         0x7F,
	         0x6F
	   };

	for(int i =0; i<8; i++)
	{
		if(!(segFont[digit] &(1<<i))){
		HAL_GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, RESET);
		}
	 else {
		 HAL_GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, SET);
	   }
	}

}




void FND_DispDigit_Dot(uint16_t digit)
{


	 const uint8_t segFont[10] = {
			    0xBF, // 0  (0x3F | 0x80)
			    0x86, // 1  (0x06 | 0x80)
			    0xDB, // 2  (0x5B | 0x80)
			    0xCF, // 3  (0x4F | 0x80)
			    0xE6, // 4  (0x66 | 0x80)
			    0xED, // 5  (0x6D | 0x80)
			    0xFD, // 6  (0x7D | 0x80)
			    0x87, // 7  (0x07 | 0x80)
			    0xFF, // 8  (0x7F | 0x80)
			    0xEF  // 9  (0x6F | 0x80)
	   };


	for(int i =0; i<8; i++)
	{
		if(!(segFont[digit] &(1<<i))){
			HAL_GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, RESET);
		}
	 else {
		 HAL_GPIO_WritePin(fndPin[i].GPIOx, fndPin[i].pinNum, SET);
	   }
	}

}

















