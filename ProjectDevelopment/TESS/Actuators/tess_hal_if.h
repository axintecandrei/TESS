/*
 * tess_hal_if.h
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_HAL_IF_H_
#define TESS_HAL_IF_H_

#include "stm32g4xx_hal.h"

#define RAW_ADC_BUFFER_SIZE   (5U)

enum
{
    ADC_M1,
    ADC_M2,
    ADC_M3,
    ADC_DcLink,
    ADC_M4
}AdcBufferMap;

typedef struct
{
    float M1;
    float M2;
    float M3;
    float M4;
}mip_raw_pwminput_t;

uint16_t RawAdcValue[RAW_ADC_BUFFER_SIZE];


mip_raw_pwminput_t RawPwmInput;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
#endif /* TESS_HAL_IF_H_ */
