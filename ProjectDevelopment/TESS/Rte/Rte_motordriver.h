/*
 * Rte_motordriver.h
 *
 *  Created on: Dec 26, 2021
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_MOTORDRIVER_H_
#define RTE_RTE_MOTORDRIVER_H_

#include "StandardTypes.h"

#define TESS_MAX_DTC     	(950)
#define TESS_MIN_DTC	 	(50)
#define TESS_STANDBY_DTC 	(500)

typedef enum
{
	M1Channel,
	M2Channel,
	M3Channel,
	M4Channel,
}TessMotDrvMotorMap_t;

extern void Tess_MotorDrv_SetMotorPwm(uint8 MotorChannel, uint16 DutyCycle);

#endif /* RTE_RTE_MOTORDRIVER_H_ */
