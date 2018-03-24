/**
  ******************************************************************************
  * File Name          : tess_bfu_io.h
  * Author			   : Axinte Andrei
  * Description        : IO pin mode setting header file
  ******************************************************************************
**/
#ifndef __tess_bfu_io_h__
#define __tess_bfu_io_h__

#include "Arduino.h"
#include "tess_sal_types.h"
/*DEFINES*/
#define IN 0
#define OUT 1
#define OFF 0
#define ON 1
#define PIN_MODE(reg, pin, mode) (reg |= ((mode)<<(pin)))


#define LEFT_F  PD5  /*PD5*/
#define LEFT_B  PD4  /*PD4*/ 
#define RIGHT_F PD2  /*PD2*/
#define RIGHT_B PD3  /*PD3*/ 


/*FUNCTIONS*/
extern void TESS_BFU_IO_INIT();

extern void TESS_IO_PIN_WRITE(volatile unsigned_char_t *reg ,unsigned_char_t pin, unsigned_char_t val); 
#endif /*__tess_bfu_io_h__*/

