/**
  ******************************************************************************
  * File Name          : tess_mip_currvoltproc.h
  * Author			   : Axinte Andrei
  * Description        : Current And voltace procesing module header file
  ******************************************************************************
**/
#ifndef __tess_mip_currvoltproc_h__
#define __tess_mip_currvoltproc_h__


/*INCLUDES*/

#include "tess_mip_currvoltproc_if.h"

/*DEFINES*/
#define CURR_VOLT_RES    (unsigned_int16_t)(5000/1024) /*ADC value to Volt/Amp*/
#define VOLT_GAIN_INV    (unsigned_char_t)(2)          /*Voltage dividor factor*/
#define CURR_GAIN        (unsigned_char_t)(2)          /*R shunt invers value 1/(1/2)Ohm */

/*VARIABLES*/



#endif /*__tess_mip_currvoltproc_h__*/
