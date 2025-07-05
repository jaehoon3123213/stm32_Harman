/*
 * Model_Distance.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */


#include "Model_Distance.h"

osMailQId DistanceDataMailBox;
osMailQDef(DistanceDataQueue, 4, Distance_t);

osMessageQId DistanceEventMsgBox;
osMessageQDef(DistanceEventQueue, 4, uint16_t);

void Model_DistanceInit()
{
	DistanceEventMsgBox = osMessageCreate(osMessageQ(DistanceEventQueue), NULL);
	DistanceDataMailBox = osMailCreate(osMailQ(DistanceDataQueue), NULL);
}
//
//void Model_SetDistanceState(eDistanceState_t state)
//{
//	DistanceState = state;
//}
//
//eDistanceState_t Model_GetDistanceState()
//{
//	return DistanceState;
//}
