/*
 * Rte_actuatormanager.h
 *
 *  Created on: Dec 27, 2021
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_ACTUATORMANAGER_H_
#define RTE_RTE_ACTUATORMANAGER_H_

#include "StandardTypes.h"
#include "tess_moc_types.h"

/*Control word bitfields*/
#define Moc_StandBy   ( 1)
#define Moc_Pwm       ( 2)
#define Moc_Voltage   ( 4)
#define Moc_Current   ( 8)
#define Moc_Speed     (16)


uint8 PORT__TessActMngControlWord;

#define Set_TessActMngControlWord(x)   (PORT__TessActMngControlWord = (x))
#define Get_TessActMngControlWord()    (*((const uint8 *) &PORT__TessActMngControlWord))

uint8 PORT__TessActMngRemoteEN;

#define Set_TessActMngRemoteEN(x)   (PORT__TessActMngRemoteEN = (x))
#define Get_TessActMngRemoteEN()    (*((const uint8 *) &PORT__TessActMngRemoteEN))

moc_mot_requests_t PORT__TessActMngRequests[4];

#define Set_TessActMngSpeedRequest(y,x)    (PORT__TessActMngRequests[y].Speed = (x))
#define Get_TessActMngSpeedRequest(y)      (PORT__TessActMngRequests[y].Speed)

#define Set_TessActMngVoltageRequest(y,x)  (PORT__TessActMngRequests[y].Voltage = (x))
#define Get_TessActMngVoltageRequest(y)    (PORT__TessActMngRequests[y].Voltage)

#define Set_TessActMngCurrentRequest(y,x)  (PORT__TessActMngRequests[y].Current = (x))
#define Get_TessActMngCurrentRequest(y)    (PORT__TessActMngRequests[y].Current)

uint16 PORT__TessActMngRequestDtc[4];

#define Set_TessActMngRequestDtc(y,x)   (PORT__TessActMngRequestDtc[y] = (x))
#define Get_TessActMngRequestDtc(y)    (*((const uint16 *) &PORT__TessActMngRequestDtc[y]))

extern void Tess_Act_StateMachineInit(void);
extern void Tess_ActMng_Inputs(void);
extern void Tess_Act_StateMachine(void);

#endif /* RTE_RTE_ACTUATORMANAGER_H_ */
