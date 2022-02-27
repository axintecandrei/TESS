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
        Motor[MotorIndex].SpeedCtrl.Pgain       = 0.229;
        Motor[MotorIndex].SpeedCtrl.Igain       = 2.68;

        Motor[MotorIndex].CurrentCtrl.Pgain     = 0.0188;
        Motor[MotorIndex].CurrentCtrl.Igain     = 377.55;

        Motor[MotorIndex].SpeedCtrl.Sat		= 1;

    }
}

void Tess_MotCtrl_Main(void)
{
    Tess_MotCtrl_SpeedControl(Motor);
    Tess_MotCtrl_CurrentControl(Motor);
}

static void Tess_MotCtrl_SpeedControl(tess_act_motor_t* Motors)
{
    float Error 					= 0;
    float ProportionalPart 			= 0;
    float UnSatOutput      			= 0;
    uint8 MotorIndex     			= 0;
    uint8 OutputSaturate 			= 0;
    uint8 SameSign       			= 0;

    if((Get_TessActMngControlWord() & Moc_Speed) > 0)
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
        	/*Limit speed request*/
        	Set_TessMocSpeedRequest(MotorIndex, Saturate(Get_TessActMngSpeedRequest(MotorIndex),-TESS_MOC_MAX_SPEED,TESS_MOC_MAX_SPEED));

        	Error                						= Get_TessMocSpeedRequest(MotorIndex) - Motors[MotorIndex].MotorInputs.MotorSpeed;
            ProportionalPart     					  	= Motors[MotorIndex].SpeedCtrl.Pgain*Error;
            Motors[MotorIndex].SpeedCtrl.IntegralPart   = Motors[MotorIndex].SpeedCtrl.IntegralPart + Motors[MotorIndex].SpeedCtrl.Sat*Error*TESS_TS;

            UnSatOutput = ProportionalPart + Motors[MotorIndex].SpeedCtrl.IntegralPart*Motors[MotorIndex].SpeedCtrl.Igain;

            Set_TessMocVoltageRequest(MotorIndex,Saturate(UnSatOutput,-(Get_TessMipDcLinkVoltage()/2),(Get_TessMipDcLinkVoltage()/2)));

            if((Get_TessActMngControlWord() & Moc_Current)  > 0)
            {
                   UnSatOutput = ProportionalPart + Motors[MotorIndex].SpeedCtrl.IntegralPart*Motors[MotorIndex].SpeedCtrl.Igain;
                   Set_TessMocCurrentRequest(MotorIndex,Saturate(UnSatOutput,0,TESS_MAX_REQ_CURRENT));
            }
            else
            {
               if (Get_TessMocVoltageRequest(MotorIndex) != UnSatOutput)
               {
                  OutputSaturate = 1;
               }

               if (OutputSaturate && SameSign)
               {
            	   Motors[MotorIndex].SpeedCtrl.Sat = 0;
               }
               else
               {
            	   Motors[MotorIndex].SpeedCtrl.Sat = 1;
               }

               Motors[MotorIndex].SpeedCtrl.IntegralPart *= Motors[MotorIndex].SpeedCtrl.Sat;

            }
            }
    }
    else
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
        	Motors[MotorIndex].SpeedCtrl.IntegralPart 	= 0;
            Set_TessMocVoltageRequest(MotorIndex,0);
        }
    }

}

static void Tess_MotCtrl_CurrentControl(tess_act_motor_t* Motors)
{
    float Error            = 0;
    float ProportionalPart = 0;
    static float IntegralPart     = 0;
    float UnSatOutput      = 0;
    uint8 MotorIndex     = 0;
    uint8 OutputSaturate = 0;
    uint8 SameSign       = 0;


    /*check if there is a need for the current controller*/
    if((Get_TessActMngControlWord() & Moc_Current)  > 0)
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            Error             = Get_TessMocCurrentRequest(MotorIndex) - Motors[MotorIndex].MotorInputs.Current;
            ProportionalPart  = Motors[MotorIndex].CurrentCtrl.Pgain*Error;

            IntegralPart      = IntegralPart + Motors[MotorIndex].CurrentCtrl.Sat*Error*TESS_TS;

            UnSatOutput = ProportionalPart + IntegralPart*Motors[MotorIndex].CurrentCtrl.Igain;

            Set_TessMocVoltageRequest(MotorIndex,Saturate(UnSatOutput,-TESS_MAX_REQ_VOLT,TESS_MAX_REQ_VOLT));

            /*Anti-WIndup*/
            if (Get_TessMocVoltageRequest(MotorIndex) != UnSatOutput)
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
            	Motors[MotorIndex].CurrentCtrl.Sat = 0;
            }
            else
            {
            	Motors[MotorIndex].CurrentCtrl.Sat = 1;
            }

            IntegralPart = Motors[MotorIndex].CurrentCtrl.Sat*IntegralPart;

        }
    }else
    {
        for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
        {
            IntegralPart = 0;
        }
    }
}
