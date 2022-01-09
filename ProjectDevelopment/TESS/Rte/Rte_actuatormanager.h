/*
 * Rte_actuatormanager.h
 *
 *  Created on: Dec 27, 2021
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_ACTUATORMANAGER_H_
#define RTE_RTE_ACTUATORMANAGER_H_

#include "StandardTypes.h"

#define Moc_StandBy   ( 1)
#define Moc_Pwm       ( 2)
#define Moc_Voltage   ( 4)
#define Moc_Current   ( 8)
#define Moc_Speed     (16)

uint8 PORT__TessActMngControlWord;

#define Set_TessActMngControlWord(x)   (PORT__TessActMngControlWord = (x))
#define Get_TessActMngControlWord()    (*((const uint8 *) &PORT__TessActMngControlWord))

extern void Tess_Act_StateMachineInit(void);
extern void Tess_ActMng_Inputs(void);
extern void Tess_Act_StateMachine(void);

#endif /* RTE_RTE_ACTUATORMANAGER_H_ */
