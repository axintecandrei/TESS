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
#include "tess_data_acq_output.h"

#if CFG_ACQ_ON

#include "tess_mip_bemfest_if.h"
#include "tess_mip_currvoltproc_if.h"
#include "tess_bfu_pwm.h"


void TESS_DATA_ACQ_OUTPUT_FILL_BUFFER(unsigned_char_t* out_buffer)
{

   unsigned_int16_t temp16;

   out_buffer[0] = TESS_2MS_COUNTER;
   out_buffer[1] = TESS_2MS_COUNTER>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(Get_TessAdcRawLeftBemfU());
   out_buffer[2] = temp16;
   out_buffer[3] = temp16>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(TESS_MOC_CURRCTRL_LEFTMOTOR.OUTPUT_VOLTAGE*1000);
   out_buffer[4] = temp16;
   out_buffer[5] = temp16>>8;
   out_buffer[6] = Get_TessMipCurrLeft();
   out_buffer[7] = Get_TessMipCurrLeft()>>8;
   out_buffer[8] = Get_TessBfuPwmDtcRight();
   out_buffer[9] = Get_TessBfuPwmDtcRight()>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(Get_TessMipCalcBemfU());
   out_buffer[10] = temp16;
   out_buffer[11] = temp16>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(Get_TessMipCalcBemfV());
   out_buffer[12] = temp16;
   out_buffer[13] = temp16>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(Get_TessMipCalcBemfW());
   out_buffer[14] = temp16;
   out_buffer[15] = temp16>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(TESS_MOC_SPEEDCTRL_LEFTMOTOR.ERROR_SPEED);
   out_buffer[16] = temp16;
   out_buffer[17] = temp16>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(TESS_MOC_SPEEDCTRL_LEFTMOTOR.P_PART*1000);
   out_buffer[18] = temp16;
   out_buffer[19] = temp16>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(Get_TessStateMachReqSpeed());
   out_buffer[20] = temp16;
   out_buffer[21] = temp16>>8;
   temp16 = TESS_SIN16_TO_UNSIN16(Get_TessAdcRawLeftBemfV());
   out_buffer[22] = temp16;
   out_buffer[23] = temp16>>8;
}

#endif
#ifdef __cplusplus
}
#endif

