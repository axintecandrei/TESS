/*
 * Rte_pwm.h
 *
 *  Created on: Dec 20, 2021
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_PWM_H_
#define RTE_RTE_PWM_H_

#include "StandardTypes.h"
#include "tess_mcal.h"


#define TESS_PWM_PERIOD  (htim1.Init.Period)

typedef enum
{
    PwmChannel1,
	PwmChannel2,
	PwmChannel3,
	PwmChannel4
}PwmChannelsMap_t;

extern TIM_HandleTypeDef htim1;

extern void Tess_Pwm_SetChannelxDTC(PwmChannelsMap_t Channel, uint16_t PwmTicks);
extern void Tess_Pwm_SetChannelNxDTC(PwmChannelsMap_t Channel, uint16_t PwmTicks);

#endif /* RTE_RTE_PWM_H_ */
