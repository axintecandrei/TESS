/**
  ******************************************************************************
  * File Name          : tess_state_machine.h
  * Author			   : Axinte Andrei
  * Description        : State machine module interface header file
  ******************************************************************************
**/

#ifdef __cplusplus
extern "C" {
#endif


/*INCLUDES*/
#include "tess_state_machine.h"


void TESS_STATE_MACHINE_INIT()
{
   Set_TessStateMachReqSpeed(0);
   Set_TessStateMachReqDir(0);
   Set_TessStateMachReqTorque(0);
}

void TESS_STATE_MACHINEL_MAIN()
{

}

#ifdef __cplusplus
}
#endif
