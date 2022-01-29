/*
 * Rte_motorinputprocessing.h
 *
 *  Created on: Jan 7, 2022
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_MOTORINPUTPROCESSING_H_
#define RTE_RTE_MOTORINPUTPROCESSING_H_

#include "StandardTypes.h"

uint16 PORT__TessMipDcLinkVoltage;

#define Set_TessMipDcLinkVoltage(x)   (PORT__TessMipDcLinkVoltage = (x))
#define Get_TessMipDcLinkVoltage()    (*((const uint16 *) &PORT__TessMipDcLinkVoltage))

extern void Tess_Mip_Init(void);
extern void Tess_Mip_Main(void);

#endif /* RTE_RTE_MOTORINPUTPROCESSING_H_ */
