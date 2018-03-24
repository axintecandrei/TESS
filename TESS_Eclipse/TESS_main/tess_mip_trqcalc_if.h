/**
  ******************************************************************************
  * File Name          : tess_mip_trqcalc_if.h
  * Author			   : Axinte Andrei
  * Description        : Motors Torque calculation module interface header file
  ******************************************************************************
**/
#ifndef __tess_mip_trqcalc_if_h__
#define __tess_mip_trqcalc_if_h__

#include "Arduino.h"
#include "tess_sal_types.h"
#include "tess_conf.h"
#include "tess_mip_currvoltproc.h"

/*PORTS*/
unsigned_int32_t PORT__TessMipMotTrqRight;

#define Set_TessMipMotTrqRight(x) (PORT__TessMipMotTrqRight = (x))
#define Get_TessMipMotTrqRight()   (*((const unsigned_int32_t *) &PORT__TessMipMotTrqRight))

unsigned_int32_t PORT__TessMipMotTrqLeft;

#define Set_TessMipMotTrqLeft(x) (PORT__TessMipMotTrqLeft = (x))
#define Get_TessMipMotTrqLeft()   (*((const unsigned_int32_t *) &PORT__TessMipMotTrqLeft))


/*FUNCTIONS*/
extern void TESS_MIP_MOTOR_TORQUE_CALC_INIT();

extern void TESS_MIP_MOTOR_TORQUE_CALC_MAIN();

#endif /*__tess_mip_trqcalc_if_h__*/

