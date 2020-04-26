/*
 * lld_timers.h
 *
 *  Created on: 11 apr. 2020
 *      Author: uidp7521
 */

#ifndef USERDEFINED_LLD_TIMERS_H_
#define USERDEFINED_LLD_TIMERS_H_
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "../_Main_/utilities.h"


#define TIM2_CLEAR_IT()                      do{TIM2->SR &= ~(TIM_SR_UIF);}while(0)

void TIMER2_INIT();
void TESS_GPIO_INIT();
#endif /* USERDEFINED_LLD_TIMERS_H_ */
