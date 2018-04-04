/**
  ******************************************************************************
  * File Name          : tess_state_machine_if.h
  * Author			   : Axinte Andrei
  * Description        : State machine module interface header file
  ******************************************************************************
**/
#ifndef __tess_state_machine_if_h__
#define __tess_state_machine_if_h__

/*INLCUDES*/
#include "tess_conf.h"
#include "tess_sal_types.h"

/*PORTS*/

signed_int16_t PORT__TessStateMachReqSpeed;

#define Set_TessStateMachReqSpeed(x) (PORT__TessStateMachReqSpeed = (x))
#define Get_TessStateMachReqSpeed()   (*((const signed_int16_t *) &PORT__TessStateMachReqSpeed))

signed_int16_t PORT__TessStateMachReqDir;

#define Set_TessStateMachReqDir(x) (PORT__TessStateMachReqDir = (x))
#define Get_TessStateMachReqDir()   (*((const signed_int16_t *) &PORT__TessStateMachReqDir))

signed_int32_t PORT__TessStateMachReqTorque;

#define Set_TessStateMachReTorque(x) (PORT__TessStateMachReqTorque = (x))
#define Get_TessStateMachReqTorque()   (*((const signed_int32_t *) &PORT__TessStateMachReqTorque))
/*FUNCTIONS*/

extern void TESS_STATE_MACHINE_INIT();

extern void TESS_STATE_MACHINE_MAIN();

#endif /*__tess_state_machine_if_h__*/
