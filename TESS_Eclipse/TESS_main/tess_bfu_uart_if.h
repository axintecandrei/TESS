/**
  ******************************************************************************
  * File Name          : tess_bfu_adc_if.h
  * Author			   : Axinte Andrei
  * Description        : ADC module interface header file
  ******************************************************************************
**/
#ifndef __tess_bfu_uart_if_h__
#define __tess_bfu_uart_if_h__

#include "Arduino.h"
#include "tess_conf.h"
#include "tess_bfu_io.h"
#include "tess_moc_speedcurrctrl_if.h"
#include "tess_data_acq_output.h"
#include "tess_ring_buffer.h"
#include "tess_sal_types.h"


/*VARIABLES*/


/*FUNCTIONS*/
extern void TESS_BFU_UART_INIT();

extern void TESS_BFU_UART_RX_HANDLER();

extern void TESS_BFU_UART_TX_HANDLER();

extern void TESS_BFU_UART_PROCESS_DATA ();

extern void TESS_BFU_UART_PUT(unsigned_char_t to_send);
#if CFG_ACQ_ON
void TESS_BFU_UART_PACK_ACQ_MSG(unsigned_char_t * acq_buffer, r_buff_data_t* ring_buffer);
#endif
extern unsigned_char_t TESS_UART_VERIFYCHECKSUM(unsigned_char_t originalResult);

extern unsigned_char_t TESS_UART_PERFORM_CHECKSUM (unsigned_char_t buffer_size);
#endif /*__tess_bfu_uart_if_h__*/

