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
	static uint32_t TESS_LOOP_CNT = 0;
	TESS_LOOP_CNT++;

    out_buffer->byte0 = (TESS_RING_BUFFER.count&0x000000FF);
    out_buffer->byte1 = (TESS_RING_BUFFER.count&0x0000FF00)>>8;
    out_buffer->byte6 = 0;
    out_buffer->byte2 = 0;
    out_buffer->byte3 = 0;
    out_buffer->byte4 = 0;
    out_buffer->byte5 = 0;
    out_buffer->byte6 = 0;
    out_buffer->byte7 = 0;
    out_buffer->byte8 = 0;
    out_buffer->byte9 = 0;
    out_buffer->byte10 =0;
    out_buffer->byte11 =0;
    out_buffer->byte12 =0;
    out_buffer->byte13 =0;
    out_buffer->byte14 =0;
    out_buffer->byte15 =0;
    out_buffer->byte16 =0;
    out_buffer->byte17 =0;
    out_buffer->byte18 =0;
    out_buffer->byte19 =0;
    out_buffer->byte20 =0;
    out_buffer->byte21 =0;
    out_buffer->byte22 =(TESS_LOOP_CNT&0x000000FF);
    out_buffer->byte23 =(TESS_LOOP_CNT&0x0000FF00)>>8;
    out_buffer->byte24 =(TESS_LOOP_CNT&0x00FF0000)>>16;
    out_buffer->byte25 =(TESS_LOOP_CNT&0xFF000000)>>24;
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
    	  /*Trigger first transmission, rest will be done by the dma*/
    	  //LLD_UART_START_TX_DMA((uint32_t)((uint8_t *)&TESS_DMA_BUFFER), ACQ_BUFFER_SIZE);
    	  HAL_UART_Transmit_DMA(&huart2, (uint8_t *)&TESS_DMA_BUFFER,ACQ_BUFFER_SIZE);
    	  Set_TessDasStates(DAS_KeepPacking);
    	  break;

      case DAS_ResumePackSend:
      	  /*Fill DAS buffer with variables*/
      	  TESS_DAS_OUT_BUFFER(&TESS_DATA_ACQ_BUFFER);
      	  /*Add package to ring buffer*/
      	  TESS_RING_BUFFER_PUT(&TESS_RING_BUFFER, TESS_DATA_ACQ_BUFFER);
      	  /*Get from rinng buffer and copy package to dma buff*/
      	  TESS_DMA_BUFFER = TESS_RING_BUFFER_GET(&TESS_RING_BUFFER);
      	  /*resume transmission, rest will be done by the dma*/
      	  HAL_UART_DMAResume(&huart2);
      	  Set_TessDasStates(DAS_KeepPacking);
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
	else if ((command == DAS_ACK))
	{
		if (Get_TessDasStates() == DAS_KeepPacking)
		{
			//Set_TessDasStates(DAS_StartMeas);
			Set_TessDasStates(DAS_ResumePackSend);
		}
		else
		{
			/*transition from other states forbidden*/
		}
		/*
		Set_TessDasStates(DAS_ResumePackSend);
		*/
	}
	else if(command == DAS_STOP_MEAS)
	{
		Set_TessDasStates(DAS_StopOfMeasurement);
	}

}

void TESS_DAS_UPDATE_BUFFER()
{

	TESS_DMA_BUFFER = TESS_RING_BUFFER_GET(&TESS_RING_BUFFER);
}


#endif

