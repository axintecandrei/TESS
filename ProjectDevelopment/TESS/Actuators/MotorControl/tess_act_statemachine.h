/*
 * tess_act_statemachine.h
 *
 *  Created on: Jun 19, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_ACT_STATEMACHINE_H_
#define TESS_ACT_STATEMACHINE_H_

#include "stdint.h"


#define Moc_StandBy   ( 1)
#define Moc_Pwm       ( 2)
#define Moc_Voltage   ( 4)
#define Moc_Current   ( 8)
#define Moc_Speed     (16)


#define ControlWord_StandBy              (Moc_StandBy)                                     /*1*/
#define ControlWord_Pwm                  (Moc_Pwm )                                         /*2*/
#define ControlWord_Voltage              (Moc_Pwm | Moc_Voltage)                           /*6*/
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
    uint8_t       ControlWord;
    ControlMode_t CurrentMode;
    ControlMode_t RequestedMode;

}moc_statemachine_t;

moc_statemachine_t MotCtrlStateMachine;

void Tess_Act_StateMachineInit(void);
void Tess_Act_StateMachine(void);
#endif /* TESS_ACT_STATEMACHINE_H_ */
