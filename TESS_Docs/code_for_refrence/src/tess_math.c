/**
  ******************************************************************************
  * File Name          : tess_bfu_io.c
  * Author			       : Axinte Andrei
  * Description        : IO pin mode setting source file
  ******************************************************************************
**/

#ifdef __cplusplus
extern "C" {
#endif

/*INCLUDES*/
#include "tess_math.h"




signed_int32_t TESS_MAP(signed_int32_t x, signed_int32_t in_min, signed_int32_t in_max, signed_int32_t out_min, signed_int32_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

#ifdef __cplusplus
}
#endif
