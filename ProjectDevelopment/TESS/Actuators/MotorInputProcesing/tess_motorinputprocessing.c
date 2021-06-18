/*
 * tess_motordriver.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#include "tess_motorinputprocesing.h"

static void Tess_Mip_GetMotorVoltages(tess_act_motor_t* Motors);
static void Tess_Mip_GetMotorCurrents(tess_act_motor_t* Motors);
static void Tess_Mip_SpeedEstimation(tess_act_motor_t* Motors);
static void Tess_Mip_GetDcLinkVoltage(void);

void Tess_Mip_Init()
{
    uint8_t MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
        Motor[MotorIndex].MotorInputs.Current    = 0;
        Motor[MotorIndex].MotorInputs.Voltage    = 0;
        Motor[MotorIndex].MotorInputs.MotorSpeed = 0;
        Motor[MotorIndex].MotorInputs.WheelSpeed = 0;

        Motor[MotorIndex].Param.R  = TESS_MOTOR_RESISTANCE;
        Motor[MotorIndex].Param.L  = TESS_MOTOR_INDUCTANCE;
        Motor[MotorIndex].Param.Ke = TESS_MOTOR_KE;
    }
}

void Tess_Mip_Main()
{
    Tess_Mip_GetDcLinkVoltage();
    Tess_Mip_GetMotorVoltages(Motor);
    Tess_Mip_GetMotorCurrents(Motor);
    Tess_Mip_SpeedEstimation (Motor);
}

static void Tess_Mip_GetMotorVoltages(tess_act_motor_t* Motors)
{
    Motors[M1].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M1*0.01F) - (MipDcLinkVoltage*0.5F);
    Motors[M2].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M2*0.01F) - (MipDcLinkVoltage*0.5F);
    Motors[M3].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M3*0.01F) - (MipDcLinkVoltage*0.5F);
    Motors[M4].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M4*0.01F) - (MipDcLinkVoltage*0.5F);
}

static void Tess_Mip_GetMotorCurrents(tess_act_motor_t* Motors)
{
    Motors[M1].MotorInputs.Current = RawAdcValue[ADC_M1]*TESS_CURRENT_SENSOR_GAIN;
    Motors[M2].MotorInputs.Current = RawAdcValue[ADC_M2]*TESS_CURRENT_SENSOR_GAIN;
    Motors[M3].MotorInputs.Current = RawAdcValue[ADC_M3]*TESS_CURRENT_SENSOR_GAIN;
    Motors[M4].MotorInputs.Current = RawAdcValue[ADC_M4]*TESS_CURRENT_SENSOR_GAIN;
}

static void Tess_Mip_SpeedEstimation(tess_act_motor_t* Motors)
{
    uint8_t MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
        float d_ia, backEMF;

        /*Calculate current derivative*/
        d_ia = Motors[MotorIndex].MotorInputs.Current - Motors[MotorIndex].SpeedEst.Iak1;
        Motors[MotorIndex].SpeedEst.Iak1 = Motors[MotorIndex].MotorInputs.Current;

        /*Apply invers DC motor model and calculate backEMF*/
        backEMF  = (Motors[MotorIndex].MotorInputs.Voltage -
                    Motors[MotorIndex].MotorInputs.Current*Motors[MotorIndex].Param.R -
                    (d_ia*Motors[MotorIndex].Param.L*TESS_TS))*TESS_mV_V;
        /**/
        Motors[MotorIndex].MotorInputs.MotorSpeed = backEMF/Motors[MotorIndex].Param.Ke ;
        Motors[MotorIndex].MotorInputs.WheelSpeed = Motors[MotorIndex].MotorInputs.MotorSpeed/TESS_GEAR_RATIO ;
    }
}

static void Tess_Mip_GetDcLinkVoltage(void)
{
    MipDcLinkVoltage = RawAdcValue[ADC_DcLink]*TESS_VOLTAGE_DIV_RATIO;
}
