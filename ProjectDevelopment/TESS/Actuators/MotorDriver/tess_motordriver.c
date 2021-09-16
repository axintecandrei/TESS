/*
 * tess_motordriver.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#include "tess_motordriver.h"

static uint16_t Tess_DtcToPwmTick(float Dtc,float MaxPwmTick);

void Tess_MotDrv_Init()
{

}

void Tess_MotDrv_SetMotorsPwm(float M1Pwm, float M2Pwm, float M3Pwm, float M4Pwm)
{
    if((MotCtrlStateMachine.ControlWord & Moc_Pwm)  > 0)
    {
        htim1.Instance->CCR3 = Tess_DtcToPwmTick(M1Pwm,htim1.Init.Period);
        htim1.Instance->CCR4 = htim1.Init.Period - htim1.Instance->CCR3;
        htim1.Instance->CCR1 = Tess_DtcToPwmTick(M2Pwm,htim1.Init.Period);
        htim1.Instance->CCR2 = htim1.Init.Period- htim1.Instance->CCR1;
        htim8.Instance->CCR1 = Tess_DtcToPwmTick(M3Pwm,htim8.Init.Period);
        htim8.Instance->CCR2 = htim8.Init.Period- htim8.Instance->CCR1;
        htim8.Instance->CCR3 = Tess_DtcToPwmTick(M4Pwm,htim8.Init.Period);
        htim8.Instance->CCR4 = htim8.Init.Period - htim8.Instance->CCR3;
    }
    else
    {
        htim1.Instance->CCR3 = htim1.Init.Period*0.5;
        htim1.Instance->CCR4 = htim1.Init.Period - htim1.Instance->CCR3;
        htim1.Instance->CCR1 = htim1.Init.Period*0.5;
        htim1.Instance->CCR2 = htim1.Init.Period - htim1.Instance->CCR1;
        htim8.Instance->CCR1 = htim8.Init.Period*0.5;
        htim8.Instance->CCR2 = htim8.Init.Period - htim8.Instance->CCR1;
        htim8.Instance->CCR3 = htim8.Init.Period*0.5;
        htim8.Instance->CCR4 = htim8.Init.Period - htim8.Instance->CCR3;
    }


}

static uint16_t Tess_DtcToPwmTick(float Dtc,float MaxPwmTick)
{

    return Dtc*MaxPwmTick;
}
