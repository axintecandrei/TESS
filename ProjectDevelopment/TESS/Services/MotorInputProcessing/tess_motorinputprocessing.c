/*
 * tess_motordriver.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#include "tess_motorinputprocessing.h"

static void Tess_Mip_GetMotorSpeed(tess_act_motor_t* Motors);
static void Tess_Mip_GetMotorCurrents(tess_act_motor_t* Motors);
static void Tess_Mip_GetDcLinkVoltage(void);

void Tess_Mip_Init(void)
{
    uint8 MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
        Motor[MotorIndex].MotorInputs.Current    = 0;
        Motor[MotorIndex].MotorInputs.Voltage    = 0;
        Motor[MotorIndex].MotorInputs.MotorSpeed = 0;
        Motor[MotorIndex].MotorInputs.WheelSpeed = 0;

    }

}

void Tess_Mip_Main(void)
{
    Tess_Mip_GetDcLinkVoltage();
    Tess_Mip_GetMotorCurrents(Motor);
    Tess_Mip_GetMotorSpeed(Motor);
}

static void Tess_Mip_GetDcLinkVoltage(void)
{
	Set_TessMipDcLinkVoltage(Tess_Adc_GetValue(AdcChannelDcLink)*TESS_VOLTAGE_DIV_RATIO);
}

static void Tess_Mip_GetMotorCurrents(tess_act_motor_t* Motors)
{
	Motors[M1].MotorInputs.Current = (Tess_Adc_GetValue(AdcChannelM1Cur)-TESS_CURRENT_SENSOR_OFFSET)/TESS_CURRENT_SENSOR_GAIN;
    Motors[M2].MotorInputs.Current = (Tess_Adc_GetValue(AdcChannelM2Cur)-TESS_CURRENT_SENSOR_OFFSET)/TESS_CURRENT_SENSOR_GAIN;
    Motors[M3].MotorInputs.Current = (Tess_Adc_GetValue(AdcChannelM3Cur)-TESS_CURRENT_SENSOR_OFFSET)/TESS_CURRENT_SENSOR_GAIN;
    Motors[M4].MotorInputs.Current = (Tess_Adc_GetValue(AdcChannelM4Cur)-TESS_CURRENT_SENSOR_OFFSET)/TESS_CURRENT_SENSOR_GAIN;
}

static void Tess_Mip_GetMotorSpeed(tess_act_motor_t* Motors)
{
	float Frequency;
	uint8 MotorIndex = 0;
	static uint8 MotorSpeedStandstillCounter[TESS_MOTOR_NUMBERS] = {0,0,0,0};
	static uint8 PrevEncoderFlag[TESS_MOTOR_NUMBERS] = {0,0,0,0};

	for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
	{

		/*Check if motor is standstill*/
		if(Get_TessNewEncoderCapture(MotorIndex) == PrevEncoderFlag[MotorIndex])
		{
			MotorSpeedStandstillCounter[MotorIndex]++;
			if (MotorSpeedStandstillCounter[MotorIndex] > TESS_MIP_STANDSTILL_THR)
			{
				MotorSpeedStandstillCounter[MotorIndex] = TESS_MIP_STANDSTILL_THR;
			}
		}
		else
		{
			MotorSpeedStandstillCounter[MotorIndex] = 0;
		}


	    /*if motor does not spins within 0.0024 ms -speed less than 7-10 rpm
	     * set speed to 0*/
		if(MotorSpeedStandstillCounter[MotorIndex] < TESS_MIP_STANDSTILL_THR)
		{
			Frequency = HAL_MCU_CLOCK_FREQUENCY/(((float)Get_TessEncoderPeriod(MotorIndex))*((float)HAL_MCU_TIM_PRESCALER));
			Motors[MotorIndex].MotorInputs.MotorSpeed = (Frequency*60.0F)/TESS_ENCODER_PPR;
		}
		else
		{
			Motors[MotorIndex].MotorInputs.MotorSpeed = 0;
		}
		Motors[MotorIndex].MotorInputs.WheelSpeed = Motors[MotorIndex].MotorInputs.MotorSpeed/TESS_GEAR_RATIO;

		PrevEncoderFlag[MotorIndex] = Get_TessNewEncoderCapture(MotorIndex);
	}

}

