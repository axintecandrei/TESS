/*
 * tess_motordriver.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#include <sys/_stdint.h>
#include <tess_act_statemachine.h>
#include <tess_sys_constants.h>
#include <tess_utilities.h>
#include "tess_motorcontrol.h"

static void Tess_MotCtrl_SpeedControl(tess_act_motor_t* Motor);
static void Tess_MotCtrl_CurrentControl(tess_act_motor_t* Motor);
static void Tess_VoltToDtc(tess_act_motor_t* Motor, float DcLinkVoltage);


void Tess_MotCtrl_Init(void)
{
    uint8_t MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
        Motor[MotorIndex].SpeedCtrl.Pgain          = 0.00032;/*0.1*/
        Motor[MotorIndex].SpeedCtrl.Igain          = 0.000188;     /*2.5*/
        Motor[MotorIndex].SpeedCtrl.IntegralPart   = 0;

        Motor[MotorIndex].CurrentCtrl.Pgain        = 2.65;
        Motor[MotorIndex].CurrentCtrl.Igain        = 1220.18;
        Motor[MotorIndex].CurrentCtrl.IntegralPart = 0;

        Motor[MotorIndex].Requests.PwmDtc          = 0.5;
        Motor[MotorIndex].Requests.Voltage         = 0;
        Motor[MotorIndex].Requests.Current         = 0;
        Motor[MotorIndex].Requests.Speed           = 0;
    }
}

void Tess_MotCtrl_Main(void)
{

    Tess_Act_StateMachine();

    Tess_MotCtrl_CurrentControl(Motor);
    Tess_MotCtrl_SpeedControl(Motor);

    Tess_VoltToDtc(Motor, MipDcLinkVoltage);
    Tess_MotDrv_SetMotorsPwm(Motor[M1].Requests.PwmDtc,
                             Motor[M2].Requests.PwmDtc,
                             Motor[M3].Requests.PwmDtc,
                             Motor[M4].Requests.PwmDtc);

}

static void Tess_MotCtrl_SpeedControl(tess_act_motor_t* Motor)
{
    float Error = 0;
    float ProportionalPart = 0;
    float IntegralPart = 0;
    uint8_t MotorIndex = 0;
    uint8_t SatOn      = 1;
    if((MotCtrlStateMachine.ControlWord & Moc_Speed) > 0)
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Error                = Motor[MotorIndex].Requests.Speed - Motor[MotorIndex].MotorInputs.MotorSpeed;
            ProportionalPart     = Motor[MotorIndex].SpeedCtrl.Pgain*Error;
            IntegralPart         = Motor[MotorIndex].SpeedCtrl.IntegralPart + Error*TESS_TS;

            if((MotCtrlStateMachine.ControlWord & Moc_Current)  > 0)
            {
                Motor[MotorIndex].Requests.Current = ProportionalPart + IntegralPart*Motor[MotorIndex].SpeedCtrl.Igain;

                /*Anti-WIndup*/
                if (Motor[MotorIndex].Requests.Current > TESS_MAX_REQ_CURRENT)
                {
                    Motor[MotorIndex].Requests.Current = TESS_MAX_REQ_CURRENT;
                    if (Error>0)
                    {
                        SatOn = 0;
                    }
                }
                else if(Motor[MotorIndex].Requests.Current < 0) /*Min current request is 0 mA*/
                {
                    Motor[MotorIndex].Requests.Current = 0;
                    if (Error<0)
                      {
                          SatOn = 0;
                      }
                }
                if (SatOn == 1)
                {
                    Motor[MotorIndex].SpeedCtrl.IntegralPart = IntegralPart;
                }


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
    float Error = 0;
    float ProportionalPart = 0;
    float IntegralPart = 0;
    uint8_t MotorIndex = 0;
    uint8_t SatOn      = 1;

    /*check if there is a need for the current controller*/
    if((MotCtrlStateMachine.ControlWord & Moc_Current)  > 0)
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Error             = Motor[MotorIndex].Requests.Current - Motor[MotorIndex].MotorInputs.Current;
            ProportionalPart  = Motor[MotorIndex].CurrentCtrl.Pgain*Error;
            IntegralPart      = Motor[MotorIndex].CurrentCtrl.IntegralPart + Error*TESS_TS;

            Motor[MotorIndex].Requests.Voltage = ProportionalPart + IntegralPart*Motor[MotorIndex].CurrentCtrl.Igain;
            /*Anti-WIndup*/
            if (Motor[MotorIndex].Requests.Voltage > TESS_MAX_REQ_VOLT)
            {
                Motor[MotorIndex].Requests.Voltage = TESS_MAX_REQ_VOLT;

                if (Error>0)
                {
                    SatOn = 0;
                }
            }
            else if(Motor[MotorIndex].Requests.Voltage < -TESS_MAX_REQ_VOLT) /*Min current request is 0 mA*/
            {
                Motor[MotorIndex].Requests.Voltage = -TESS_MAX_REQ_VOLT;
                if (Error < 0)
                  {
                      SatOn = 0;
                  }
            }
            if (SatOn == 1)
            {
                Motor[MotorIndex].CurrentCtrl.IntegralPart = IntegralPart;
            }
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
        Motor[M1].Requests.PwmDtc = Saturate(0.5F + ( Motor[M1].Requests.Voltage/DcLinkVoltage),0.02F,0.98F);
        Motor[M2].Requests.PwmDtc = Saturate(0.5F + ( Motor[M2].Requests.Voltage/DcLinkVoltage),0.02F,0.98F);
        Motor[M3].Requests.PwmDtc = Saturate(0.5F + ( Motor[M3].Requests.Voltage/DcLinkVoltage),0.02F,0.98F);
        Motor[M4].Requests.PwmDtc = Saturate(0.5F + ( Motor[M4].Requests.Voltage/DcLinkVoltage),0.02F,0.98F);
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
    Motor[MotorIndex].Requests.PwmDtc          = 0.5;
    Motor[MotorIndex].Requests.Voltage         = 0;
    Motor[MotorIndex].Requests.Current         = 0;
    Motor[MotorIndex].Requests.Speed           = 0;
    }
}
