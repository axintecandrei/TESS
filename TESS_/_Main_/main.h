/*
 * main.h
 *
 *  Created on: 20 mar. 2018
 *      Author: uidp7521
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "main_init.h"
#include "utilities.h"
#include "../LowLevelDrivers/UserDefined/lld_usart.h"
#include "../Communication/FreeMaster/freemaster.h"
#include "../Communication/FreeMaster/freemaster_private.h"


void Error_Handler(void);
uint32_t MAIN_CLOCK;
#endif /* MAIN_H_ */
