
#include "FND.h"


typedef struct{
   GPIO_TypeDef *GPIOx;
   uint32_t pinNum;
} FND_TypeDef;


FND_TypeDef FND_Bar[7] = {
      {GPIOA, 11},
      {GPIOB, 12},
      {GPIOB, 2},
      {GPIOB, 1},
      {GPIOB, 15},
      {GPIOB, 14},
      {GPIOB, 13},
};

void FND_init()
{
 	GPIO_Init(GPIOC, 8, OUTPUT); // D1
 	GPIO_Init(GPIOC, 6, OUTPUT); // D2
 	GPIO_Init(GPIOC, 5, OUTPUT); // D3
 	GPIO_Init(GPIOA, 12, OUTPUT); // D4
 	GPIO_Init(GPIOA, 11, OUTPUT); // A
 	GPIO_Init(GPIOB, 12, OUTPUT); // B
 	GPIO_Init(GPIOB, 2, OUTPUT); // C
 	GPIO_Init(GPIOB, 1, OUTPUT); // D
 	GPIO_Init(GPIOB, 15, OUTPUT); // E
 	GPIO_Init(GPIOB, 14, OUTPUT); // F
 	GPIO_Init(GPIOB, 13, OUTPUT); // G
 	GPIO_Init(GPIOC, 4, OUTPUT); // DP
}

void FND(uint32_t data)
{
	static uint32_t digit = 0;
	uint32_t data1 = data % 10;
	uint32_t data10 = data/10 % 10;
	uint32_t data100 = data/100 % 10;
	uint32_t data1000 = data/1000 % 10;
	switch(digit)
	{
	case 0:
		FND0();
		FND_Display(data1);
		break;
	case 1:
		FND10();
		FND_Display(data10);
		break;
	case 2:
		FND100();
		FND_Display(data100);
		break;
	case 3:
		FND1000();
		FND_Display(data1000);
		break;
	}
	digit ++;
	if(digit ==4)
	{
		digit = 0;
	}
	delay(1);

};


void FND0()
{
	GPIO_WritePin(GPIOC, 8, PIN_SET);
	GPIO_WritePin(GPIOC, 6, PIN_SET);
	GPIO_WritePin(GPIOC, 5, PIN_SET);
	GPIO_WritePin(GPIOA, 12, PIN_RESET);
};

void FND10()
{
	GPIO_WritePin(GPIOC, 8, PIN_SET);
	GPIO_WritePin(GPIOC, 6, PIN_SET);
	GPIO_WritePin(GPIOC, 5, PIN_RESET);
	GPIO_WritePin(GPIOA, 12, PIN_SET);
};

void FND100()
{
	GPIO_WritePin(GPIOC, 8, PIN_SET);
	GPIO_WritePin(GPIOC, 6, PIN_RESET);
	GPIO_WritePin(GPIOC, 5, PIN_SET);
	GPIO_WritePin(GPIOA, 12, PIN_SET);
};

void FND1000()
{
	GPIO_WritePin(GPIOC, 8, PIN_RESET);
	GPIO_WritePin(GPIOC, 6, PIN_SET);
	GPIO_WritePin(GPIOC, 5, PIN_SET);
	GPIO_WritePin(GPIOA, 12, PIN_SET);
};


void FND_Display(uint32_t data)
{
	switch(data)
	{
	case 0:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_RESET);
		break;
	case 1:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_RESET);
		break;
	case 2:
	{
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_SET);
		break;
	}
	case 3:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_SET);
		break;
	case 4:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_SET);
		break;
	case 5:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_SET);
		break;
	case 6:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_SET);
		break;
	case 7:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_RESET);
		break;
	case 8:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_SET);
		break;
	case 9:
		GPIO_WritePin(FND_Bar[0].GPIOx, FND_Bar[0].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[1].GPIOx, FND_Bar[1].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[2].GPIOx, FND_Bar[2].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[3].GPIOx, FND_Bar[3].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[4].GPIOx, FND_Bar[4].pinNum, PIN_RESET);
		GPIO_WritePin(FND_Bar[5].GPIOx, FND_Bar[5].pinNum, PIN_SET);
		GPIO_WritePin(FND_Bar[6].GPIOx, FND_Bar[6].pinNum, PIN_SET);
		break;

	}

}
//
//FND_Display()
//{
//	GPIO_WritePin(GPIOC, pinNum, pin_State)
//
//};
