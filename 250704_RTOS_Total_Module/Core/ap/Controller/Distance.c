/*
 * Distance.c
 *
 *  Created on: Jul 4, 2025
 *      Author: kccistc
 */

#include "Distance.h"

Distance_t distanceData;
extern UltraSonic_TypeDef sensor;

void Distance_Init()
{
	distanceData.distance = 0;

	Distance_t *pDistanceData = osMailAlloc(DistanceDataMailBox, 0);
	memcpy(pDistanceData, &distanceData, sizeof(Distance_t));
	osMailPut(DistanceDataMailBox, pDistanceData);
}

void Distance_Execute()
{
	Distance_Measurement();
}

void Distance_Measurement()
{
	osEvent evt = osMessageGet(DistanceEventMsgBox, 0);
	uint16_t evtState;

	if (evt.status == osEventMessage) {
		evtState = evt.value.v;

		if (evtState == EVENT_DISTANCE) {
			distanceData.distance = UltraSonic_GetDistance(&sensor);

			Distance_t *pDistanceData = osMailAlloc(DistanceDataMailBox, 0);
			memcpy(pDistanceData, &distanceData, sizeof(Distance_t));
			osMailPut(DistanceDataMailBox, pDistanceData);
		}
	}
}
