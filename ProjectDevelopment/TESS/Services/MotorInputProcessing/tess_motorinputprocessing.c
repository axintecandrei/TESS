/*
 * tess_motordriver.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#include "tess_motorinputprocessing.h"

static void Tess_Mip_GetMotorVoltages(tess_act_motor_t* Motors);
static void Tess_Mip_GetMotorCurrents(tess_act_motor_t* Motors);
static void Tess_Mip_GetDcLinkVoltage(void);

void Tess_Mip_Init()
{
    uint8 MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
        Motor[MotorIndex].MotorInputs.Current    = 0;
        Motor[MotorIndex].MotorInputs.Voltage    = 0;
        Motor[MotorIndex].MotorInputs.MotorSpeed = 0;
        Motor[MotorIndex].MotorInputs.WheelSpeed = 0;

    }

    Motor[M1].Param.R             = TESS_M1_RESISTANCE;
    Motor[M1].Param.L             = TESS_M1_INDUCTANCE;
    Motor[M1].Param.Ke            = TESS_M1_KE;

    Motor[M2].Param.R             = TESS_M2_RESISTANCE;
    Motor[M2].Param.L             = TESS_M2_INDUCTANCE;
    Motor[M2].Param.Ke            = TESS_M2_KE;

    Motor[M3].Param.R             = TESS_M3_RESISTANCE;
    Motor[M3].Param.L             = TESS_M3_INDUCTANCE;
    Motor[M3].Param.Ke            = TESS_M3_KE;

    Motor[M4].Param.R             = TESS_M4_RESISTANCE;
    Motor[M4].Param.L             = TESS_M4_INDUCTANCE;
    Motor[M4].Param.Ke            = TESS_M4_KE;
}

void Tess_Mip_Main()
{
    Tess_Mip_GetDcLinkVoltage();
    Tess_Mip_GetMotorVoltages(Motor);
    Tess_Mip_GetMotorCurrents(Motor);
}

static void Tess_Mip_GetDcLinkVoltage(void)
{
    MipDcLinkVoltage = Tess_Adc_GetValue(AdcChannelDcLink)*TESS_VOLTAGE_DIV_RATIO;
}

static void Tess_Mip_GetMotorVoltages(tess_act_motor_t* Motors)
{
    /*Motors[M1].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M1) - (MipDcLinkVoltage*0.5F);
    Motors[M2].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M2) - (MipDcLinkVoltage*0.5F);
    Motors[M3].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M3) - (MipDcLinkVoltage*0.5F);
    Motors[M4].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M4) - (MipDcLinkVoltage*0.5F);*/
}

static void Tess_Mip_GetMotorCurrents(tess_act_motor_t* Motors)
{
	Motors[M1].MotorInputs.Current = (Tess_Adc_GetValue(AdcChannelM1Cur)-TESS_CURRENT_SENSOR_OFFSET)/TESS_CURRENT_SENSOR_GAIN;
    Motors[M2].MotorInputs.Current = Tess_Adc_GetValue(AdcChannelM2Cur)/TESS_CURRENT_SENSOR_GAIN;
    Motors[M3].MotorInputs.Current = Tess_Adc_GetValue(AdcChannelM3Cur)/TESS_CURRENT_SENSOR_GAIN;
    Motors[M4].MotorInputs.Current = Tess_Adc_GetValue(AdcChannelM4Cur)/TESS_CURRENT_SENSOR_GAIN;
}
