
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

/* Includes ------------------------------------------------------------------*/
#include "task_scheduler.h"
#include "../LowLevelDrivers/UserDefined/lld_usart.h"
#include "../Communication/FreeMaster/freemaster.h"
#include "../Communication/FreeMaster/freemaster_private.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
#if CFG_DEBUG_FMSTR
uint8_t meas_period;
uint32_t TIM1_SR;
uint32_t TIM1_CNT;
uint32_t TIM1_CR1;
uint32_t TIM1_CR2;
uint32_t TIM1_CCER;
uint32_t TIM1_CCR1;
uint32_t TIM1_SMCR;
uint32_t ADC_CR1;
uint32_t ADC_CR2;
uint32_t ADC_SR;
#endif


void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void USART2_IRQHandler(void);


#endif /* __STM32F4xx_IT_H */
