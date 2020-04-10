/**
  ******************************************************************************
  * File Name          : tess_bfu_pwm.c
  * Author			   : Axinte Andrei
  * Description        : Timer 1(PWM generator) module source file
  ******************************************************************************
**/
#ifdef __cplusplus
extern "C" {
#endif

/*INCLUDES*/
#include "tess_bfu_pwm.h"


void TESS_BFU_PWM_INIT()
{
   /*STM32F30 PWM peripheral should be placed here*/
   Set_TessBfuPwmDtcRight(0);
   Set_TessBfuPwmDtcLeft(0);
}

void TESS_BFU_PWM_MAIN()
{
/*
  OCR1A = ICR1 - Get_TessBfuPwmDtcRight();
  OCR1B = ICR1 - Get_TessBfuPwmDtcLeft();
  */
  TESS_2MS_COUNTER++;
}

#ifdef __cplusplus
}
#endif
