/*
 * tess_act_statemachine.h
 *
 *  Created on: Jun 19, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_ACT_STATEMACHINE_H_
#define TESS_ACT_STATEMACHINE_H_

#include "StandardTypes.h"
#include "Rte_actuatormanager.h"
#include "Rte_motorcontrol.h"
#include "Rte_motoroutputprocessing.h"
#include "Rte_ComBT.h"

#define ControlWord_StandBy              (Moc_StandBy)                                     /*1*/
#define ControlWord_Pwm                  (Moc_Pwm  )                                       /*2*/
#define ControlWord_Voltage              (Moc_Pwm | Moc_Voltage )                          /*6*/
#define ControlWord_CurrentControl       (Moc_Pwm | Moc_Voltage | Moc_Current)             /*14*/
#define ControlWord_SpeedVoltageControl  (Moc_Pwm | Moc_Voltage | Moc_Speed)               /*22*/
#define ControlWord_SpeedControl         (Moc_Pwm | Moc_Voltage | Moc_Current | Moc_Speed) /*30*/

typedef enum
{
    StandBy,
    PwmMode,
    VoltageMode,
    CurrentControl,
    SpeedVoltageControl,
    SpeedControl
}ControlMode_t;


typedef struct
{
    uint8       ControlWord;
    ControlMode_t CurrentMode;
    ControlMode_t RequestedMode;

}moc_statemachine_t;

moc_statemachine_t 	MotCtrlStateMachine;

ControlMode_t      	Tess_Input_RequestMode;
uint16			   	Tess_Input_RequestedSpeed;
uint16			   	Tess_Input_RequestedVoltage;
uint16			   	Tess_Input_RequestedCurrent;
uint16			   	Tess_Input_RequestedDTC;


void Tess_Act_StateMachineInit(void);
void Tess_Act_StateMachine(void);

#endif /* TESS_ACT_STATEMACHINE_H_ */
