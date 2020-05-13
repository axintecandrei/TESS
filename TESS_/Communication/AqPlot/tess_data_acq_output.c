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
uint32_t dma_isr_cnt, ring_buff_cnt;

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
    out_buffer->byte3 = 0;
    out_buffer->byte4 = 0;
    out_buffer->byte5 = 0;
    out_buffer->byte6 = 0;
    out_buffer->byte7 = 0;
    out_buffer->byte8 = 0;
    out_buffer->byte9 = 0;
    out_buffer->byte10 = 0;// Get_TessDasStates();
    out_buffer->byte11 =(TESS_LOOP_CNT&0x000000FF);
    out_buffer->byte12 =(TESS_LOOP_CNT&0x0000FF00)>>8;
    out_buffer->byte13 =(TESS_LOOP_CNT&0x00FF0000)>>16;
    out_buffer->byte14 =(TESS_LOOP_CNT&0xFF000000)>>24;
    out_buffer->byte15 =0x77;

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
    	  HAL_UART_Transmit_DMA(&huart2, (uint8_t *)&TESS_DMA_BUFFER,ACQ_BUFFER_SIZE);

    	  Set_TessDasStates(DAS_KeepPacking);
    	  TESS_LOOP_CNT++;
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
    	  /*Send a msg to pc that the measurement window is closed*/
    	  //TESS_DMA_BUFFER.byte0 =
    	  //break;
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
		if (Get_TessDasStates() == DAS_KeepPacking)
		{
			Set_TessDasStates(DAS_StopOfMeasurement);
		}
		else
		{
			/*transition from other states forbidden*/
		}

	}

}

void TESS_DAS_UPDATE_UPON_TC()
{



   if (Get_TessDasStates() == DAS_KeepPacking)
   {
 	  //if (!TESS_RINGBUFF_IS_FULL(&TESS_RING_BUFFER) )
         {
         TESS_DMA_BUFFER = TESS_RING_BUFFER_GET(&TESS_RING_BUFFER);
         dma_isr_cnt++;
         ring_buff_cnt = TESS_RING_BUFFER.count;
         TESS_DMA_BUFFER.byte1 = dma_isr_cnt&0x000000FF;
         TESS_DMA_BUFFER.byte2 = (dma_isr_cnt &0x0000FF00)>>8;
         TESS_DMA_BUFFER.byte3 = (TESS_RING_BUFFER.count&0x000000FF);
         TESS_DMA_BUFFER.byte4 = (TESS_RING_BUFFER.count&0x0000FF00)>>8;
         TESS_DMA_BUFFER.byte5 =  TESS_RING_BUFFER.head&0x000000FF;
         TESS_DMA_BUFFER.byte6 = (TESS_RING_BUFFER.head&0x0000FF00)>>8;
         TESS_DMA_BUFFER.byte7 =  TESS_RING_BUFFER.tail&0x000000FF;
         TESS_DMA_BUFFER.byte8 = (TESS_RING_BUFFER.tail&0x0000FF00)>>8;
         }

   }
   else if (Get_TessDasStates() == DAS_StopOfMeasurement)
   {
	  HAL_UART_DMAStop(&huart2);
	  /*Reset all data from RingBuffer*/
	  TESS_DAS_INIT();
   }

}



#endif

