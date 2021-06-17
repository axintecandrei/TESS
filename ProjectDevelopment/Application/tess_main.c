/*
 * tess_main.c
 *
 *  Created on: Jun 17, 2021
 *      Author: nxf70809
 */
#include "tess_main.h"





uint8_t PWM_DTC;


uint32_t ADC_CLBK;
float    MotorCurrentM1;
float    MotorCurrentM2;
float    MotorCurrentM3;
float    MotorCurrentM4;
float    MotorVoltageM1;
float    MotorVoltageM2;
float    MotorVoltageM3;
float    MotorVoltageM4;
float    DcLink;

void TessMain(void)
{
    ADC_CLBK++;
    MotorCurrentM1 = ADC_VALUE[0];
    MotorCurrentM1 /= 0.46F;
    MotorCurrentM2 = ADC_VALUE[1];
    MotorCurrentM2 /= 0.46F;
    MotorCurrentM3 = ADC_VALUE[2];
    MotorCurrentM3 /= 0.46F;
    MotorCurrentM4 = ADC_VALUE[4];
    MotorCurrentM4 /= 0.46F;

    DcLink         = ADC_VALUE[3]*3;
    MotorVoltageM1 = (DcLink*PwmInputM1*0.01F) - (DcLink*0.5F);
    MotorVoltageM2 = (DcLink*PwmInputM2*0.01F) - (DcLink*0.5F);
    MotorVoltageM3 = (DcLink*PwmInputM3*0.01F) - (DcLink*0.5F);
    MotorVoltageM4 = (DcLink*PwmInputM4*0.01F) - (DcLink*0.5F);
    /*M1*/
    TIM1->CCR3 = ((float)PWM_DTC/100.0F)*htim1.Init.Period;
    TIM1->CCR4 = htim1.Init.Period - TIM1->CCR3;
    /*M2*/
    TIM1->CCR1 = ((float)PWM_DTC/100.0F)*htim1.Init.Period;
    TIM1->CCR2 = htim1.Init.Period - TIM1->CCR1;
    /*M3*/
    TIM8->CCR1 = ((float)PWM_DTC/100.0F)*htim8.Init.Period;
    TIM8->CCR2 = htim1.Init.Period - TIM8->CCR1;
    /*M4*/
    TIM8->CCR3 = ((float)PWM_DTC/100.0F)*htim8.Init.Period;
    TIM8->CCR4 = htim1.Init.Period - TIM8->CCR3;

    #if(!FMSTR_DISABLE)
        {
          FMSTR_Poll();
          FMSTR_Recorder();
        }
    #endif
}


void TessMainInit(void)
{
    PWM_DTC=50;

#if !FMSTR_DISABLE
    FMSTR_Init();
#endif
}
