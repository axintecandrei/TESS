/*
 * tess_encoders.c
 *
 *  Created on: Feb 15, 2022
 *      Author: axinteandrei
 */
#include "tess_encoder.h"

void Tess_EcuSetEncoderPeriod(uint8 EncoderIdx, int16 EncoderPeriod)
{
	Set_TessEncoderPeriod(EncoderIdx, EncoderPeriod);
	Set_TessNewEncoderCapture(EncoderIdx,Get_TessNewEncoderCapture(EncoderIdx)^1);
}
