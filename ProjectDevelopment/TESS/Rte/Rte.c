/*
 * Rte.c
 *
 *  Created on: Mar 9, 2022
 *      Author: axinteandrei
 */

/*define all Ports here*/
#include "tess_moc_types.h"

uint8 PORT__TessActMngControlWord;
uint8 PORT__TessActMngRemoteEN;
moc_mot_requests_t PORT__TessActMngRequests[4];
uint16 PORT__TessActMngRequestDtc[4];


int16 PORT__TessEncoderPeriod[4];
uint8 PORT__TessNewEncoderCapture[4];

moc_mot_requests_t PORT__TessMocRequests[4];

uint16 PORT__TessMipDcLinkVoltage;
