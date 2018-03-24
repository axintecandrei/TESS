/**
  ******************************************************************************
  * File Name          : tess_bfu_pwm.h
  * Author			   : Axinte Andrei
  * Description        : Timer 1(PWM generator) module header file
  ******************************************************************************
**/
#ifndef __tess_bfu_pwm_h__
#define __tess_bfu_pwm_h__

/*INCLUDES*/
#include "tess_bfu_pwm_if.h"

/*DEFINES*/
#define COM1A(x) (((x)&3)<<6) 
#define COM1B(x) (((x)&3)<<4)
#define WGMA(x)  (((x)&3))
#define WGMB(x)  (((x)&3)<<3)
#define CS(x)    (((x)&7))
#define IC(x)    (((x)&3)<<6)



/*VARIABLES*/
unsigned_int32_t TESS_2MS_COUNTER;


#endif /*__tess_bfu_pwm_h__*/
