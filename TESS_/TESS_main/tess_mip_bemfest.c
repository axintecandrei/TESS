/**
  ******************************************************************************
  * File Name          : tess_mip_bemfobs.c
  * Author			       : Axinte Andrei
  * Description        : B-emf and speed estimator module module source file
  ******************************************************************************
**/

#ifdef __cplusplus
extern "C" {
#endif

/*INCLUDES*/
#include "tess_mip_bemfest.h"


void TESS_MIP_BEMFEST_INIT()
{
  Set_TessMipBemfLeftM(0);
  Set_TessMipBemfRightM(0);
  TESS_MIP_BEMFEST_CURRLEFT_K1  = Get_TessMipCurrLeft();
  TESS_MIP_BEMFEST_CURRRIGHT_K1 = Get_TessMipCurrRight();
}

void TESS_MIP_BEMFEST_MAIN()
{
#if !CFG_TESS_MIP_SENSORED
   unsigned_int16_t temp16;
   
   temp16 = (Get_TessMipCurrRight()  - TESS_MIP_BEMFEST_CURRRIGHT_K1)/Ts;    /*di/dt*/
   temp16 = Get_TessMipVoltMRight() - Get_TessMipCurrRight()*RESISTANCE - (unsigned_int16_t)((unsigned_int32_t)(temp16*INDUCTANCE)/1000000);

   Set_TessMipBemfRightM(temp16);
   if(TESS_MOC_MOTOR_RIGHT_DIR == FORWARD)
   {
      Set_TessMipEstSpeedRightM((Get_TessMipBemfRightM() * BEMF_CONST));
   }
   else if(TESS_MOC_MOTOR_RIGHT_DIR == BACKWARD)
   {
	   Set_TessMipEstSpeedRightM((Get_TessMipBemfRightM() * BEMF_CONST));
   }

   temp16 = (Get_TessMipCurrLeft() - TESS_MIP_BEMFEST_CURRLEFT_K1)/Ts;    /*di/dt*/
   temp16 = Get_TessMipVoltMLeft() - Get_TessMipCurrLeft()*RESISTANCE - (unsigned_int16_t)((unsigned_int32_t)(temp16*INDUCTANCE)/1000000);


   Set_TessMipBemfLeftM(temp16);

   if(TESS_MOC_MOTOR_LEFT_DIR == FORWARD)
   {
	   Set_TessMipEstSpeedLeftM(Get_TessMipBemfLeftM() * BEMF_CONST);
   }
   else if(TESS_MOC_MOTOR_LEFT_DIR == BACKWARD)
   {
	   Set_TessMipEstSpeedLeftM((-1)*(Get_TessMipBemfLeftM() * BEMF_CONST));
   }
   /*regression*/
   TESS_MIP_BEMFEST_CURRLEFT_K1  = Get_TessMipCurrLeft();
   TESS_MIP_BEMFEST_CURRRIGHT_K1 = Get_TessMipCurrRight();
#endif
   signed_int16_t loc_bemf_u;
   signed_int16_t loc_bemf_v;
   signed_int16_t loc_bemf_w;

   loc_bemf_u = Get_TessAdcRawLeftBemfU() - 512;
   Set_TessMipCalcBemfU(loc_bemf_u);

   loc_bemf_v = Get_TessAdcRawLeftBemfV() - 512;
   Set_TessMipCalcBemfV(loc_bemf_v);

   loc_bemf_w = 0 - loc_bemf_u - loc_bemf_v;

   Set_TessMipCalcBemfW(loc_bemf_w);
}


#ifdef __cplusplus
}
#endif
