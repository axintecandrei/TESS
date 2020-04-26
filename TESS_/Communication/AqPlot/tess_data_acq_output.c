/**
  ******************************************************************************
  * File Name          : tess_data_acq_output.c
  * Author			       : Axinte Andrei
  * Description        : IO pin mode setting source file
  ******************************************************************************
**/

/*INCLUDES*/
#include "tess_data_acq_output.h"
//#include  "../LowLevelDrivers/UserDefined/lld_usart.h"
#if CFG_ACQ_ON




void TESS_DAS_OUT_BUFFER(r_buff_data_t* out_buffer);

void TESS_DAS_INIT()
{
    USART_RX_ENABLE();
	Set_TessDasStates(DAS_StandBy);
}

void TESS_DAS_OUT_BUFFER(r_buff_data_t* out_buffer)
{
    /* fill buffer with dummy data*/
	static uint8_t cnt = 0;
   
    out_buffer->byte0 = ACQ_HEADER;
    out_buffer->byte1 = cnt++;
    out_buffer->byte2 = cnt++;
    out_buffer->byte3 = cnt++;
    out_buffer->byte4 = cnt++;
    out_buffer->byte5 = cnt++;
    out_buffer->byte6 = cnt++;
    out_buffer->byte7 = cnt++;
    out_buffer->byte8 = cnt++;
    out_buffer->byte9 = cnt++;
    out_buffer->byte10 =cnt++;
    out_buffer->byte11 =cnt++;
    out_buffer->byte12 =cnt++;
    out_buffer->byte13 =cnt++;
    out_buffer->byte14 =cnt++;
    out_buffer->byte15 =cnt++;
    out_buffer->byte16 =cnt++;
    out_buffer->byte17 =cnt++;
    out_buffer->byte18 =cnt++;
    out_buffer->byte19 =cnt++;
    out_buffer->byte20 =cnt++;
    out_buffer->byte21 =cnt++;
    out_buffer->byte22 =cnt++;
    out_buffer->byte23 =cnt++;
    out_buffer->byte24 =cnt++;
    out_buffer->byte25 =ACQ_FOOTER;
}

void TESS_DAS_MAIN()
{
  /*DAS State Machine*/
   switch(Get_TessDasStates())
   {
      case DAS_SendPackage:
    	  /*Fill DAS buffer with variables*/
    	  TESS_DAS_OUT_BUFFER(&TESS_DATA_ACQ_BUFFER);
    	  /*Add package to ring buffer*/
    	  TESS_RING_BUFFER_PUT(&TESS_RING_BUFFER, TESS_DATA_ACQ_BUFFER);
    	  /*Get from rinng buffer and copy package to dma buff*/
    	  TESS_DMA_BUFFER = TESS_RING_BUFFER_GET(&TESS_RING_BUFFER);
    	  /*Trigger first transmission, rest will be done by the dma*/
    	  LLD_UART_START_TX_DMA((uint32_t)((uint8_t *)&TESS_DMA_BUFFER), ACQ_BUFFER_SIZE);

    	  break;
      case DAS_KeepPacking:
   	      /*Fill DAS buffer with variables*/
    	  TESS_DAS_OUT_BUFFER(&TESS_DATA_ACQ_BUFFER);
   	      /*Add package to ring buffer*/
   	      TESS_RING_BUFFER_PUT(&TESS_RING_BUFFER, TESS_DATA_ACQ_BUFFER);
          break;
      case DAS_StopOfMeasurement:
    	  Set_TessDasStates(DAS_StandBy);
          break;
      case DAS_StandBy:
          break;
      default:
    	  break;
   }

}

void TESS_DAS_GET_COMMANDS(uint8_t command)
{

	if ((command == DAS_START_MEAS) || (command == DAS_ACK))
	{
		Set_TessDasStates(DAS_SendPackage);
	}
	else if(command == DAS_STOP_MEAS)
	{
		Set_TessDasStates(DAS_StopOfMeasurement);
	}

}

void TESS_DAS_UPDATE_BUFFER()
{

}


#endif

