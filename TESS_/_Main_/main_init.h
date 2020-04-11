/*
 * mcu_init.h
 *
 *  Created on: 20 mar. 2018
 *      Author: uidp7521
 */

#ifndef MCU_INIT_H_
#define MCU_INIT_H_

#include "stm32f4xx.h"
#include "../LowLevelDrivers/UserDefined/lld_system.h"
#include "../LowLevelDrivers/UserDefined/lld_usart.h"
#include "../Communication/FreeMaster/freemaster.h"
#include "../Communication/FreeMaster/freemaster_STM32F4xx.h"



void MAIN_INIT(void);
#endif /* MCU_INIT_H_ */
