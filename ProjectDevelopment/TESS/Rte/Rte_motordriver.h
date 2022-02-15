/*
 * Rte_motordriver.h
 *
 *  Created on: Dec 26, 2021
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_MOTORDRIVER_H_
#define RTE_RTE_MOTORDRIVER_H_

#include "StandardTypes.h"

#define TESS_MAX_DTC     	(1000)
#define TESS_MIN_DTC	 	(0)
#define TESS_STANDBY_DTC 	(500)

extern void Tess_MotorDrv_SetMotorPwm(uint8 MotorChannel, uint16 DutyCycle);

#endif /* RTE_RTE_MOTORDRIVER_H_ */
