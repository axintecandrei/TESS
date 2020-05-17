#ifndef __usart_H
#define __usart_H
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "../_Main_/utilities.h"
#include "../Communication/AqPlot/tess_data_acq_output.h"
#if CFG_FMSTR_ON || CFG_ACQ_ON
#define SCI_TX_Pin        GPIO_PIN_2
#define SCI_TX_GPIO_Port  GPIOA
#define SCI_RX_Pin        GPIO_PIN_3
#define SCI_RX_GPIO_Port  GPIOA

#define DMA_CLEAR_TCIT()        do{DMA1->HIFCR &= (~DMA_HIFCR_CTCIF6);}while(0)
#define DMA_ENABLE()            do{DMA1_Stream6->CR |= DMA_SxCR_EN;}while(0)
#define DMA_DISABLE()           do{DMA1_Stream6->CR &= (~DMA_SxCR_EN);}while((DMA1_Stream6->CR & 0x01))

#define USART_TX_ENABLE()       do{USART2->CR1 |= USART_CR1_TE;}while(0)
#define USART_TX_DISABLE()      do{USART2->CR1 &= (~USART_CR1_TE);}while(0)
#define USART_RX_ENABLE()       do{USART2->CR1 |= USART_CR1_RE;}while(0)
#define USART_RX_DISABLE()      do{USART2->CR1 &= (~USART_CR1_RE);}while(0)

#define USART_ENABLE_RXIT()     do{USART2->CR1 |= (USART_CR1_RXNEIE);}while(0)
#define USART_DISABLE_RXIT()    do{USART2->CR1 &= ~(USART_CR1_RXNEIE);}while(0)
#define USART_ENABLE_TXIT()     do{USART2->CR1 |= (USART_CR1_TCIE);}while(0)
#define USART_DISABLE_TXIT()    do{USART2->CR1 &= ~(USART_CR1_TCIE);}while(0)
#define USART_CLEAR_RXIT()      do{USART2->SR &= ~(USART_SR_RXNE | USART_SR_IDLE);}while(0)
#define USART_CLEAR_TCIT()      do{USART2->SR &= (~USART_SR_TC);}while(0)

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_tx;

extern void Error_Handler(void);
void USART2_UART_Init(void);
#endif
#endif /*__usart_H*/
