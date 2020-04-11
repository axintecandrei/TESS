/*
 * mcu_init.c
 *
 *  Created on: 20 mar. 2018
 *      Author: uidp7521
 */
#include "main_init.h"


void MAIN_INIT(void)
{
	RCC_INIT();

	USART2_UART_Init();
#if !FMSTR_DISABLE
	FMSTR_Init();
#endif
}



