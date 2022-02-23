/*
 * tess_encoders.c
 *
 *  Created on: Feb 15, 2022
 *      Author: axinteandrei
 */
#include "tess_encoder.h"

void Tess_EcuGetEncoderFrequency(uint8 EncoderIdx, int16 EncoderFrequency)
{
	switch (EncoderIdx)
	{
	case 0:
		Set_TessEncoderFrequencyM1(EncoderFrequency);
		break;
	case 1:
		Set_TessEncoderFrequencyM2(EncoderFrequency);
		break;
	case 2:
		Set_TessEncoderFrequencyM3(EncoderFrequency);
		break;
	case 3:
		Set_TessEncoderFrequencyM4(EncoderFrequency);
		break;
	default:
		break;
	}
}
