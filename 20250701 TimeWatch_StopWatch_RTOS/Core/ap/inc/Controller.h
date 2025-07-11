/*
 * Controller.h
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#ifndef AP_CONTROLLER_H_
#define AP_CONTROLLER_H_

#include "stopwatch.h"
#include "timewatch.h"

typedef struct {
	int id;
	int data;
}inputData_TypeDef;




enum {NO_CONTROL, MODE,STOPWATCH_RUN_STOP,STOPWATCH_CLEAR};
enum {MODE_NO_ACT,MODE_ACT,STOPWATCH_NO_ACT,STOPWATCH_ACT};

void Controller_SetInputData(inputData_TypeDef inputData);
void Controller_execute();



#endif /* AP_CONTROLLER_H_ */
