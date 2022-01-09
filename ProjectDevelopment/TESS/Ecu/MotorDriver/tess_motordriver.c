/*
 * tess_motordriver.c
 *
 *  Created on: Dec 20, 2021
 *      Author: axinteandrei
 */

#include "tess_motordriver.h"


static uint8_t MotorToPwmChannel[4] =
{
	PwmChannel2, /*M1*/
	PwmChannel1, /*M2*/
	PwmChannel3, /*M3*/
	PwmChannel4  /*M4*/
};


void Tess_MotorDrv_SetMotorPwm(uint8 MotorChannel, uint16 DutyCycle)
{
	/*From dtc to pwm ticks*/
	uint16 LocPwmTicks = 0;

	LocPwmTicks = (float)(DutyCycle*TESS_PWM_PERIOD)/1000.0F;

	Tess_Pwm_SetChannelxDTC(MotorToPwmChannel[MotorChannel],LocPwmTicks);
	Tess_Pwm_SetChannelxDTC(MotorToPwmChannel[MotorChannel],TESS_PWM_PERIOD - LocPwmTicks);
}
