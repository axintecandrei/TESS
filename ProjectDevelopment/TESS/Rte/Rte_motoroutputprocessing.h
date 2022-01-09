/*
 * Rte_motoroutputprocessing.h
 *
 *  Created on: Jan 7, 2022
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_MOTOROUTPUTPROCESSING_H_
#define RTE_RTE_MOTOROUTPUTPROCESSING_H_

#include "StandardTypes.h"

uint16 PORT__TessMopRequestDtc[4];

#define Set_TessMopRequestDtc(y,x)   (PORT__TessMopRequestDtc[y] = (x))
#define Get_TessMopRequestDtc(y)    (*((const uint16 *) &PORT__TessMopRequestDtc[y]))

extern void Tess_Mop_Main(void);

#endif /* RTE_RTE_MOTOROUTPUTPROCESSING_H_ */
