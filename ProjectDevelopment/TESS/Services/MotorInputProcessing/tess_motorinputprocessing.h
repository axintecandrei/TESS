/*
 * tess_motorinputprocessing.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_MOTORINTPUTPROC_H_
#define TESS_MOTORINTPUTPROC_H_

#include "Rte_adc.h"
#include "Rte_motorinputprocessing.h"
#include "Rte_encoders.h"
#include "tess_moc_types.h"
#include "tess_moc_param.h"


#define HAL_MCU_CLOCK_FREQUENCY   	(170000000)
#define HAL_MCU_TIM_PRESCALER     	(399)
#define TESS_MIP_STANDSTILL_TIME   	(6.8F)       /*ms*/
#define TESS_MIP_STANDSTILL_THR    	((uint8)(TESS_MIP_STANDSTILL_TIME/0.2F))

void Tess_Mip_Init();
void Tess_Mip_Main();

#endif /* TESS_MOTORINTPUTPROC_H_ */
