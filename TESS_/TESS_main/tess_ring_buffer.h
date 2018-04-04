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

#if CFG_ACQ_ON

#define RBUF_SIZE                               64
#define Benchalign_buffer_overwrite             0x0001
#define Benchaling_buffer_concurent_write_read  0x0002
#define Buff_lock_none                          ((unsigned_char_t)0x00)
#define Buff_lock_read                          ((unsigned_char_t)0x01)
#define Buff_lock_write                         ((unsigned_char_t)0x02)

typedef struct
{
   unsigned_char_t byte0;  
   unsigned_char_t byte1;  
   unsigned_char_t byte2;  
   unsigned_char_t byte3;  
   unsigned_char_t byte4;  
   unsigned_char_t byte5;  
   unsigned_char_t byte6;  
   unsigned_char_t byte7;  
   unsigned_char_t byte8;  
   unsigned_char_t byte9;  
   unsigned_char_t byte10; 
   unsigned_char_t byte11; 
   unsigned_char_t byte12;
   unsigned_char_t byte13; 
   unsigned_char_t byte14; 
   unsigned_char_t byte15; 
   unsigned_char_t byte16;
   unsigned_char_t byte17;
   unsigned_char_t byte18;
   unsigned_char_t byte19;
   unsigned_char_t byte20;
   unsigned_char_t byte21;
   unsigned_char_t byte22;
   unsigned_char_t byte23;
   unsigned_char_t byte24;
   unsigned_char_t byte25;
}r_buff_data_t;


typedef struct
{
   unsigned_char_t head; 
   unsigned_char_t tail; 
   unsigned_char_t count;
   unsigned_char_t inner_count;
   unsigned_char_t buffer_acces;
   unsigned_char_t buffer_flags;
   r_buff_data_t buff_data[RBUF_SIZE];
	
}ring_buffer_t;

r_buff_data_t TESS_RING_BUFFER_DATA;
r_buff_data_t TESS_TO_RING_BUFFER;
ring_buffer_t TESS_RING_BUFFER;

extern void TESS_RING_BUFFER_INIT(ring_buffer_t * buff);

extern unsigned_char_t TESS_RING_BUFFER_GET(ring_buffer_t * buff);

extern void TESS_RING_BUFFER_PUT(ring_buffer_t * buff, r_buff_data_t data);

extern unsigned_char_t TESS_RINGBUFF_IS_EMPTY( const ring_buffer_t * buff);

#endif /*CFG_ACQ_ON*/
#endif /* __tess_ring_buffer_h__ */
