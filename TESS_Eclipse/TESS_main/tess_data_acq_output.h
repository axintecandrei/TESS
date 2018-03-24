/**
  ******************************************************************************
  * File Name          : tess_data_acq_output.h
  * Author			   : Axinte Andrei
  * Description        : IO pin mode setting header file
  ******************************************************************************
**/
#ifndef __tess_data_acq_output_h__
#define __tess_data_acq_output_h__

#include "Arduino.h"
#include "tess_sal_types.h"
#include "tess_conf.h"
#include "tess_math.h"

#if CFG_ACQ_ON

/*DEFINES*/
#define ACQ_BUFFER_SIZE 24

/*VARIABLES*/
unsigned_char_t TESS_DATA_ACQ_BUFFER[ACQ_BUFFER_SIZE];

/*FUNCTIONS*/

extern void TESS_DATA_ACQ_OUTPUT_FILL_BUFFER(unsigned_char_t* out_buffer); 

#endif /*CFG_ACQ_ON*/
#endif /*__tess_data_acq_output_h__*/

