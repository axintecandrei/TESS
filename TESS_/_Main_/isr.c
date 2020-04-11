#include "isr.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"


/**
  * @brief  This function handles SysTick Handler, but only if no RTOS defines it.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}


void ADC_IRQHandler(void)
{

}

void TIM1_UP_TIM10_IRQHandler(void)
{
   //HAL_TIM_IRQHandler(&htim1);
}

void TIM2_IRQHandler ()
{


}

void USART2_IRQHandler(void)
{

   if(!FMSTR_DISABLE)
   {
      FMSTR_ProcessSCI();
   }
  
   HAL_UART_IRQHandler(&huart2);

}
