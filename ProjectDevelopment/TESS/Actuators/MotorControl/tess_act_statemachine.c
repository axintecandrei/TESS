/*
 * tess_moc_statemachine.c
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */
#include "tess_act_statemachine.h"


void Tess_MotCtrl_StandbyMode();
void Tess_MotCtrl_PwmMode();
void Tess_MotCtrl_VoltageMode();
void Tess_MotCtrl_CurrentControlMode();
void Tess_MotCtrl_SpeedVoltageMode();
void Tess_MotCtrl_SpeedControlMode();

void Tess_Act_StateMachineInit(void)
{
    MotCtrlStateMachine.CurrentMode   = StandBy;
    MotCtrlStateMachine.RequestedMode = StandBy;
    MotCtrlStateMachine.ControlWord = ControlWord_StandBy;
}


void Tess_Act_StateMachine(void)
{
    switch(MotCtrlStateMachine.CurrentMode)
    {
    case StandBy:
        MotCtrlStateMachine.ControlWord = ControlWord_StandBy;
        Tess_MotCtrl_StandbyMode();
        break;
    case PwmMode:
        MotCtrlStateMachine.ControlWord = ControlWord_Pwm;
        Tess_MotCtrl_PwmMode();
        break;
    case VoltageMode:
        MotCtrlStateMachine.ControlWord = ControlWord_Voltage;
        Tess_MotCtrl_VoltageMode();
        break;
    case CurrentControl:
        MotCtrlStateMachine.ControlWord = ControlWord_CurrentControl;
        Tess_MotCtrl_CurrentControlMode();
        break;
    case SpeedVoltageControl:
        MotCtrlStateMachine.ControlWord = ControlWord_SpeedVoltageControl;
        Tess_MotCtrl_SpeedVoltageMode();
        break;
    case SpeedControl:
        MotCtrlStateMachine.ControlWord = ControlWord_SpeedControl;
        Tess_MotCtrl_SpeedControlMode();
        break;
    default:
        break;
    }
}

void Tess_MotCtrl_StandbyMode()
{

    switch(MotCtrlStateMachine.RequestedMode)
    {
    case PwmMode:
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        MotCtrlStateMachine.CurrentMode = SpeedControl;
        break;
    default:
        break;
    }
}
void Tess_MotCtrl_PwmMode()
{

    switch(MotCtrlStateMachine.RequestedMode)
    {
    case StandBy:
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case VoltageMode:
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        MotCtrlStateMachine.CurrentMode = SpeedControl;
        break;
    default:
        break;
    }
}
void Tess_MotCtrl_VoltageMode()
{

    switch(MotCtrlStateMachine.RequestedMode)
    {
    case StandBy:
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case CurrentControl:
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        MotCtrlStateMachine.CurrentMode = SpeedControl;
        break;
    default:
        break;
    }
}
void Tess_MotCtrl_CurrentControlMode()
{

    switch(MotCtrlStateMachine.RequestedMode)
    {
    case StandBy:
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case SpeedVoltageControl:
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        MotCtrlStateMachine.CurrentMode = SpeedControl;
        break;
    default:
        break;
    }
}

void Tess_MotCtrl_SpeedVoltageMode()
{

    switch(MotCtrlStateMachine.RequestedMode)
    {
    case StandBy:
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedControl:
        MotCtrlStateMachine.CurrentMode = SpeedControl;
        break;
    default:
        break;
    }
}

void Tess_MotCtrl_SpeedControlMode()
{

    switch(MotCtrlStateMachine.RequestedMode)
    {
    case StandBy:
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    default:
        break;
    }
}


