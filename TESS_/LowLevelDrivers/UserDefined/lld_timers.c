/*
 * lld_timers.c
 *
 *  Created on: 11 apr. 2020
 *      Author: uidp7521
 */
#include "lld_timers.h"

void TIMER2_INIT()
{

	/*Enable AHB clock*/
	__TIM2_CLK_ENABLE();

   /*time-base unit*/
   /*
    * Prescaler 0 => Fcnt = Ftim_clk/(Prescaler + 1)
    *                Fcnt = 84Mhz
    *                Tcnt = 11,9047619047 ns
    */
	TIM2->PSC = 0;
	/*Interrupt period = Tcnt*ARR
	 * Ex: For 0.0002us ARR needs to be 16800
	 * */
	TIM2->ARR = 16800;


	/*master/slave controller unit*/
	/*Enable master mode to trigger start
	 * ADC conversion
	 */
	TIM2->CR2 |= TIM_CR2_MMS_1;
	TIM2->SMCR |= TIM_SMCR_MSM;



	/*Interrupt Settings
	 * Enable Update Event interrupt
	 * */
#if !CFG_ADC_REG_CONV

	HAL_NVIC_SetPriority(TIM2_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	TIM2->DIER |=TIM_DIER_UIE;*/
#endif
    /*Enable Counter*/
	TIM2->CR1  |= TIM_CR1_CEN;

}

void TESS_GPIO_INIT()
{
	GPIO_InitTypeDef GPIOx_Init;

	GPIOx_Init.Pin   = GPIO_PIN_10;
	GPIOx_Init.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIOx_Init.Pull  = GPIO_NOPULL;
	GPIOx_Init.Speed = GPIO_SPEED_HIGH;

	/*Enable bus clock for ports*/
	__GPIOC_CLK_ENABLE();
    /*HAL func that will do the proper initialisation*/
	HAL_GPIO_Init(GPIOC, &GPIOx_Init);
}
