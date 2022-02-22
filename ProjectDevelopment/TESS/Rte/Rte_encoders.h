/*
 * Rte_encoders.h
 *
 *  Created on: Feb 15, 2022
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_ENCODERS_H_
#define RTE_RTE_ENCODERS_H_

#include "StandardTypes.h"

uint16 PORT__TessEncoderFrequencyM1;
uint16 PORT__TessEncoderFrequencyM2;
uint16 PORT__TessEncoderFrequencyM3;
uint16 PORT__TessEncoderFrequencyM4;

#define Set_TessEncoderFrequencyM1(x)   (PORT__TessEncoderFrequencyM1 = (x))
#define Get_TessEncoderFrequencyM1()    (*((const uint16 *) &PORT__TessEncoderFrequencyM1))

#define Set_TessEncoderFrequencyM2(x)   (PORT__TessEncoderFrequencyM2 = (x))
#define Get_TessEncoderFrequencyM2()    (*((const uint16 *) &PORT__TessEncoderFrequencyM2))

#define Set_TessEncoderFrequencyM3(x)   (PORT__TessEncoderFrequencyM3 = (x))
#define Get_TessEncoderFrequencyM3()    (*((const uint16 *) &PORT__TessEncoderFrequencyM3))

#define Set_TessEncoderFrequencyM4(x)   (PORT__TessEncoderFrequencyM4 = (x))
#define Get_TessEncoderFrequencyM4()    (*((const uint16 *) &PORT__TessEncoderFrequencyM4))


extern void Tess_EcuGetEncoderFrequency(uint8 EncoderIdx, uint16 EncoderFrequency);
#endif /* RTE_RTE_ENCODERS_H_ */
