/**
  ******************************************************************************
  * File Name          : USART.c
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  */

/* Includes ------------------------------------------------------------------*/
#include "lld_usart.h"

void DMA_INIT_UART();

void USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 1000000;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;


#if (CFG_FMSTR_ON)
  __HAL_UART_ENABLE_IT(&huart2,UART_IT_RXNE);
  __HAL_UART_ENABLE_IT(&huart2,UART_IT_TXE);
  __HAL_UART_ENABLE_IT(&huart2,UART_IT_TC);
#endif
  HAL_UART_Init(&huart2);
#if CFG_ACQ_ON

  USART_ENABLE_RXIT();
  //USART_ENABLE_TXIT();
  DMA_INIT_UART();
#endif
}

void DMA_INIT_UART()
{
    /*Configure DMA controller*/
     __HAL_RCC_DMA1_CLK_ENABLE();
#if 0
     /*If the stream is enabled, disable it*/
  	DMA1_Stream6->CR &= ~DMA_SxCR_EN;
  	while((DMA1_Stream6->CR & 0x01));

  	/*Set peripheral address - destination
  	 * the memory address and number of byte will be set
  	 * before transmission start, as this will vary */
  	DMA1_Stream6->PAR   = (uint32_t)&USART2->DR;
  	/*Set memory address - source*/
  	//DMA1_Stream6->M0AR  = (uint32_t)&ADC_TO_DMA_BUFFER[0];
  	//DMA1_Stream6->NDTR  = 30;
    /*Set channel */
  	DMA1_Stream6->CR   |= 4<<DMA_SxCR_CHSEL_Pos;
    /* Set priority*/
  	DMA1_Stream6->CR   |= DMA_SxCR_PL_0 ;
    /*Set direction of transfer - memory to peripheral*/
  	DMA1_Stream6->CR   |= DMA_SxCR_DIR_0;
  	/*Set Mode and data size 1byte, so 0 on PSIZE and MSIZE sections*/
  	DMA1_Stream6->CR   |= DMA_SxCR_CIRC |
  						  DMA_SxCR_MINC ;
#endif


    /* Peripheral DMA init*/
    hdma_usart2_tx.Instance = DMA1_Stream6;
    hdma_usart2_tx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_tx.Init.PeriphDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_tx.Init.Mode = DMA_CIRCULAR; //DMA_NORMAL; //
    hdma_usart2_tx.Init.Priority = DMA_PRIORITY_MEDIUM;
    hdma_usart2_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    HAL_DMA_Init(&hdma_usart2_tx);


  	__HAL_LINKDMA(&huart2,hdmatx,hdma_usart2_tx);

  	/*Enable Transfer complete interrupt*/
    DMA1_Stream6->CR   |= DMA_SxCR_TCIE;

    /* DMA interrupt init */
    HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(uartHandle->Instance==USART2)
  {
    /* Peripheral clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();
  
    /**USART2 GPIO Configuration    
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX 
    */

    __GPIOA_CLK_ENABLE();

    GPIO_InitStruct.Pin = SCI_TX_Pin|SCI_RX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Peripheral interrupt init */
    HAL_NVIC_SetPriority(USART2_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);

  }
}

void LLD_UART_START_TX_DMA(uint32_t data_buffer_addres, uint8_t size)
{

    /*send the buffer address and nr o f bytes to be transmitted
     * to the DMA controller*/
  	DMA1_Stream6->M0AR  = data_buffer_addres;
  	DMA1_Stream6->NDTR  = size;

    /* Clear the TC flag in the SR register by writing 0 to it */
    __HAL_UART_CLEAR_FLAG(&huart2, UART_FLAG_TC);
    /* Enable the DMA transfer for transmit request by setting the DMAT bit
       in the UART CR3 register */
    SET_BIT(huart2.Instance->CR3, USART_CR3_DMAT);

    /*Enable the DMA*/
  	DMA_ENABLE();

}
