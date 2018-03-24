/**
  ******************************************************************************
  * File Name          : tess_ring_buffer.c
  * Author			   : Axinte Andrei
  * Description        : Ring buffer module interface source file
  ******************************************************************************
**/
#include "tess_ring_buffer.h"


static unsigned_char_t TESS_RING_BUFFER_FULL(ring_buffer_t *rb);
static unsigned_char_t TESS_RING_BUFFER_EMPTY(ring_buffer_t *rb);

void TESS_RING_BUFFER_INIT(void)
{
   /* Initialize the ring buffer internal variables */
   TESS_RING_BUFFER.HEAD = 0;
   TESS_RING_BUFFER.TAIL = 0;
   TESS_RING_BUFFER.COUNTER = 0;
   TESS_RING_BUFFER.INNER_COUNTER = 0;
   TESS_RING_BUFFER.BUFFER = RING_BUFFER_MEM;
}

signed_char_t TESS_RING_BUFFER_PUT(const void *data)
{
   signed_char_t err = 0;

   if ((TESS_RING_BUFFER_FULL(&TESS_RING_BUFFER) == 0)) 
   {
      TESS_RING_BUFFER.BUFFER[TESS_RING_BUFFER.HEAD++] = &data;
	  TESS_RING_BUFFER.COUNTER++;
	  
	  if(TESS_RING_BUFFER.COUNTER > MAX_ELEM)
	  {
		  TESS_RING_BUFFER.COUNTER = 0;
	  }
	  else
	  {
          err = 0;
	  }
   } 
   else 
   {
       err = -1;
   }

    return err;
}

signed_char_t TESS_RING_BUFFER_GET(void *data)
{
   signed_char_t stat = 0;

   if ((TESS_RING_BUFFER_EMPTY(&TESS_RING_BUFFER) == 0)) 
   {
	   &data = TESS_RING_BUFFER.BUFFER[TESS_RING_BUFFER.TAIL][TESS_RING_BUFFER.INNER_COUNTER++];
	   
	   if (TESS_RING_BUFFER.INNER_COUNTER >= (ACQ_BUFFER_SIZE + 2))
	   {	
          TESS_RING_BUFFER.INNER_COUNTER = 0;
		      stat = 4;
	   }
	   else
	   {
		   stat = 5; /*busy*/
	   }
	   
	   if (TESS_RING_BUFFER.INNER_COUNTER == 0)
	   {
		   TESS_RING_BUFFER.TAIL++;
	   }
	   else
	   {
	      /* do nothing */
	   }
   }
   else 
   {
       stat = -1;
   }

    return stat;
}

static unsigned_char_t TESS_RING_BUFFER_FULL(ring_buffer_t *rb)
{
    return ((rb->COUNTER) == MAX_ELEM) ? 1 : 0;
}

static unsigned_char_t TESS_RING_BUFFER_EMPTY(ring_buffer_t *rb)
{
    return ((rb->COUNTER) == 0U) ? 1 : 0;
}

