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

	ADC_INIT();
    TIMER2_INIT();
    TESS_GPIO_INIT();

#if CFG_ACQ_ON
    TESS_DAS_INIT();
#if CFG_DAS_USB_UART == CFG_DAS_USB_AVAILABLE
    MX_USB_DEVICE_Init();
#else
	USART2_UART_Init();
#endif
#endif

#if !FMSTR_DISABLE
	USART2_UART_Init();
	FMSTR_Init();
#endif
}



