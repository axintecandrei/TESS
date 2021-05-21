/**
  ******************************************************************************
  * File Name          : tess_mip_currvoltproc_if.h
  * Author			   : Axinte Andrei
  * Description        : Current And voltace procesing module interface header file
  ******************************************************************************
**/
#ifndef __tess_mip_currvoltproc_if_h__
#define __tess_mip_currvoltproc_if_h__

/*INLCUDES*/

#include "tess_bfu_io.h"
#include "tess_sal_types.h"
#include "tess_bfu_adc.h"

/*VARIABLES*/
unsigned_int16_t PORT__TessMipCurrRight;

unsigned_int16_t PORT__TessMipCurrLeft;

unsigned_int16_t PORT__TessMipVoltMRight;
                           
unsigned_int16_t PORT__TessMipVoltMLeft;

#define Set_TessMipCurrRight(x) (PORT__TessMipCurrRight = (x))
#define Get_TessMipCurrRight()   (*((const unsigned_int16_t *) &PORT__TessMipCurrRight))

#define Set_TessMipCurrLeft(x) (PORT__TessMipCurrLeft = (x))
#define Get_TessMipCurrLeft()   (*((const unsigned_int16_t *) &PORT__TessMipCurrLeft))

#define Set_TessMipVoltMRight(x) (PORT__TessMipVoltMRight = (x))
#define Get_TessMipVoltMRight()   (*((const unsigned_int16_t *) &PORT__TessMipVoltMRight))

#define Set_TessMipVoltMLeft(x) (PORT__TessMipVoltMLeft = (x))
#define Get_TessMipVoltMLeft()   (*((const unsigned_int16_t *) &PORT__TessMipVoltMLeft))

/*FUNCTIONS*/

extern void TESS_MIP_CURRVOLTPROC_INIT();

extern void TESS_MIP_CURRVOLTPROC_MAIN();

#endif /*__tess_mip_currvoltproc_if_h__*/
