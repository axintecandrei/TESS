/*
 * tess_motordriver.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_MOTORDRIVER_H_
#define TESS_MOTORDRIVER_H_

#include <tess_act_statemachine.h>
#include "tess_act_types.h"
#include "tess_hal_if.h"
#include "tess_utilities.h"

void Tess_MotDrv_Init();
void Tess_MotDrv_SetMotorsPwm(float M1Pwm, float M2Pwm, float M3Pwm, float M4Pwm);
#endif /* TESS_MOTORDRIVER_H_ */
