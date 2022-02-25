/*
 * Rte_encoders.h
 *
 *  Created on: Feb 15, 2022
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_ENCODERS_H_
#define RTE_RTE_ENCODERS_H_

#include "StandardTypes.h"

int16 PORT__TessEncoderPeriod[4];

uint8 PORT__TessNewEncoderCapture[4];

#define Set_TessEncoderPeriod(y,x)   (PORT__TessEncoderPeriod[y] = (x))
#define Get_TessEncoderPeriod(y)     (PORT__TessEncoderPeriod[y])

#define Set_TessNewEncoderCapture(y,x)   (PORT__TessNewEncoderCapture[y] = (x))
#define Get_TessNewEncoderCapture(y)     (PORT__TessNewEncoderCapture[y])


extern void Tess_EcuSetEncoderPeriod(uint8 EncoderIdx, int16 EncoderPeriod);
#endif /* RTE_RTE_ENCODERS_H_ */
