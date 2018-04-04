/**
  ******************************************************************************
  * File Name          : tess_bfu_uart.c
  * Author			       : Axinte Andrei
  * Description        : UART module source file
  ******************************************************************************
**/
#ifdef __cplusplus
extern "C" {
#endif

/*INCLUDES*/
#include "tess_bfu_uart.h"


void TESS_BFU_UART_INIT()
{
   SREG |= (0<<7);                            /*disable global interrupts*/ 
   UBRR0H = USART_BAUDRATE >> 8;
   UBRR0L = USART_BAUDRATE & 0xff;
   
   UCSR0B = (1<<7) | (1<<6) |(0<<5) |(1<<4) |(1<<3) |(0<<2) |(0<<1) |(0);  
   UCSR0C = (0<<7) | (0<<6) |(0<<5) |(0<<4) |(0<<3) |(1<<2) |(1<<1) |(0);
      
   TESS_BFU_UART_RECIEVE.HEADER_FLAG   = 0;
   TESS_BFU_UART_RECIEVE.COUNTER       = 0;
   TESS_BFU_UART_TRANSMITE.COUNTER     = 0;
   TESS_START_ACQ = 0;
   TESS_RING_BUFFER_INIT(&TESS_RING_BUFFER);
}

void TESS_BFU_UART_TX_HANDLER()
{
   unsigned_int16_t req_speed;
   unsigned_int16_t req_dir;

   req_speed = (2450)>>5;
   req_dir   = (32)>>5;
  
   if(TESS_BFU_UART_TRANSMITE.COUNTER == 0)
   {
      TESS_BFU_UART_TRANSMITE.BUFFER[0] = HEADER | ((req_speed & 0x3C0)>>6);
      TESS_BFU_UART_TRANSMITE.BUFFER[1] = ((req_speed & 0x3F)<<2) | ((req_dir & 0x300)>>8);
      TESS_BFU_UART_TRANSMITE.BUFFER[2] = req_dir & 0xFF;
      TESS_BFU_UART_TRANSMITE.BUFFER[3] = TESS_UART_PERFORM_CHECKSUM(BUFFER_SIZE);
   }
   else
   {
      /*do nothing*/
   }
   
    TESS_BFU_UART_PUT(TESS_BFU_UART_TRANSMITE.BUFFER[TESS_BFU_UART_TRANSMITE.COUNTER++]);

    if(TESS_BFU_UART_TRANSMITE.COUNTER >= BUFFER_SIZE)
    {
        TESS_BFU_UART_TRANSMITE.COUNTER = 0;
    }
    else
    {
       /*do nothing*/
    }

}

void TESS_BFU_UART_RX_HANDLER()
{
    //read only one byte at a time
    unsigned_char_t r_byte;
    unsigned_char_t checksum;
    
    r_byte = UDR0;
    
    //Check if header is found
    if((r_byte & 0xF0) == HEADER)
    {
      //We must consider that we may sometimes receive unformatted data, and
      //given the case we must ignore it and restart our reading code.
      //If it's the first time we find the header, we restart readCounter
      //indicating that data is coming.
      //It's possible the header appears again as a data byte. That's why
      //this conditional is implemented, so that we don't restart readCounter
      //and corrupt the data. 
      
      if(!TESS_BFU_UART_RECIEVE.HEADER_FLAG)
      {
        TESS_BFU_UART_RECIEVE.HEADER_FLAG = 1;
        TESS_BFU_UART_RECIEVE.COUNTER = 0;
      }
      else
      {
        /* do nothing */
      }
    }
    else
    {
      /* do nothing */
    }  
    //store received byte, increase readCounter
    TESS_BFU_UART_RECIEVE.BUFFER[TESS_BFU_UART_RECIEVE.COUNTER++] = r_byte;
    
    //prior overflow, we have to restart readCounter
    if(TESS_BFU_UART_RECIEVE.COUNTER >= BUFFER_SIZE)
    {
      TESS_BFU_UART_RECIEVE.COUNTER = 0;
      
      //if header was found
      if(TESS_BFU_UART_RECIEVE.HEADER_FLAG == 1)
      {
        //get checksum value from buffer's last value, according to defined protocol
        checksum =  TESS_BFU_UART_RECIEVE.BUFFER[CHECK_SUM_BYTE];
        
        //perform checksum validation, it's optional but really suggested
        if(TESS_UART_VERIFYCHECKSUM(checksum))
        {
           /*Process messages and send send them further*/
           TESS_BFU_UART_PROCESS_DATA ();
        }
        else
        {
          /* do thing */
        }
        
        //restart header flag
        TESS_BFU_UART_RECIEVE.HEADER_FLAG = 0;
      }
      else
      {
        /* do nothing */
      }
    }
    else
    {
      /* do nothing */
    }
}

void TESS_BFU_UART_PROCESS_DATA ()
{
  Set_TessStateMachReqSpeed((((TESS_BFU_UART_RECIEVE.BUFFER[0] & SPEED_MSK1)<<6) | ((TESS_BFU_UART_RECIEVE.BUFFER[1] & SPEED_MSK2)>>2))*32 );
  Set_TessStateMachReqDir(((TESS_BFU_UART_RECIEVE.BUFFER[1] & DIR_MSK1)<<8) | ((TESS_BFU_UART_RECIEVE.BUFFER[2] & DIR_MSK2)>>0) );

   if((Get_TessStateMachReqSpeed() >= 0) && (Get_TessStateMachReqSpeed() <= 16000))
      Set_TessStateMachReqSpeed(Get_TessStateMachReqSpeed()-16000);
   else if ((Get_TessStateMachReqSpeed() > 16000) && (Get_TessStateMachReqSpeed() <= 32000))
      Set_TessStateMachReqSpeed((-1)*(16000-Get_TessStateMachReqSpeed()));
}

unsigned_char_t TESS_UART_PERFORM_CHECKSUM (unsigned_char_t buffer_size)
{
  /*Perform a sum of all bytes, except the one that corresponds to the original
    checksum value. After summing we need to AND the result to a byte value.*/
    
  unsigned_char_t result = 0;
  unsigned_char_t sum = 0;
  unsigned_char_t i;
  
  for(i = 0; i < (buffer_size - 1); i++)
  {

    sum += TESS_BFU_UART_TRANSMITE.BUFFER[i];
  }
  result = sum & 0xFF;

  return result;
}

unsigned_char_t TESS_UART_VERIFYCHECKSUM(unsigned_char_t originalResult)
{

//This a common checksum validation method
//We perform a sum of all bytes, except the one that corresponds to the original
//checksum value. After summing we need to AND the result to a byte value.
  
  unsigned_char_t result = 0;
  unsigned_int16_t sum = 0;
  unsigned_char_t i;
  
  for(i = 0; i < (BUFFER_SIZE - 1); i++)
  {
    sum += TESS_BFU_UART_RECIEVE.BUFFER[i];
  }
  result = sum & 0xFF;
  
  if(originalResult == result)
  {
     return 1;
  }
  else
  {
     return 0;
  }
}

void TESS_BFU_UART_PUT(unsigned_char_t to_send)
{

    while ( !( UCSR0A & (1<<UDRE0)) );
    {
      UDR0 = to_send;
    }
}

void TESS_BFU_UART_PACK_ACQ_MSG(unsigned_char_t * acq_buffer, r_buff_data_t* ring_buffer)
{
   unsigned_int16_t loc_cnt;
   unsigned_char_t * ptr2str = (unsigned_char_t * )(ring_buffer);
   ptr2str[0]  = ACQ_HEADER;
   for(loc_cnt = 1; loc_cnt <= ACQ_BUFFER_SIZE; loc_cnt++)
   {
      ptr2str[loc_cnt] = acq_buffer[loc_cnt-1];
   }
   ptr2str[ACQ_BUFFER_SIZE+1] = ACQ_FOOTER;

}
#ifdef __cplusplus
}
#endif




