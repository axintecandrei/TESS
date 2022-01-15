/*
 * tess_motoroutputprocessing.c
 *
 *  Created on: Jan 6, 2022
 *      Author: axinteandrei
 */

#include "tess_motoroutputprocessing.h"

static void Tess_Mop_SetDutyCycle(uint8 Motor, uint16 MotorVoltage);
static uint16 Tess_Mop_Voltage2DutyCycle(uint16 Voltage);

void Tess_Mop_Main(void)
{
	uint8 MotorIndex;

	if((Get_TessActMngControlWord() & Moc_Voltage) != 0)
	{
		for(MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS;MotorIndex++)
		{

			Tess_Mop_SetDutyCycle(MotorIndex,Tess_Mop_Voltage2DutyCycle((uint16)Get_TessMocVoltageRequest(MotorIndex)));
		}
	}
	else if((Get_TessActMngControlWord() & Moc_Pwm) != 0)
	{
		for(MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS;MotorIndex++)
		{
			Tess_Mop_SetDutyCycle(MotorIndex,(uint16)Get_TessMopRequestDtc(MotorIndex));
		}
	}
	else if((Get_TessActMngControlWord() & Moc_StandBy) != 0)
	{
		for(MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
		{
			Tess_Mop_SetDutyCycle(MotorIndex,TESS_STANDBY_DTC);
		}
	}
}

static uint16 Tess_Mop_Voltage2DutyCycle(uint16 MotorVoltage)
{
	return (((float)MotorVoltage/(float)Get_TessMipDcLinkVoltage())*1000U);
}

static void Tess_Mop_SetDutyCycle(uint8 Motor, uint16 ReqDutyCycle)
{

	ReqDutyCycle = Saturate(ReqDutyCycle,TESS_MIN_DTC,TESS_MAX_DTC);
	Tess_MotorDrv_SetMotorPwm(Motor,ReqDutyCycle);
}
