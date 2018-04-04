/**
  ******************************************************************************
  * File Name          : tess_mip_bemfest_if.h
  * Author			       : Axinte Andrei
  * Description        : B-emf and speed estimator module interface header file
  ******************************************************************************
**/
#ifndef __tess_mip_bemfest_if_h__
#define __tess_mip_bemfest_if_h__

/*INLCUDES*/
#include "tess_mip_currvoltproc.h"
#include "tess_sal_types.h"

/*VARIABLES*/
unsigned_int16_t PORT__TessMipBemfLeftM;

#define Set_TessMipBemfLeftM(x) (PORT__TessMipBemfLeftM = (x))
#define Get_TessMipBemfLeftM()   (*((const unsigned_int16_t *) &PORT__TessMipBemfLeftM))

unsigned_int16_t PORT__TessMipBemfRightM;

#define Set_TessMipBemfRightM(x) (PORT__TessMipBemfRightM = (x))
#define Get_TessMipBemfRightM()   (*((const unsigned_int16_t *) &PORT__TessMipBemfRightM))

signed_int32_t PORT__TessMipEstSpeedRightM;

#define Set_TessMipEstSpeedRightM(x) (PORT__TessMipEstSpeedRightM = (x))
#define Get_TessMipEstSpeedRightM()   (*((const signed_int32_t *) &PORT__TessMipEstSpeedRightM))

signed_int32_t PORT__TessMipEstSpeedLeftM;

#define Set_TessMipEstSpeedLeftM(x) (PORT__TessMipEstSpeedLeftM = (x))
#define Get_TessMipEstSpeedLeftM()   (*((const signed_int32_t *) &PORT__TessMipEstSpeedLeftM))

signed_int32_t PORT__TessMipCalcBemfU;

#define Set_TessMipCalcBemfU(x) (PORT__TessMipCalcBemfU = (x))
#define Get_TessMipCalcBemfU()   (*((const signed_int32_t *) &PORT__TessMipCalcBemfU))

signed_int32_t PORT__TessMipCalcBemfV;

#define Set_TessMipCalcBemfV(x) (PORT__TessMipCalcBemfV = (x))
#define Get_TessMipCalcBemfV()   (*((const signed_int32_t *) &PORT__TessMipCalcBemfV))

signed_int32_t PORT__TessMipCalcBemfW;

#define Set_TessMipCalcBemfW(x) (PORT__TessMipCalcBemfW = (x))
#define Get_TessMipCalcBemfW()   (*((const signed_int32_t *) &PORT__TessMipCalcBemfW))


/*FUNCTIONS*/

extern void TESS_MIP_BEMFEST_INIT();

extern void TESS_MIP_BEMFEST_MAIN();

#endif /*__tess_mip_bemfest_if_h__*/
