/*
 * tess_motordriver.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#include "tess_motorcontrol.h"


static void Tess_MotCtrl_SpeedControl(tess_act_motor_t* Motors);
static void Tess_MotCtrl_CurrentControl(tess_act_motor_t* Motors);


void Tess_MotCtrl_Init(void)
{
    uint8 MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
        Motor[MotorIndex].SpeedCtrl.Pgain          = 0.229;
        Motor[MotorIndex].SpeedCtrl.Igain          = 2.68;
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
	Motor[1].Requests.Speed = Get_TessMocSpeedRequest(1);
    Tess_MotCtrl_SpeedControl(Motor);
    Tess_MotCtrl_CurrentControl(Motor);
}

static void Tess_MotCtrl_SpeedControl(tess_act_motor_t* Motors)
{
    float Error = 0;
    float ProportionalPart = 0;
    float IntegralPart     = 0;
    float UnSatOutput      = 0;
    uint8 MotorIndex     = 0;
    uint8 OutputSaturate = 0;
    uint8 SameSign       = 0;
    uint8 DisableSat     = 1;

    if((Get_TessActMngControlWord() & Moc_Speed) > 0)
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Error                = Motors[MotorIndex].Requests.Speed - Motors[MotorIndex].MotorInputs.MotorSpeed;
            Motors[MotorIndex].SpeedCtrl.Error = Error;
            ProportionalPart     = Motors[MotorIndex].SpeedCtrl.Pgain*Error;
            Motors[MotorIndex].SpeedCtrl.ProportionalPart = ProportionalPart;
            IntegralPart         = Motors[MotorIndex].SpeedCtrl.IntegralPart + DisableSat*Error*TESS_TS;

            UnSatOutput = ProportionalPart + Motors[MotorIndex].SpeedCtrl.IntegralPart*Motors[MotorIndex].SpeedCtrl.Igain;
            Motors[MotorIndex].Requests.Voltage = Saturate(UnSatOutput,-TESS_MAX_REQ_VOLT,TESS_MAX_REQ_VOLT);
            Set_TessMocVoltageRequest(MotorIndex,Motors[MotorIndex].Requests.Voltage);

            if((Get_TessActMngControlWord() & Moc_Current)  > 0)
            {
                UnSatOutput = ProportionalPart + IntegralPart*Motors[MotorIndex].SpeedCtrl.Igain;
                Motors[MotorIndex].Requests.Current = Saturate(UnSatOutput,0,TESS_MAX_REQ_CURRENT);

                /*Anti-WIndup*/

                Motors[MotorIndex].SpeedCtrl.IntegralPart = IntegralPart;
            }
            else
            {

                if (Motors[MotorIndex].Requests.Voltage != UnSatOutput)
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

                Motors[MotorIndex].SpeedCtrl.Sat = DisableSat;
                Motors[MotorIndex].SpeedCtrl.IntegralPart = DisableSat*IntegralPart;
            }
         }
    }
    else
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Motors[MotorIndex].SpeedCtrl.IntegralPart = 0;
        }
    }

}

static void Tess_MotCtrl_CurrentControl(tess_act_motor_t* Motors)
{
    float Error            = 0;
    float ProportionalPart = 0;
    float IntegralPart     = 0;
    float UnSatOutput      = 0;
    uint8 MotorIndex     = 0;
    uint8 OutputSaturate = 0;
    uint8 SameSign       = 0;
    uint8 DisableSat     = 1;


    /*check if there is a need for the current controller*/
    if((Get_TessActMngControlWord() & Moc_Current)  > 0)
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Error             = Motors[MotorIndex].Requests.Current - Motors[MotorIndex].MotorInputs.Current;
            Motors[MotorIndex].CurrentCtrl.Error = Error;
            ProportionalPart  = Motors[MotorIndex].CurrentCtrl.Pgain*Error;
            Motors[MotorIndex].CurrentCtrl.ProportionalPart = ProportionalPart;
            IntegralPart      = Motors[MotorIndex].CurrentCtrl.IntegralPart + DisableSat*Error*TESS_TS;

            UnSatOutput = ProportionalPart + IntegralPart*Motors[MotorIndex].CurrentCtrl.Igain;
            Motors[MotorIndex].Requests.Voltage = Saturate(UnSatOutput,-TESS_MAX_REQ_VOLT,TESS_MAX_REQ_VOLT);
            Set_TessMocVoltageRequest(MotorIndex,Motors[MotorIndex].Requests.Voltage);
            /*Anti-WIndup*/

            if (Motors[MotorIndex].Requests.Voltage != UnSatOutput)
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

            Motors[MotorIndex].CurrentCtrl.Sat = DisableSat;
            Motors[MotorIndex].CurrentCtrl.IntegralPart = DisableSat*IntegralPart;

        }
    }else
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Motors[MotorIndex].CurrentCtrl.IntegralPart = 0;
        }
    }
}
