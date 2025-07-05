/*
 * Presenter_TempHumi.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */


#include "Presenter_TempHumi.h"
#include <string.h>
#include <stdio.h>

void Presenter_TempHumiInit()
{
	LCD_Init(&hi2c1);
}

void Presenter_TempHumiExecute()
{
	TempHumi_t TempHumiData;
	TempHumi_t *pTempHumiData;

	osEvent evt = osMailGet(TempHumiDataMailBox, 0);
	if (evt.status == osEventMail) {
		pTempHumiData = evt.value.p;
		memcpy(&TempHumiData, pTempHumiData, sizeof(TempHumi_t));
		osMailFree(TempHumiDataMailBox, pTempHumiData);

		Presenter_TempHumi_FND(TempHumiData);
		Presenter_TempHumi_LCD(TempHumiData);
	}
}

void Presenter_TempHumi_FND(TempHumi_t TempHumiData)
{
	FND_WriteData(TempHumiData.TempHumi);

}

void Presenter_TempHumi_LCD(TempHumi_t TempHumiData)
{
	char str[50];
	char str1[50];

	sprintf(str, "T : %02d H : %02d  ", (TempHumiData.TempHumi)/100, (TempHumiData.TempHumi)%100);
	LCD_writeStringXY(0, 0, str);
	sprintf(str1, "                 ");
	LCD_writeStringXY(1, 0, str1);
}
