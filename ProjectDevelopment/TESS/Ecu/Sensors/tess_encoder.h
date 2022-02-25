/*
 * tess_encoder.h
 *
 *  Created on: Feb 15, 2022
 *      Author: axinteandrei
 */

#ifndef ECU_SENSORS_TESS_ENCODER_H_
#define ECU_SENSORS_TESS_ENCODER_H_

#include "StandardTypes.h"
#include "Rte_encoders.h"
#include "Rte_motordriver.h"

void Tess_EcuSetEncoderPeriod(uint8 EncoderIdx, int16 EncoderPeriod);
#endif /* ECU_SENSORS_TESS_ENCODER_H_ */
