/**
  ******************************************************************************
  * File Name          : tess_mip_currvoltproc.c
  * Author			       : Axinte Andrei
  * Description        : Current And voltace procesing module source file
  ******************************************************************************
**/

#ifdef __cplusplus
extern "C" {
#endif


/*INCLUDES*/
#include "tess_mip_currvoltproc.h"


void TESS_MIP_CURRVOLTPROC_INIT()
{
   Set_TessMipCurrRight(0);
   Set_TessMipCurrLeft(0);
   Set_TessMipVoltMRight(0);
   Set_TessMipVoltMLeft(0);
}

void TESS_MIP_CURRVOLTPROC_MAIN()
{
   unsigned_int16_t temp16;

   temp16 = Get_TessAdcRawCurrRight()*CURR_VOLT_RES*CURR_GAIN;
   Set_TessMipCurrRight(temp16);

   temp16 = Get_TessAdcRawCurrRight()*CURR_VOLT_RES*CURR_GAIN;
   Set_TessMipCurrLeft(temp16);
#if !CFG_TESS_MIP_SENSORED
   temp16 = Get_TessAdcRawVoltMRight()*CURR_VOLT_RES*VOLT_GAIN_INV;
   Set_TessMipVoltMRight(temp16);

   temp16 = Get_TessAdcRawVoltMLeft()*CURR_VOLT_RES*VOLT_GAIN_INV;
   Set_TessMipVoltMLeft(temp16);
#endif
}

#ifdef __cplusplus
}
#endif
