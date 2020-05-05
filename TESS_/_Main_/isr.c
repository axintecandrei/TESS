#include "isr.h"



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
#if CFG_ADC_REG_CONV

	task_scheduler();
	/*clear interrupt flag before exit */
	ADC_CLEAR_IT();
#endif
}

void TIM1_UP_TIM10_IRQHandler(void)
{
    /*clear interrupt flag before exit */
}

void TIM2_IRQHandler()
{
#if !CFG_ADC_REG_CONV
	task_scheduler();

	TIM2_CLEAR_IT();
#endif
}

void USART2_IRQHandler(void)
{

#if	FMSTR_DISABLE
	uint8_t temp_dr;f
	uint8_t temp_sr;
	temp_sr = USART2->SR;
	/*Check interrupt source*/
	if ((temp_sr & USART_SR_RXNE)>>USART_SR_RXNE_Pos)
	{
		/*Check for commands from PC-tester
		 * Call commands handler
	    */
		//HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_10);
		temp_dr = USART2->DR;
		TESS_DAS_GET_COMMANDS(temp_dr);

	}
	else if ((temp_sr & USART_SR_TC)>>USART_SR_TC_Pos)
	{
		/*the package has been sent
		 * - enable RX to get new commands
		 * - disable DMA and TX until further commands*/
		USART_CLEAR_TCIT();
	}else if ((temp_sr & USART_SR_PE)>>USART_SR_PE_Pos)
	{
		/*dummy read from DR*/
		temp_dr = USART2->DR;
		USART2->SR = 0;
	}


#else
	FMSTR_ProcessSCI();
#endif
	/*clear interrupt flag before exit */

	HAL_UART_IRQHandler(&huart2);
}

/* This function handles DMA1 stream6 global interrupt. */
void DMA1_Stream6_IRQHandler(void)
{
	HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_10);

	HAL_DMA_IRQHandler(&hdma_usart2_tx);
}
