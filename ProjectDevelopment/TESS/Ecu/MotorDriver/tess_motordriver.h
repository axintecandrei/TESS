/*
 * tess_motordriver.h
 *
 *  Created on: Dec 20, 2021
 *      Author: axinteandrei
 */

#ifndef ECU_MOTORDRIVER_TESS_MOTORDRIVER_H_
#define ECU_MOTORDRIVER_TESS_MOTORDRIVER_H_

#include "StandardTypes.h"
#include "Rte_pwm.h"
#include "Rte_motordriver.h"

typedef enum
{
	M1Channel,
	M2Channel,
	M3Channel,
	M4Channel,
}TessMotDrvMotorMap_t;

#endif /* ECU_MOTORDRIVER_TESS_MOTORDRIVER_H_ */
