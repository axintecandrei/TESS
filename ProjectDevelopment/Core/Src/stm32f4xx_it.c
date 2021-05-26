/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "freemaster_private.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TESS_MOTOR_RESISTANCE (1.9F)       /*Ohm*/
#define TESS_MOTOR_INDUCTANCE (0.001558F)  /*H*/
//#define TESS_MOTOR_KE         (4.282E-3)   /*V/rad/s*/
#define TESS_MOTOR_KE         (2.584E-4) /*(4.484E-04)*/  /*V/rad/s*/
#define TESS_TS               (0.002F)     /*s*/
#define TESS_GEAR_RATIO       (25.0F)      /*gear box ratio*/
#define TESS_mV_TO_V          (0.001F)     /**/
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define AbsValue(x) (((x)>=0) ? (x) : (-(x)))
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint16_t AdcValueM1Current;
uint16_t AdcValueM2Current;
uint16_t AdcValueM3Current;
uint16_t AdcValueM4Current;
uint16_t AdcValueDcLink1;

uint32_t MAIN_CLOCK;
uint16_t PWM_DTC;
uint16_t PWM_DTC_READ;
uint16_t PWM_PER_READ;
float    MOTOR_PWM_DTC;
uint16_t MOTOR_CURRENT_ADC_VALUE;
float    DC_LINK_VOLT;
float    MOTOR_VOLT, M1_CURRENT, M2_CURRENT, WHEEL_EST_SPEED;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
float TESS_MOTOR_MODEL(float current_meas, float voltage_meas);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint16_t ADC_GetSingleConv()
{
    /*Start conversion*/
    ADC1->CR2 |= 1 << 30;

    /*Wait till conversion done*/
    while(!((ADC1->SR & 0x02)>>1));

    /*Return the converted data*/
    return ADC1->DR;
}
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim2;
extern UART_HandleTypeDef huart3;
/* USER CODE BEGIN EV */
extern TIM_HandleTypeDef htim1;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

    HAL_GPIO_TogglePin(GPIOB, LD2_Pin);
  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles ADC1 global interrupt.
  */
void ADC_IRQHandler(void)
{
  /* USER CODE BEGIN ADC_IRQn 0 */
    HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);
    AdcValueM1Current = HAL_ADCEx_InjectedGetValue(&hadc1, ADC_INJECTED_RANK_1);
    AdcValueDcLink1   = HAL_ADCEx_InjectedGetValue(&hadc1, ADC_INJECTED_RANK_2);
    AdcValueM3Current = HAL_ADCEx_InjectedGetValue(&hadc1, ADC_INJECTED_RANK_3);
    AdcValueM4Current = HAL_ADCEx_InjectedGetValue(&hadc1, ADC_INJECTED_RANK_4);
    //AdcValueDcLink1 = ADC_GetSingleConv();


    MOTOR_PWM_DTC = (float)PWM_DTC_READ/(float)PWM_PER_READ;
    /*DC_LINK_VOLT = ((((float)DC_LINK_ADC_VALUE*3.3F)/4096.0F) * 3 );
    MOTOR_VOLT = DC_LINK_VOLT * MOTOR_PWM_DTC;*/
    M1_CURRENT =  (((float)AdcValueM1Current*3300.0F)/4096.0F) ; /*adc to mV*/
    M1_CURRENT /= 0.5F; /*mV to mA*/

    DC_LINK_VOLT = (((float)AdcValueDcLink1*3320.0F)/4095.0F)*3 ; /*adc to mV*/
    MOTOR_VOLT = DC_LINK_VOLT*MOTOR_PWM_DTC - (DC_LINK_VOLT*0.5);
    WHEEL_EST_SPEED = TESS_MOTOR_MODEL(M1_CURRENT,MOTOR_VOLT);
    TIM1->CCR3 = htim1.Init.Period*0.5;/*((float)PWM_DTC*0.01F)*htim1.Init.Period;*/
    TIM1->CCR4 = htim1.Init.Period*0.5;/*htim1.Init.Period - (((float)PWM_DTC*0.01F)*htim1.Init.Period);*/
    TIM1->CCR1 = ((float)PWM_DTC*0.01F)*htim1.Init.Period;
    TIM1->CCR2 =  htim1.Init.Period - (((float)PWM_DTC*0.01F)*htim1.Init.Period);

    MAIN_CLOCK++;
#if(!FMSTR_DISABLE)
      FMSTR_Poll();
      FMSTR_Recorder();
#endif
  /* USER CODE END ADC_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc1);
  /* USER CODE BEGIN ADC_IRQn 1 */

  /* USER CODE END ADC_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */
    HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_RESET);
    PWM_DTC_READ = TIM2->CCR2;
    PWM_PER_READ = TIM2->CCR1;
  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles USART3 global interrupt.
  */
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */
#if(!FMSTR_DISABLE)
  FMSTR_ProcessSCI();
#endif
  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */

  /* USER CODE END USART3_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream0 global interrupt.
  */
void DMA2_Stream0_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream0_IRQn 0 */

  /* USER CODE END DMA2_Stream0_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc1);
  /* USER CODE BEGIN DMA2_Stream0_IRQn 1 */

  /* USER CODE END DMA2_Stream0_IRQn 1 */
}

/* USER CODE BEGIN 1 */
float TESS_MOTOR_MODEL(float ia_meas, float va_meas)
{
    static float ia_k_1;
    float d_ia, est_speed;

    d_ia = ia_meas - ia_k_1;
    ia_k_1 = ia_meas;

    est_speed  = (va_meas - ia_meas*TESS_MOTOR_RESISTANCE - (TESS_MOTOR_INDUCTANCE*d_ia)*TESS_TS)*TESS_mV_TO_V;
    est_speed /= TESS_MOTOR_KE;
    est_speed /= TESS_GEAR_RATIO;

    return est_speed;
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
