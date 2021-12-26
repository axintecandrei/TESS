/*
 * tess_motordriver.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#include "tess_actuator_manager.h"
#include "tess_moc_param.h"
#include "stdint.h"
#include "tess_utilities.h"
#include "tess_motorcontrol.h"

static void Tess_MotCtrl_SpeedControl(tess_act_motor_t* Motor);
static void Tess_MotCtrl_CurrentControl(tess_act_motor_t* Motor);
static void Tess_VoltToDtc(tess_act_motor_t* Motor, float DcLinkVoltage);


void Tess_MotCtrl_Init(void)
{
    uint8_t MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
        Motor[MotorIndex].SpeedCtrl.Pgain          = 0.024;      /*0.1*/
        Motor[MotorIndex].SpeedCtrl.Igain          = 3.35;     /*2.5*/
        Motor[MotorIndex].SpeedCtrl.IntegralPart   = 0;

        Motor[MotorIndex].CurrentCtrl.Pgain        = 0.0188;
        Motor[MotorIndex].CurrentCtrl.Igain        = 377.55;
        Motor[MotorIndex].CurrentCtrl.IntegralPart = 0;

        Motor[MotorIndex].Requests.Voltage         = 0;
        Motor[MotorIndex].Requests.Current         = 0;
        Motor[MotorIndex].Requests.Speed           = 0;
    }
}

void Tess_MotCtrl_Main(void)
{

    Tess_MotCtrl_CurrentControl(Motor);
    Tess_MotCtrl_SpeedControl(Motor);


}

static void Tess_MotCtrl_SpeedControl(tess_act_motor_t* Motor)
{
    float Error = 0;
    float ProportionalPart = 0;
    float IntegralPart     = 0;
    float UnSatOutput      = 0;
    uint8_t MotorIndex     = 0;
    uint8_t SatOn          = 1;

    if((MotCtrlStateMachine.ControlWord & Moc_Speed) > 0)
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Error                = Motor[MotorIndex].Requests.Speed - Motor[MotorIndex].MotorInputs.MotorSpeed;
            Motor[MotorIndex].SpeedCtrl.Error = Error;
            ProportionalPart     = Motor[MotorIndex].SpeedCtrl.Pgain*Error;
            Motor[MotorIndex].SpeedCtrl.ProportionalPart = ProportionalPart;
            IntegralPart         = Motor[MotorIndex].SpeedCtrl.IntegralPart + SatOn*Error*TESS_TS;

            if((MotCtrlStateMachine.ControlWord & Moc_Current)  > 0)
            {
                UnSatOutput = ProportionalPart + IntegralPart*Motor[MotorIndex].SpeedCtrl.Igain;
                Motor[MotorIndex].Requests.Current = Saturate(UnSatOutput,0,TESS_MAX_REQ_CURRENT);

                /*Anti-WIndup*/
#if 1
                if (Motor[MotorIndex].Requests.Current != UnSatOutput)
                {
                    SatOn = 0;
                }
                else
                {
                    SatOn = 1;
                }


                if (Sign(UnSatOutput) == Sign(Error))
                {
                    SatOn = 0;
                }
                else
                {
                    SatOn = 1;
                }
                Motor[MotorIndex].SpeedCtrl.Sat = SatOn;
#endif
                Motor[MotorIndex].SpeedCtrl.IntegralPart = IntegralPart;
            }
            else
            {
                Motor[MotorIndex].Requests.Voltage = ProportionalPart + Motor[MotorIndex].SpeedCtrl.IntegralPart*Motor[MotorIndex].SpeedCtrl.Igain;
                Motor[MotorIndex].Requests.Voltage = Saturate(Motor[MotorIndex].Requests.Voltage,-TESS_MAX_REQ_VOLT,TESS_MAX_REQ_VOLT);
            }
         }
    }
    else
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Motor[MotorIndex].SpeedCtrl.IntegralPart = 0;
        }
    }

}

static void Tess_MotCtrl_CurrentControl(tess_act_motor_t* Motor)
{
    float Error            = 0;
    float ProportionalPart = 0;
    float IntegralPart     = 0;
    float UnSatOutput      = 0;
    uint8_t MotorIndex     = 0;
    uint8_t OutputSaturate = 0;
    uint8_t SameSign       = 0;
    uint8_t DisableSat     = 1;


    /*check if there is a need for the current controller*/
    if((MotCtrlStateMachine.ControlWord & Moc_Current)  > 0)
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Error             = Motor[MotorIndex].Requests.Current - Motor[MotorIndex].MotorInputs.Current;
            Motor[MotorIndex].CurrentCtrl.Error = Error;
            ProportionalPart  = Motor[MotorIndex].CurrentCtrl.Pgain*Error;
            Motor[MotorIndex].CurrentCtrl.ProportionalPart = ProportionalPart;
            IntegralPart      = Motor[MotorIndex].CurrentCtrl.IntegralPart + DisableSat*Error*TESS_TS;

            UnSatOutput = ProportionalPart + IntegralPart*Motor[MotorIndex].CurrentCtrl.Igain;
            Motor[MotorIndex].Requests.Voltage = Saturate(UnSatOutput,-TESS_MAX_REQ_VOLT,TESS_MAX_REQ_VOLT);
            /*Anti-WIndup*/

            if (Motor[MotorIndex].Requests.Voltage != UnSatOutput)
            {
                OutputSaturate = 1;
            }
            else
            {
                OutputSaturate = 0;
            }


            if (Sign(UnSatOutput) == Sign(Error))
            {
                SameSign = 1;
            }
            else
            {
                SameSign = 0;
            }

            if (OutputSaturate && SameSign)
            {
                DisableSat = 0;
            }
            else
            {
                DisableSat = 1;
            }

            Motor[MotorIndex].CurrentCtrl.Sat = DisableSat;
            Motor[MotorIndex].CurrentCtrl.IntegralPart = DisableSat*IntegralPart;

        }
    }else
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Motor[MotorIndex].CurrentCtrl.IntegralPart = 0;
        }
    }
}


static void Tess_VoltToDtc(tess_act_motor_t* Motor, float DcLinkVoltage)
{
    if((MotCtrlStateMachine.ControlWord & Moc_Voltage)  > 0)
    {
        /*Motor[M1].Requests.PwmDtc = Saturate(0.5F + ( Motor[M1].Requests.Voltage/DcLinkVoltage),0.02F,0.98F);
        Motor[M2].Requests.PwmDtc = Saturate(0.5F + ( Motor[M2].Requests.Voltage/DcLinkVoltage),0.02F,0.98F);
        Motor[M3].Requests.PwmDtc = Saturate(0.5F + ( Motor[M3].Requests.Voltage/DcLinkVoltage),0.02F,0.98F);
        Motor[M4].Requests.PwmDtc = Saturate(0.5F + ( Motor[M4].Requests.Voltage/DcLinkVoltage),0.02F,0.98F);*/
    }else
    {
        /*do nothing*/
    }
}

void Tess_MotCtrl_ResetInputs(void)
{
    uint8_t MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
    	Motor[MotorIndex].Requests.Voltage         = 0;
    	Motor[MotorIndex].Requests.Current         = 0;
    	Motor[MotorIndex].Requests.Speed           = 0;
    }
}
