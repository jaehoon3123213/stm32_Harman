/*
 * Presenter_Distance.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */


#include "Presenter_Distance.h"
#include <string.h>
#include <stdio.h>

void Presenter_DistanceInit()
{
	LCD_Init(&hi2c1);
}
void Presenter_DistanceExecute()
{
	Distance_t DistanceData;
	Distance_t *pDistanceData;

	osEvent evt = osMailGet(DistanceDataMailBox, 0);
	if (evt.status == osEventMail) {
		pDistanceData = evt.value.p;
		memcpy(&DistanceData, pDistanceData, sizeof(Distance_t));
		osMailFree(DistanceDataMailBox, pDistanceData);

		Presenter_Distance_FND(DistanceData);
		Presenter_Distance_LCD(DistanceData);
	}
}

void Presenter_Distance_FND(Distance_t distanceData)
{
	FND_WriteData(distanceData.distance);

}

void Presenter_Distance_LCD(Distance_t distanceData)
{
	char str[50];
	char str1[50];
	sprintf(str, "Distance : %02d   ", distanceData.distance);
	sprintf(str1, "                 ");
	LCD_writeStringXY(0, 0, str);
	LCD_writeStringXY(1, 0, str1);
}
