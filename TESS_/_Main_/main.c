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

int main(void)
{
	MAIN_INIT();

	for(;;)
	{
		MAIN_CLOCK++;
		//task_scheduler();
	}

}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */


  /* USER CODE END Error_Handler_Debug */
}


