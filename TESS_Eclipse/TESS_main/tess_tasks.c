/**
  ******************************************************************************
  * File Name          : tess_tasks.c
  * Author			       : Axinte Andrei
  * Description        : Main functions source file
  ******************************************************************************
**/
#ifdef __cplusplus
extern "C" {
#endif


/*INCLUDES*/
#include "tess_tasks.h"

void MAIN_2MS_LOOP (void)
{
   TESS_BFU_ADC_MAIN();
   TESS_MIP_CURRVOLTPROC_MAIN();
   TESS_MIP_BEMFEST_MAIN();
   TESS_MIP_MOTOR_TORQUE_CALC_MAIN();
   TESS_MOC_SPEEDCURRCTRL_MAIN();
   TESS_BFU_PWM_MAIN();
#if CFG_ACQ_ON
   if(TESS_START_ACQ == 1)
   {
   TESS_DATA_ACQ_OUTPUT_FILL_BUFFER(TESS_DATA_ACQ_BUFFER);
   TESS_BFU_UART_PACK_ACQ_MSG(TESS_DATA_ACQ_BUFFER, &TESS_TO_RING_BUFFER);
   TESS_RING_BUFFER_PUT(&TESS_RING_BUFFER, TESS_TO_RING_BUFFER);
   TESS_BFU_UART_PUT(TESS_RING_BUFFER_GET(&TESS_RING_BUFFER));
   }
   else
   {
	   /*do nothing*/
   }
#endif
}

void MAIN_10MS_LOOP (void)
{ 

}


#ifdef __cplusplus
}
#endif
