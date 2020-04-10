/**
  ******************************************************************************
  * File Name          : tess_moc_speedcurrctrl.h
  * Author			       : Axinte Andrei
  * Description        : Speed and Current Control module header file
  ******************************************************************************
**/
#ifndef __tess_moc_speedcurrctrl_h__
#define __tess_moc_speedcurrctrl_h__


/*INCLUDES*/

#include "tess_moc_speedcurrctrl_if.h"

/*DEFINES*/
#define FORWARD      1
#define BACKWARD     0
#define TS           500
#define DC_LINK_VOLT (float32)5.3
#define CLOSED_LOOP  0

/*STRUCTS*/
typedef struct speed_ctrl
{
  float32 OUTPUT_CURRENT;
  float32 OUTPUT_CURRENT_K1;
  float32 ERROR_SPEED;
  float32 P_GAIN;
  float32 I_GAIN;
  float32 P_PART;
  float32 I_PART;
}speed_ctrl_t;

typedef struct current_ctrl
{
  float32 OUTPUT_VOLTAGE;
  float32 OUTPUT_VOLTAGE_K1;
  float32 ERROR_CURRENT;
  float32 P_GAIN;
  float32 I_GAIN;
}current_ctrl_t;



/*VARIABLES*/

speed_ctrl_t   TESS_MOC_SPEEDCTRL_LEFTMOTOR;
speed_ctrl_t   TESS_MOC_SPEEDCTRL_RIGHTMOTOR;
current_ctrl_t TESS_MOC_CURRCTRL_LEFTMOTOR;
current_ctrl_t TESS_MOC_CURRCTRL_RIGHTMOTOR;

unsigned_char_t TESS_MOC_MOTOR_LEFT_DIR;
unsigned_char_t TESS_MOC_MOTOR_RIGHT_DIR;

#endif /*__tess_moc_speedcurrctrl_h__*/
