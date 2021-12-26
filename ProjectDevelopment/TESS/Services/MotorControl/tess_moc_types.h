/*
 * Tess_Act_Types.h
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_ACT_TYPES_H_
#define TESS_ACT_TYPES_H_

#include "StandardTypes.h"
#include "tess_moc_param.h"


/*Motors ID*/
enum
{
    M1 = 0,
    M2,
    M3,
    M4
}Motors;

/*Motor Parameters*/
typedef struct
{
    float R;
    float L;
    float Ke;
}mip_mot_parameters_t;

/*Motor inputs*/
typedef struct
{
    float Voltage;
    float Current;
    float MotorSpeed;
    float WheelSpeed;
}mip_mot_inputs_t;

/*Requests*/
typedef struct
{
    float Speed;
    float Current;
    float Voltage;
}moc_mot_requests_t;

typedef struct
{
    float Error;
    float Pgain;
    float Igain;
    float IntegralPart;
    float ProportionalPart;
    float Sat;
}moc_mot_speed_ctrl_t;

typedef struct
{
    float Error;
    float Pgain;
    float Igain;
    float IntegralPart;
    float ProportionalPart;
    float Sat;
}moc_mot_current_ctrl_t;

typedef struct
{
    /*feedback: volt, current, speed*/
    mip_mot_inputs_t       MotorInputs;
    /*requests Speed, current, voltage*/
    moc_mot_requests_t     Requests;
    /*motor parameters*/
    mip_mot_parameters_t   Param;
    /*speed controller */
    moc_mot_speed_ctrl_t   SpeedCtrl;
    /*current controller*/
    moc_mot_current_ctrl_t CurrentCtrl;

}tess_act_motor_t;

float MipDcLinkVoltage;
tess_act_motor_t Motor[TESS_MOTOR_NUMBERS];

#endif /* TESS_ACT_TYPES_H_ */
