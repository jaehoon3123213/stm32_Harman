/*
 * Model_TempHumi.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */


#include "Model_TempHumi.h"

osMailQId TempHumiDataMailBox;
osMailQDef(TempHumiDataQueue, 16, TempHumi_t);

osMessageQId TempHumiEventMsgBox;
osMessageQDef(TempHumiEventQueue, 4, uint16_t);

void Model_TempHumiInit()
{
	TempHumiEventMsgBox = osMessageCreate(osMessageQ(TempHumiEventQueue), NULL);
	TempHumiDataMailBox = osMailCreate(osMailQ(TempHumiDataQueue), NULL);
}
