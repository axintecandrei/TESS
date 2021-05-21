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
#include "tess_bfu_io.h"


void TESS_BFU_IO_INIT()
{
#if 0
   PIN_MODE(DDRD,RIGHT_F,OUT);                  /* set pins as outputs */
   PIN_MODE(DDRD,RIGHT_B,OUT);
   PIN_MODE(DDRD,LEFT_F ,OUT);
   PIN_MODE(DDRD,LEFT_B ,OUT);

   TESS_IO_PIN_WRITE(&PORTD,RIGHT_F,OFF);
   TESS_IO_PIN_WRITE(&PORTD,RIGHT_B,OFF);
   TESS_IO_PIN_WRITE(&PORTD,LEFT_F ,OFF);
   TESS_IO_PIN_WRITE(&PORTD,LEFT_B ,OFF);  
#endif
}

void TESS_IO_PIN_WRITE(volatile unsigned_char_t *reg , unsigned_char_t pin, unsigned_char_t val)
{
	//uint8_t oldSREG = SREG;


	if (val == 0) {
		//*reg &= ~(val<<pin);
		*reg |= (val<<pin);
	} else {
		*reg |= (val<<pin);
	}

	//SREG = oldSREG;
}

#ifdef __cplusplus
}
#endif
