/*
 * Rte_adc.h
 *
 *  Created on: Dec 20, 2021
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_ADC_H_
#define RTE_RTE_ADC_H_

#include "StandardTypes.h"

typedef enum
{
    AdcChannelM1Cur, //M1 Current,
	AdcChannelM2Cur, //M2 Current,
	AdcChannelM3Cur, //M3 Current,
	AdcChannelDcLink, //DcLink Voltage,
	AdcChannelM4Cur  //M4 Current
}AdcBufferMap_t;

#define ADC_DMA_BUFFER_SIZE   (5U)

extern uint16 AdcDmaBuffer[ADC_DMA_BUFFER_SIZE];

extern uint16 Tess_Adc_GetValue(uint8 Channel);

#endif /* RTE_RTE_ADC_H_ */
