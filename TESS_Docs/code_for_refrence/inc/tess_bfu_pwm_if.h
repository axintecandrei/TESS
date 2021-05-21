/**
  ******************************************************************************
  * File Name          : tess_bfu_pwm_if.h
  * Author			   : Axinte Andrei
  * Description        : Timer 1(PWM generator) module interface header file
  ******************************************************************************
**/
#ifndef __tess_bfu_pwm_if_h__
#define __tess_bfu_pwm_if_h__

/*INLCUDES*/

#include "tess_bfu_io.h"
#include "tess_sal_types.h"

/*VARIABLES*/

unsigned_int16_t PORT__TessBfuPwmDtcRight;

unsigned_int16_t PORT__TessBfuPwmDtcLeft;

#define Set_TessBfuPwmDtcRight(x) (PORT__TessBfuPwmDtcRight = (x))
#define Get_TessBfuPwmDtcRight()   (*((const unsigned_int16_t *) &PORT__TessBfuPwmDtcRight))


#define Set_TessBfuPwmDtcLeft(x) (PORT__TessBfuPwmDtcLeft = (x))
#define Get_TessBfuPwmDtcLeft()   (*((const unsigned_int16_t *) &PORT__TessBfuPwmDtcLeft))

/*FUNCTIONS*/

extern void TESS_BFU_PWM_INIT();

extern void TESS_BFU_PWM_MAIN();

#endif /*__tess_bfu_pwm_if_h__*/
