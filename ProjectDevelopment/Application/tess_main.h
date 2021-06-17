/*
 * tess_main.h
 *
 *  Created on: Jun 17, 2021
 *      Author: nxf70809
 */

#ifndef TESS_MAIN_H_
#define TESS_MAIN_H_

#include "stm32g4xx_hal.h"
#include "freemaster.h"
#include "freemaster_private.h"


#define ADC_BUFFER_SIZE  5

uint16_t ADC_VALUE[ADC_BUFFER_SIZE];
uint16_t PwmInputM1;
uint16_t PwmInputM2;
uint16_t PwmInputM3;
uint16_t PwmInputM4;
extern TIM_HandleTypeDef htim1;


void TessMain(void);
void TessMainInit(void);

#endif /* TESS_MAIN_H_ */
