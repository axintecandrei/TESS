/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tess_main.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define HAL_MCU_CLOCK_FREQUENCY   (170000000)
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWMOutput1M2_Pin_Pin GPIO_PIN_0
#define PWMOutput1M2_Pin_GPIO_Port GPIOC
#define PWMOutput2M2_Pin_Pin GPIO_PIN_1
#define PWMOutput2M2_Pin_GPIO_Port GPIOC
#define PWMOutput1M1_Pin_Pin GPIO_PIN_2
#define PWMOutput1M1_Pin_GPIO_Port GPIOC
#define PWMOutput2M1_Pin_Pin GPIO_PIN_3
#define PWMOutput2M1_Pin_GPIO_Port GPIOC
#define ADCM1Current_Pin_Pin GPIO_PIN_0
#define ADCM1Current_Pin_GPIO_Port GPIOA
#define ADCM2Current_Pin_Pin GPIO_PIN_1
#define ADCM2Current_Pin_GPIO_Port GPIOA
#define ADCM3Current_Pin_Pin GPIO_PIN_2
#define ADCM3Current_Pin_GPIO_Port GPIOA
#define ADCDcLink_Pin_Pin GPIO_PIN_3
#define ADCDcLink_Pin_GPIO_Port GPIOA
#define EncoderM1_A_Pin GPIO_PIN_5
#define EncoderM1_A_GPIO_Port GPIOA
#define BT_TX_Pin GPIO_PIN_4
#define BT_TX_GPIO_Port GPIOC
#define BT_RX_Pin GPIO_PIN_5
#define BT_RX_GPIO_Port GPIOC
#define ADCM4Current_Pin_Pin GPIO_PIN_14
#define ADCM4Current_Pin_GPIO_Port GPIOB
#define PWMOutput1M3_Pin_Pin GPIO_PIN_6
#define PWMOutput1M3_Pin_GPIO_Port GPIOC
#define PWMOutput2M3_Pin_Pin GPIO_PIN_7
#define PWMOutput2M3_Pin_GPIO_Port GPIOC
#define PWMOutput1M4_Pin_Pin GPIO_PIN_8
#define PWMOutput1M4_Pin_GPIO_Port GPIOC
#define PWMOutput2M4_Pin_Pin GPIO_PIN_9
#define PWMOutput2M4_Pin_GPIO_Port GPIOC
#define Debug_Pin GPIO_PIN_8
#define Debug_GPIO_Port GPIOA
#define USART3_TX_Pin GPIO_PIN_10
#define USART3_TX_GPIO_Port GPIOC
#define USART3_RX_Pin GPIO_PIN_11
#define USART3_RX_GPIO_Port GPIOC
#define EncoderM1_B_Pin GPIO_PIN_3
#define EncoderM1_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
