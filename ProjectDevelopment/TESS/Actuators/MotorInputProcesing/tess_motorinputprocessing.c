/*
 * tess_motordriver.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#include "tess_motorinputprocessing.h"

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
        Motor[MotorIndex].SpeedEst.Iak1          = 0;
        Motor[MotorIndex].SpeedEst.Vak1          = 0;
        Motor[MotorIndex].SpeedEst.Speedk1       = 0;
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
    Tess_Mip_SpeedEstimation (Motor);
}

static void Tess_Mip_GetDcLinkVoltage(void)
{
    MipDcLinkVoltage = RawAdcValue[ADC_DcLink]*TESS_VOLTAGE_DIV_RATIO;
}

static void Tess_Mip_GetMotorVoltages(tess_act_motor_t* Motors)
{
    Motors[M1].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M1) - (MipDcLinkVoltage*0.5F);
    Motors[M2].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M2) - (MipDcLinkVoltage*0.5F);
    Motors[M3].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M3) - (MipDcLinkVoltage*0.5F);
    Motors[M4].MotorInputs.Voltage = (MipDcLinkVoltage*RawPwmInput.M4) - (MipDcLinkVoltage*0.5F);
}

static void Tess_Mip_GetMotorCurrents(tess_act_motor_t* Motors)
{
    Motors[M1].MotorInputs.Current = RawAdcValue[ADC_M1];
    Motors[M2].MotorInputs.Current = RawAdcValue[ADC_M2]/TESS_CURRENT_SENSOR_GAIN;
    Motors[M3].MotorInputs.Current = RawAdcValue[ADC_M3]/TESS_CURRENT_SENSOR_GAIN;
    Motors[M4].MotorInputs.Current = RawAdcValue[ADC_M4]/TESS_CURRENT_SENSOR_GAIN;
}

static void Tess_Mip_SpeedEstimation(tess_act_motor_t* Motors)
{
    uint8_t MotorIndex = 0;
    float d_ia, backEMF;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {

#if 0 /*Fw euler*/
        /*Calculate current derivative*/
        d_ia = Motors[MotorIndex].SpeedEst.Iak1 - Motors[MotorIndex].MotorInputs.Current;
        Motors[MotorIndex].SpeedEst.Iak1 = Motors[MotorIndex].MotorInputs.Current;

        /*Apply invers DC motor model and calculate backEMF*/
        backEMF  = (Motors[MotorIndex].MotorInputs.Voltage -
                    Motors[MotorIndex].MotorInputs.Current*Motors[MotorIndex].Param.R -
                    (d_ia*Motors[MotorIndex].Param.L*TESS_TS))*TESS_mV_V;

#else /*Trapezoidal*/
        d_ia = Motors[MotorIndex].SpeedEst.Iak1 - Motors[MotorIndex].MotorInputs.Current;
        backEMF = (Motors[MotorIndex].SpeedEst.Vak1 + Motors[MotorIndex].MotorInputs.Voltage -
                   Motors[MotorIndex].Param.R*(Motors[MotorIndex].SpeedEst.Iak1 + Motors[MotorIndex].MotorInputs.Current) -
                   2*TESS_TS*Motors[MotorIndex].Param.L*d_ia - Motors[MotorIndex].Param.Ke*Motors[MotorIndex].SpeedEst.Speedk1)*TESS_mV_V;

        Motors[MotorIndex].SpeedEst.Iak1    = Motors[MotorIndex].MotorInputs.Current;
        Motors[MotorIndex].SpeedEst.Vak1    = Motors[MotorIndex].MotorInputs.Voltage;
        Motors[MotorIndex].SpeedEst.Speedk1 = Motors[MotorIndex].MotorInputs.MotorSpeed/TESS_RAD_TO_RPM;
#endif
        Motors[MotorIndex].MotorInputs.MotorSpeed  = backEMF/Motors[MotorIndex].Param.Ke ;
        Motors[MotorIndex].MotorInputs.MotorSpeed *= TESS_RAD_TO_RPM;
        Motors[MotorIndex].MotorInputs.WheelSpeed  = Motors[MotorIndex].MotorInputs.MotorSpeed/TESS_GEAR_RATIO;
        Motors[MotorIndex].SpeedEst.bEMF  = backEMF;
    }
}
