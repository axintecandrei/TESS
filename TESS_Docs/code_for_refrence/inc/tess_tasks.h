/**
  ******************************************************************************
  * File Name          : tess_tasks.h
  * Author			       : Axinte Andrei
  * Description        : Main functions header file
  ******************************************************************************
**/
#ifndef __tess_tasks_h__
#define __tess_tasks_h__

/*INCLUDES*/
#include "tess_sal_types.h"
#include "tess_bfu_io.h"
#include "tess_bfu_pwm.h"
#include "tess_bfu_adc.h"
#include "tess_bfu_uart.h"
#include "tess_mip_bemfest.h"
#include "tess_mip_trqcalc.h"



/*FUNCTIONS*/

extern void MAIN_2MS_LOOP (void);

extern void MAIN_10MS_LOOP (void);


#endif /*__tess_tasks_h__*/
