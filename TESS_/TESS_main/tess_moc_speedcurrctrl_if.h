/**
  ******************************************************************************
  * File Name          : tess_mip_currvoltproc_if.h
  * Author			       : Axinte Andrei
  * Description        : Current And voltace procesing module interface header file
  ******************************************************************************
**/
#ifndef __tess_moc_speedcurrctrl_if_h__
#define __tess_moc_speedcurrctrl_if_h__

/*INLCUDES*/
#include "tess_sal_types.h"
#include "tess_math.h"
#include "tess_bfu_io.h"
#include "tess_bfu_pwm.h"
#include "tess_mip_currvoltproc.h"
#include "tess_mip_bemfest.h"


/*VARIABLES*/
unsigned_int16_t PORT__TessMocReqVoltageLeftM;

#define Set_TessMocReqVoltageLeftM(x) (PORT__TessMocReqVoltageLeftM = (x))
#define Get_TessMocReqVoltageLeftM()   (*((const unsigned_int16_t *) &PORT__TessMocReqVoltageLeftM))

unsigned_int16_t PORT__TessMocReqVoltageRightM;

#define Set_TessMocReqVoltageRightM(x) (PORT__TessMocReqVoltageRightM = (x))
#define Get_TessMocReqVoltageRightM()   (*((const unsigned_int16_t *) &PORT__TessMocReqVoltageRightM))


signed_int16_t PORT__TessStateMachReqSpeed;

#define Set_TessStateMachReqSpeed(x) (PORT__TessStateMachReqSpeed = (x))
#define Get_TessStateMachReqSpeed()   (*((const signed_int16_t *) &PORT__TessStateMachReqSpeed))

signed_int16_t PORT__TessStateMachReqDir;

#define Set_TessStateMachReqDir(x) (PORT__TessStateMachReqDir = (x))
#define Get_TessStateMachReqDir()   (*((const signed_int16_t *) &PORT__TessStateMachReqDir))
/*FUNCTIONS*/

extern void TESS_MOC_SPEEDCURRCTRL_INIT();

extern void TESS_MOC_SPEEDCURRCTRL_MAIN();

#endif /*__tess_moc_speedcurrctrl_if_h__*/
