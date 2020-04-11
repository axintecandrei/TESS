/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "main.h"
void UART_TransmitHelloWorld();

int main(void)
{
	MAIN_INIT();

	for(;;)
	{
		MAIN_CLOCK++;
		//UART_TransmitHelloWorld();
		#if(!FMSTR_DISABLE)
		   {
			FMSTR_Poll();
			FMSTR_Recorder();
		   }
		#endif
	}
}
void UART_TransmitHelloWorld()
{
    char message[] = "hel";
    HAL_UART_Transmit(&huart2, (unsigned char*)message, 3, 10);
}
