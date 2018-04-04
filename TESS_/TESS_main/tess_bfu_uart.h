/**
  ******************************************************************************
  * File Name          : tess_bfu_adc.h
  * Author			       : Axinte Andrei
  * Description        : UART module header file
  ******************************************************************************
**/
#ifndef __tess_bfu_uart_h__
#define __tess_bfu_uart_h__

#include "tess_bfu_uart_if.h"

/*DEFINES*/
#define F_OSC            16000000                 /*MCU clock frequence [Hz]*/
#define BAUD_RATE        250000                   /*Desired baude rate*/
#define USART_BAUDRATE ((F_OSC/(16*BAUD_RATE))-1) /*Calculated the value to be set in baud rate register*/
#define HEADER           0xA0                      /*First byte of message block*/
#if CFG_ACQ_ON
#define ACQ_HEADER       0x7E                      /*First byte of message block*/
#define ACQ_FOOTER       0x81                      /*First byte of message block*/
#endif
#define BUFFER_SIZE      4                        /*Number of incomming bytes*/
#define CHECK_SUM_BYTE   3

#define SPEED_MSK1       0x0F
#define SPEED_MSK2       0xFC
#define DIR_MSK1         0x03
#define DIR_MSK2         0xFF
/*STRUCTURES*/

typedef struct
{
   unsigned_char_t  BUFFER[BUFFER_SIZE];
   unsigned_char_t  HEADER_FLAG;
   unsigned_char_t  COUNTER;  
}tess_rx_struct_t;

typedef struct
{
   unsigned_char_t  BUFFER[BUFFER_SIZE];
   unsigned_char_t  COUNTER;  
}tess_tx_struct_t;

/*VARIABLES*/
tess_rx_struct_t TESS_BFU_UART_RECIEVE;
tess_tx_struct_t TESS_BFU_UART_TRANSMITE;
unsigned_char_t TESS_START_ACQ;

#endif /*__tess_bfu_uart_h__*/
