/**
  ******************************************************************************
  * File Name          : tess_data_acq_output.c
  * Author			       : Axinte Andrei
  * Description        : IO pin mode setting source file
  ******************************************************************************
**/

/*INCLUDES*/
#include "tess_data_acq_output.h"

#if CFG_ACQ_ON

static void TESS_DAS_OUT_BUFFER(r_buff_data_t* out_buffer);

void TESS_DAS_INIT()
{
	TESS_RING_BUFFER_INIT(&TESS_RING_BUFFER);
	TESS_LOOP_CNT=0;
	Set_TessDasStates(DAS_StandBy);
}

static void TESS_DAS_OUT_BUFFER(r_buff_data_t* out_buffer)
{
    /* fill buffer with data*/
    out_buffer->byte0 = 0x55;
    out_buffer->byte1 = 0;
    out_buffer->byte2 = 0;
    out_buffer->byte3 = (TESS_RING_BUFFER.count&0x000000FF);
    out_buffer->byte4 = (TESS_RING_BUFFER.count&0x0000FF00)>>8;
    out_buffer->byte5 =  TESS_RING_BUFFER.head&0x000000FF;
    out_buffer->byte6 = (TESS_RING_BUFFER.head&0x0000FF00)>>8;
    out_buffer->byte7 =  TESS_RING_BUFFER.tail&0x000000FF;
    out_buffer->byte8 = (TESS_RING_BUFFER.tail&0x0000FF00)>>8;
    out_buffer->byte9 = 0;
    out_buffer->byte10 = Get_TessDasStates();
    out_buffer->byte11 =(TESS_LOOP_CNT&0x000000FF);
    out_buffer->byte12 =(TESS_LOOP_CNT&0x0000FF00)>>8;
    out_buffer->byte13 =(TESS_LOOP_CNT&0x00FF0000)>>16;
    out_buffer->byte14 =(TESS_LOOP_CNT&0xFF000000)>>24;
    out_buffer->byte15 =Get_AdcIa()&0x000000FF;
    out_buffer->byte16 =(Get_AdcIa()&0x0000FF00)>>8;
    out_buffer->byte17 =0x77;
    out_buffer->byte18 =0x77;
    out_buffer->byte19 =0x77;

}

void TESS_DAS_MAIN()
{
  /*DAS State Machine*/
   switch(Get_TessDasStates())
   {
      case DAS_StartMeas:
    	  /*Fill DAS buffer with variables*/
    	  TESS_DAS_OUT_BUFFER(&TESS_DATA_ACQ_BUFFER);
    	  /*Add package to ring buffer*/
    	  TESS_RING_BUFFER_PUT(&TESS_RING_BUFFER, TESS_DATA_ACQ_BUFFER);
    	  /*Get from rinng buffer and copy package to dma buff*/
    	  TESS_DMA_BUFFER = TESS_RING_BUFFER_GET(&TESS_RING_BUFFER);
#if CFG_DAS_USB_UART == CFG_DAS_UART_AVAILABLE
    	  /*Trigger first transmission, rest will be done by the dma*/
    	  HAL_UART_Transmit_DMA(&huart2, (uint8_t *)&TESS_DMA_BUFFER,ACQ_BUFFER_SIZE);
#else
    	  CDC_Transmit_FS((uint8_t *)&TESS_DMA_BUFFER,ACQ_BUFFER_SIZE);
#endif
    	  TESS_LOOP_CNT++;


    	  Set_TessDasStates(DAS_KeepPacking);
    	  break;

      case DAS_KeepPacking:

    	  if (!TESS_RINGBUFF_IS_FULL(&TESS_RING_BUFFER) )
            {
                /*Fill DAS buffer with variables*/
                TESS_DAS_OUT_BUFFER(&TESS_DATA_ACQ_BUFFER);
                /*Add package to ring buffer*/
                TESS_RING_BUFFER_PUT(&TESS_RING_BUFFER, TESS_DATA_ACQ_BUFFER);
                TESS_LOOP_CNT++;
            }
    	  else
            {
                /*Send a msg to pc that the measurement window is closed*/
               	Set_TessDasStates(DAS_StopOfMeasurement);
            }

          break;
      case DAS_StopOfMeasurement:
    	  TESS_DAS_INIT();
    	  Set_TessDasStates(DAS_StandBy);
    	  break;
      case DAS_StandBy:

      default:
    	  break;
   }

}

void TESS_DAS_GET_COMMANDS(uint8_t command)
{

	if ((command == DAS_START_MEAS) )
	{
		if (Get_TessDasStates() == DAS_StandBy)
		{
			Set_TessDasStates(DAS_StartMeas);
		}
		else
		{
			/*transition from other states forbidden*/
		}
	}
	else if(command == DAS_STOP_MEAS)
	{
		if ((Get_TessDasStates() == DAS_KeepPacking) || (Get_TessDasStates() == DAS_StartMeas))
		{
			Set_TessDasStates(DAS_StopOfMeasurement);
		}
		else
		{
			/*transition from other states forbidden*/
		}

	}

}

uint8_t TESS_DAS_UPDATE_UPON_TC()
{
#if CFG_DAS_USB_UART == CFG_DAS_USB_AVAILABLE
   uint8_t usb_tx_result = USBD_OK;
#endif
   if (Get_TessDasStates() == DAS_KeepPacking)
   {
 	  if (!TESS_RINGBUFF_IS_EMPTY(&TESS_RING_BUFFER) )
         {
 		    TESS_DMA_BUFFER = TESS_RING_BUFFER_GET(&TESS_RING_BUFFER);
#if CFG_DAS_USB_UART == CFG_DAS_USB_AVAILABLE
 		    usb_tx_result =  CDC_Transmit_FS((uint8_t *)&TESS_DMA_BUFFER,ACQ_BUFFER_SIZE);
#endif
         }else
         {
#if CFG_DAS_USB_UART == CFG_DAS_USB_AVAILABLE
        	 /*trigger another transmittion*/
        	 Set_TessDasStates(DAS_StartMeas);
#endif
         }
   }
#if CFG_DAS_USB_UART == CFG_DAS_USB_AVAILABLE
   else if (Get_TessDasStates() == DAS_StopOfMeasurement)
   {
	  HAL_UART_DMAStop(&huart2);
	  /*Reset all data from RingBuffer*/
	  TESS_DAS_INIT();
   }
#endif
   return usb_tx_result;
}

#if CFG_DAS_USB_UART == CFG_DAS_USB_AVAILABLE
void DAS_Receive_Clbk_USB (uint8_t* Buf, uint32_t Len)
{
	uint8_t rx_char_usb = 0;

	rx_char_usb = Buf[0];
	TESS_DAS_GET_COMMANDS(rx_char_usb);
}

int8_t  DAS_Transmit_Clbk_USB (void)
{

	return TESS_DAS_UPDATE_UPON_TC();
}
#endif

#endif

