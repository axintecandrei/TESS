/*
 * tess_motordriver.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_MOTORCONTROL_H_
#define TESS_MOTORCONTROL_H_

#include "Rte_motorcontrol.h"
#include "Rte_motorinputprocessing.h"
#include "Rte_actuatormanager.h"
#include "tess_moc_param.h"
#include "tess_utilities.h"
#include "tess_moc_types.h"

#define TESS_MOC_MAX_SPEED     (10000)  /*mot rpm*/

tess_act_motor_t Motor[TESS_MOTOR_NUMBERS];

void Tess_MotCtrl_Init(void);
void Tess_MotCtrl_Main(void);

#endif /* TESS_MOTORCONTROL_H_ */
