/*
 * tess_main.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_MAIN_H_
#define TESS_MAIN_H_

#include "stm32g4xx_hal.h"

#include "tess_act_statemachine.h"
#include "tess_motorcontrol.h"
#include "tess_motorinputprocesing.h"
#include "tess_motordriver.h"


void TessMain(void);
void TessMainInit(void);

#endif /* TESS_MAIN_H_ */
