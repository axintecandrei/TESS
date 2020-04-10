/**
  ******************************************************************************
  * File Name          : tess_mip_trqcalc.c
  * Author			   : Axinte Andrei
  * Description        : Motors Torque calculation module interface header file
  ******************************************************************************
**/
#ifdef __cplusplus
extern "C" {
#endif

/*INCLUDES*/
#include "tess_mip_trqcalc.h"


void TESS_MIP_MOTOR_TORQUE_CALC_INIT()
{
	Set_TessMipMotTrqRight(0);
	Set_TessMipMotTrqLeft(0);
}

void TESS_MIP_MOTOR_TORQUE_CALC_MAIN()
{

   unsigned_int32_t temp32;

   temp32 = Get_TessMipCurrRight() * TRQ_CST;
   Set_TessMipMotTrqRight(temp32);

   temp32 = Get_TessMipCurrLeft() * TRQ_CST;
   Set_TessMipMotTrqLeft(temp32);

}

#ifdef __cplusplus
}
#endif




