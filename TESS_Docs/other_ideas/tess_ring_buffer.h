/**
  ******************************************************************************
  * File Name          : tess_ring_buffer.h
  * Author			   : Axinte Andrei
  * Description        : Ring buffer module header file
  ******************************************************************************
**/
#ifndef __tess_ring_buffer_h__
#define __tess_ring_buffer_h__

#include "tess_ring_buffer_if.h"

/*DEFINES*/
#define MAX_ELEM         255

typedef struct
{
	volatile unsigned_char_t  HEAD;
	volatile unsigned_char_t  TAIL;
	volatile unsigned_int16_t COUNTER;
	         unsigned_int16_t INNER_COUNTER;
           unsigned_char_t **BUFFER;
}ring_buffer_t;

typedef unsigned_int16_t ring_buffer_descriptor_t; /* Ring buffer descriptor */

/*VARIABLES*/
unsigned_char_t RING_BUFFER_MEM[MAX_ELEM][ACQ_BUFFER_SIZE + 2];
static ring_buffer_t TESS_RING_BUFFER;

#endif /* __tess_ring_buffer_h__ */
