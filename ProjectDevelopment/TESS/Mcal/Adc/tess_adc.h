/*
 * tess_adc.h
 *
 *  Created on: Dec 19, 2021
 *      Author: axinteandrei
 */

#ifndef MCAL_ADC_TESS_ADC_H_
#define MCAL_ADC_TESS_ADC_H_

#include "StandardTypes.h"
#include "tess_mcal.h"

#define ADC_DMA_BUFFER_SIZE   (5U)

uint16_t AdcDmaBuffer[ADC_DMA_BUFFER_SIZE];

#endif /* MCAL_ADC_TESS_ADC_H_ */
