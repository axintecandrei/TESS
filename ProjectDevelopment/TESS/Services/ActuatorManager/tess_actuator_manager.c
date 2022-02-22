/*
 * tess_moc_statemachine.c
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */
#include "tess_actuator_manager.h"

#define TESS_DEMO_POS_DTC    (700)/**/
#define TESS_DEMO_NEG_DTC    (300)

void Tess_MotCtrl_StandbyMode();
void Tess_MotCtrl_PwmMode();
void Tess_MotCtrl_VoltageMode();
void Tess_MotCtrl_CurrentControlMode();
void Tess_MotCtrl_SpeedVoltageMode();
void Tess_MotCtrl_SpeedControlMode();
static void Tess_ActMng_ResetInputs(void);
static void Tess_ActMng_Demo(void);

void Tess_Act_StateMachineInit(void)
{
    MotCtrlStateMachine.CurrentMode   = StandBy;
    MotCtrlStateMachine.RequestedMode = StandBy;
    MotCtrlStateMachine.ControlWord = ControlWord_StandBy;
    Tess_Input_RequestedSpeed = 0;
    Tess_Input_RequestedDTC = 500;
    Set_TessActMngRemoteEN(STD_OFF);  /*default debug mode*/
}

void Tess_ActMng_Inputs(void)
{
	uint8 MotorIndex;
	if(Get_TessActMngRemoteEN() == STD_ON)
	{
		Tess_ActMng_Demo();
	}else
	{
		/*Debug Mode*/
		MotCtrlStateMachine.RequestedMode = Tess_Input_RequestMode;

		for(MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
		{
			Set_TessMocSpeedRequest(MotorIndex,Tess_Input_RequestedSpeed);
			Set_TessMocVoltageRequest(MotorIndex,Tess_Input_RequestedVoltage);
			Set_TessMocCurrentRequest(MotorIndex,Tess_Input_RequestedCurrent);
			Set_TessMopRequestDtc(MotorIndex,Tess_Input_RequestedDTC);
		}
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
    //Tess_ActMng_ResetInputs();

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
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case VoltageMode:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        Tess_ActMng_ResetInputs();
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
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case CurrentControl:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        Tess_ActMng_ResetInputs();
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
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case SpeedVoltageControl:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    case SpeedControl:
        Tess_ActMng_ResetInputs();
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
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedControl:
        Tess_ActMng_ResetInputs();
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
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = StandBy;
        break;
    case PwmMode:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = PwmMode;
        break;
    case VoltageMode:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = VoltageMode;
        break;
    case CurrentControl:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = CurrentControl;
        break;
    case SpeedVoltageControl:
        Tess_ActMng_ResetInputs();
        MotCtrlStateMachine.CurrentMode = SpeedVoltageControl;
        break;
    default:
        break;
    }
}


static void Tess_ActMng_ResetInputs(void)
{
    uint8 MotorIndex = 0;

    for (MotorIndex = 0; MotorIndex < TESS_MOTOR_NUMBERS; MotorIndex++)
    {
		Set_TessMocSpeedRequest(MotorIndex,0);
		Set_TessMocVoltageRequest(MotorIndex,0);
		Set_TessMocCurrentRequest(MotorIndex,0);
		Set_TessMopRequestDtc(MotorIndex,500);
    }
}

static void Tess_ActMng_Demo(void)
{
	if(TessBTFrame.Ignition == STD_ON)
	{
				MotCtrlStateMachine.RequestedMode = PwmMode;
				switch(TessBTFrame.Command)
				{
				case 'f':
				{
					Set_TessMopRequestDtc(0,TESS_DEMO_POS_DTC);
					Set_TessMopRequestDtc(1,TESS_DEMO_POS_DTC);
					Set_TessMopRequestDtc(2,TESS_DEMO_POS_DTC);
					Set_TessMopRequestDtc(3,TESS_DEMO_POS_DTC);
				}
					break;
				case 'b':
				{
					Set_TessMopRequestDtc(0,TESS_DEMO_NEG_DTC);
					Set_TessMopRequestDtc(1,TESS_DEMO_NEG_DTC);
					Set_TessMopRequestDtc(2,TESS_DEMO_NEG_DTC);
					Set_TessMopRequestDtc(3,TESS_DEMO_NEG_DTC);
				}
					break;
				case 'c':
				{
					Set_TessMopRequestDtc(0,TESS_DEMO_NEG_DTC);
					Set_TessMopRequestDtc(1,TESS_DEMO_POS_DTC);
					Set_TessMopRequestDtc(2,TESS_DEMO_POS_DTC);
					Set_TessMopRequestDtc(3,TESS_DEMO_NEG_DTC);
				}
					break;
				case 'd':
				{
					Set_TessMopRequestDtc(0,TESS_DEMO_POS_DTC);
					Set_TessMopRequestDtc(1,TESS_DEMO_NEG_DTC);
					Set_TessMopRequestDtc(2,TESS_DEMO_NEG_DTC);
					Set_TessMopRequestDtc(3,TESS_DEMO_POS_DTC);
				}
					break;
				}
			}
			else
			{
				MotCtrlStateMachine.ControlWord = ControlWord_StandBy;
				Set_TessMopRequestDtc(0,500);
				Set_TessMopRequestDtc(1,500);
				Set_TessMopRequestDtc(2,500);
				Set_TessMopRequestDtc(3,500);
			}
}
