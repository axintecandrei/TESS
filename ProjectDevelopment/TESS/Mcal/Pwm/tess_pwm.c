/*
 * tess_pwm.c
 *
 *  Created on: Dec 20, 2021
 *      Author: axinteandrei
 */

#include "tess_pwm.h"

void Tess_Pwm_Init(void)
{

}

void Tess_Pwm_SetChannelxDTC(PwmChannelsMap_t Channel, uint16_t PwmTicks)
{
	switch(Channel)
	{
	case PwmChannel1:
	    htim1.Instance->CCR1 = PwmTicks;
		break;
	case PwmChannel2:
        htim1.Instance->CCR3 = PwmTicks;
		break;
	case PwmChannel3:
        htim8.Instance->CCR1 = PwmTicks;
		break;
	case PwmChannel4:
        htim8.Instance->CCR3 = PwmTicks;
		break;
	default:
		break;
	}
}

void Tess_Pwm_SetChannelNxDTC(PwmChannelsMap_t Channel, uint16_t PwmTicks)
{
	switch(Channel)
	{
	case PwmChannel1:
	    htim1.Instance->CCR2 = PwmTicks;
		break;
	case PwmChannel2:
        htim1.Instance->CCR4 = PwmTicks;
		break;
	case PwmChannel3:
        htim8.Instance->CCR2 = PwmTicks;
		break;
	case PwmChannel4:
        htim8.Instance->CCR4 = PwmTicks;
		break;
	default:
		break;
	}
}
