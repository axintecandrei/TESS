/*
 * tess_sys_constants.h
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_SYS_CONSTANTS_H_
#define TESS_SYS_CONSTANTS_H_

#define TESS_TS                      (0.0005F)
#define TESS_mV_V                    (0.001F)
#define TESS_RAD_TO_RPM              (30.0F/3.141592653F)

/*Motor Param*/
#define TESS_GEAR_RATIO              (25) /*16.9*/
#define TESS_MOTOR_NUMBERS           (4U)
#define TESS_M1_RESISTANCE           (3.1F)        /*Ohm*/
#define TESS_M2_RESISTANCE           (3.1F)        /*Ohm*/
#define TESS_M3_RESISTANCE           (3.1F)        /*Ohm*/
#define TESS_M4_RESISTANCE           (8.4F)        /*Ohm*/

#define TESS_M1_INDUCTANCE           (0.00249F)/*(0.001558F)*/   /*H*/
#define TESS_M2_INDUCTANCE           (0.001558F)   /*H*/
#define TESS_M3_INDUCTANCE           (0.001558F)   /*H*/
#define TESS_M4_INDUCTANCE           (0.001558F)   /*H*/

#define TESS_M1_KE                   (4.252E-3)    /*V/rad/s*/
#define TESS_M2_KE                   (4.252E-3)    /*V/rad/s*/
#define TESS_M3_KE                   (4.252E-3)    /*V/rad/s*/
#define TESS_M4_KE                   (4.516E-3)    /*V/rad/s*/

#define TESS_MAX_REQ_VOLT            (3000)        /*mV*/
#define TESS_MAX_REQ_CURRENT         (2000)        /*mV*/

/*Feedback ratios*/
#define TESS_CURRENT_SENSOR_GAIN     (0.652F)       /*mV/A*/
#define TESS_VOLTAGE_DIV_RATIO       (3.0F)


#endif /* TESS_SYS_CONSTANTS_H_ */
