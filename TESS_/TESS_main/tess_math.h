/**
  ******************************************************************************
  * File Name          : tess_math.h
  * Author			   : Axinte Andrei
  * Description        : Math functions file
  ******************************************************************************
**/
#ifndef __tess_math_h__
#define __tess_math_h__

#include "tess_sal_types.h"

/*DEFINES*/
#define TESS_PI_DOUBLE (float32)(3.14159265)
#define TESS_RPM2RAD  (float32)(TESS_PI_DOUBLE/30.0F)
#define Absolut_value(x) ((x < 0) ? (-x) : (x) )
#define TESS_LIM(x, l, u ) (((x) <= (l)) ? (l) : (((x) >= (u)) ? (u) : (x)) )
#define TESS_SIN16_TO_UNSIN16(x) ((unsigned_int16_t)((x) + 32768U))

signed_int32_t TESS_MAP(signed_int32_t x, signed_int32_t in_min, signed_int32_t in_max, signed_int32_t out_min, signed_int32_t out_max);


#endif /*__tess_math_h__*/

