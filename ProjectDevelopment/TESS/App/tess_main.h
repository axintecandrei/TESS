/*
 * tess_main.h
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_MAIN_H_
#define TESS_MAIN_H_

#include "tess_mcal.h"
#include "Rte_adc.h"
#include "Rte_actuatormanager.h"
#include "Rte_motorcontrol.h"
#include "Rte_motorinputprocessing.h"
#include "Rte_motoroutputprocessing.h"
#include "Rte_ComBT.h"


void TessMain(void);
void TessMainInit(void);

#endif /* TESS_MAIN_H_ */
