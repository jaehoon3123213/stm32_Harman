/*
 * queue.h
 *
 *  Created on: Jun 25, 2025
 *      Author: kccistc
 */

#ifndef AP_INC_QUEUE_H_
#define AP_INC_QUEUE_H_

#include "stm32h7xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUE_SIZE   8

typedef struct {
	int front ;
	int rear ;
	int typeSize;
	void *queData[QUE_SIZE];
} Que_TypeDef;

extern Que_TypeDef LCD_Que;

void Que_Init(Que_TypeDef *q, int size);
void Que_DeInit(Que_TypeDef *q, int size);

int isQueFull(Que_TypeDef *q);
int isQueEmpty(Que_TypeDef *q);

bool enQue(Que_TypeDef *q, void* pdata);
bool deQue(Que_TypeDef *q, void *pData);
bool peekQue(Que_TypeDef *q, void *pData);



#endif /* AP_INC_QUEUE_H_ */
