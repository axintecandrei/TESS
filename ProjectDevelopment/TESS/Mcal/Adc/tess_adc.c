/*
 * tess_adc.c
 *
 *  Created on: Dec 19, 2021
 *      Author: axinteandrei
 */

#include "tess_adc.h"


void Tess_Adc_Init(void)
{

}

uint16 Tess_Adc_GetValue(uint8_t Channel)
{
	return AdcDmaBuffer[Channel];
}
