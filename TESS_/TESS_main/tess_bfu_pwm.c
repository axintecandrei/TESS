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
   //SREG |= (0<<7); 						 /*disable global interrupts*/
   PIN_MODE(DDRB,1,OUT);                     /* set pins as outputs */
   PIN_MODE(DDRB,2,OUT);
   TCCR1A = COM1A(3) | COM1B(3) | WGMA(2);   /* non-inverting PWM *//* mode 10: fast PWM, TOP=ICR1 */
   TCCR1B = IC(0) | WGMB(2) | CS(1) ;        /* prescaler 1 */
   ICR1 = 16000000/(2*500);                  /* pwm freq 500hz*/
   TIMSK1 = 0x01;							 /* Enable timer interrupt on overflow*/
   SREG |= 1<<7; 						     /* enable global interrupts*/
   TESS_2MS_COUNTER=0;
   OCR1A = 0;
   OCR1B = 0;

   Set_TessBfuPwmDtcRight(0);
   Set_TessBfuPwmDtcLeft(0);
}

void TESS_BFU_PWM_MAIN()
{
  OCR1A = ICR1 - Get_TessBfuPwmDtcRight();
  OCR1B = ICR1 - Get_TessBfuPwmDtcLeft();
  TESS_2MS_COUNTER++;
}

#ifdef __cplusplus
}
#endif
