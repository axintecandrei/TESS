/**
  ******************************************************************************
  * File Name          : tess_bfu_adc.c
  * Author			       : Axinte Andrei
  * Description        : ADC module source file
  ******************************************************************************
**/
#ifdef __cplusplus
extern "C" {
#endif

/*INCLUDES*/
#include "tess_bfu_adc.h"


void TESS_BFU_ADC_INIT()
{
   ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); // clear prescaler bits
 //ADCSRA |= bit (ADPS0) | bit (ADPS1);                 //   8 
   ADCSRA |= bit (ADPS2);                               //  16
 //ADCSRA |= bit (ADPS0) | bit (ADPS2);                 //  32 
// ADCSRA |= bit (ADPS1) | bit (ADPS2);                 //  64 
// ADCSRA |= bit (ADPS0) | bit (ADPS1) | bit (ADPS2);   // 128
   ADCSRA |= 1<<7;
}

void TESS_BFU_ADC_MAIN()
{
  
  #if CFG_TESS_ADC_1_SAMPLE
  Set_TessAdcRawCurrRight(analogRead(A2));
  Set_TessAdcRawCurrLeft(analogRead(A0));
  
  /*1 Sample motor voltage on the acording adc pin depending on the direction of motors*/
  if(TESS_MOC_MOTOR_RIGHT_DIR == FORWARD)
     Set_TessAdcRawVoltMRight(analogRead(A3));
  else if(TESS_MOC_MOTOR_RIGHT_DIR == BACKWARD)
     Set_TessAdcRawVoltMRight(analogRead(A4));
     
  if(TESS_MOC_MOTOR_LEFT_DIR == FORWARD)
     Set_TessAdcRawVoltMLeft(analogRead(A1));
  else if(TESS_MOC_MOTOR_LEFT_DIR == BACKWARD)
     Set_TessAdcRawVoltMLeft(analogRead(A5));
  #endif
  
  #if CFG_TESS_ADC_2_SAMPLE
  Set_TessAdcRawCurrRight((analogRead(A2) + analogRead(A2))>>1);
  Set_TessAdcRawCurrLeft((analogRead(A0) + analogRead(A0))>>1);
  
  /*2 Sample motor voltage on the acording adc pin depending on the direction of motors*/
  if(TESS_MOC_MOTOR_RIGHT_DIR == FORWARD)
     Set_TessAdcRawVoltMRight((analogRead(A3) + analogRead(A3))>>1);
  else if(TESS_MOC_MOTOR_RIGHT_DIR == BACKWARD)
     Set_TessAdcRawVoltMRight((analogRead(A4) + analogRead(A4))>>1);
     
  if(TESS_MOC_MOTOR_LEFT_DIR == FORWARD)
     Set_TessAdcRawVoltMLeft((analogRead(A1) + analogRead(A1))>>1);
  else if(TESS_MOC_MOTOR_LEFT_DIR == BACKWARD)
     Set_TessAdcRawVoltMLeft((analogRead(A5) + analogRead(A5))>>1);
  #endif

#if CFG_TESS_ADC_3_SAMPLE
   Set_TessAdcRawCurrRight((analogRead(A0) + analogRead(A0)+ analogRead(A0))/3);
   Set_TessAdcRawCurrLeft((analogRead(A1) + analogRead(A1)+ analogRead(A1))/3);
  
   /*3 Sample motor voltage on the acording adc pin depending on the direction of motors*/
   if(TESS_MOC_MOTOR_RIGHT_DIR == FORWARD)
   {
      Set_TessAdcRawVoltMRight((analogRead(A2) + analogRead(A2)+ analogRead(A2))/3);
   }
   else if(TESS_MOC_MOTOR_RIGHT_DIR == BACKWARD)
   {
     Set_TessAdcRawVoltMRight((analogRead(A3) + analogRead(A3)+ analogRead(A3))/3);
   }

   if(TESS_MOC_MOTOR_LEFT_DIR == FORWARD)
   {
      Set_TessAdcRawVoltMLeft((analogRead(A4) + analogRead(A4)+ analogRead(A4))/3);
   }
   else if(TESS_MOC_MOTOR_LEFT_DIR == BACKWARD)
   {
      Set_TessAdcRawVoltMLeft((analogRead(A5) + analogRead(A5)+ analogRead(A5))/3);
   }
#endif

#if CFG_TESS_MIP_SENSORED
   Set_TessAdcRawLeftBemfU(analogRead(A2));
   Set_TessAdcRawLeftBemfV(analogRead(A3));
#endif
}

#ifdef __cplusplus
}
#endif




