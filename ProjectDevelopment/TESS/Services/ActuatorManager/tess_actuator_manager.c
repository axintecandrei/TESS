/*
 * tess_moc_statemachine.c
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */
#include "tess_actuator_manager.h"


void Tess_MotCtrl_StandbyMode();
void Tess_MotCtrl_PwmMode();
void Tess_MotCtrl_VoltageMode();
void Tess_MotCtrl_CurrentControlMode();
void Tess_MotCtrl_SpeedVoltageMode();
void Tess_MotCtrl_SpeedControlMode();
extern void Tess_MotCtrl_ResetInputs(void);

void Tess_Act_StateMachineInit(void)
{
    MotCtrlStateMachine.CurrentMode   = StandBy;
    MotCtrlStateMachine.RequestedMode = StandBy;
    MotCtrlStateMachine.ControlWord = ControlWord_StandBy;
    Tess_Input_RequestedDTC = 500;
}

void Tess_ActMng_Inputs(void)
{
	uint8 MotorIndex;

	MotCtrlStateMachine.RequestedMode = Tess_Input_RequestMode;

	for(MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
	{
		Set_TessMocSpeedRequest(MotorIndex,Tess_Input_RequestedSpeed);
		Set_TessMocVoltageRequest(MotorIndex,Tess_Input_RequestedVoltage);
		Set_TessMocCurrentRequest(MotorIndex,Tess_Input_RequestedCurrent);
		Set_TessMopRequestDtc(MotorIndex,Tess_Input_RequestedDTC);
	}
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
    Set_TessActMngControlWord(MotCtrlStateMachine.ControlWord);
}

void Tess_MotCtrl_StandbyMode()
{
    //Tess_MotCtrl_ResetInputs();

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
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case VoltageMode:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        Tess_MotCtrl_ResetInputs();
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
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case CurrentControl:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        Tess_MotCtrl_ResetInputs();
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
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case SpeedVoltageControl:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        Tess_MotCtrl_ResetInputs();
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
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedControl:
        Tess_MotCtrl_ResetInputs();
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
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        Tess_MotCtrl_ResetInputs();
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    default:
        break;
    }
}


