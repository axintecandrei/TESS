/*
 * tess_sys_constants.h
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_SYS_CONSTANTS_H_
#define TESS_SYS_CONSTANTS_H_

#define TESS_TS                      (0.0001F)
#define TESS_mV_V                    (0.001F)
#define TESS_RAD_TO_RPM              (9.54929658F)

/*Motor Param*/
#define TESS_GEAR_RATIO              (75.0F)
#define TESS_ENCODER_PPR             (11.0F)
#define TESS_MOTOR_NUMBERS           (4U)
#define TESS_M1_RESISTANCE           (3.1F)        /*Ohm*/
#define TESS_M2_RESISTANCE           (3.1F)        /*Ohm*/
#define TESS_M3_RESISTANCE           (3.1F)        /*Ohm*/
#define TESS_M4_RESISTANCE           (8.4F)        /*Ohm*/

#define TESS_M1_INDUCTANCE           (0.00248F)    /*H*/
#define TESS_M2_INDUCTANCE           (0.00248F)    /*H*/
#define TESS_M3_INDUCTANCE           (0.00248F)    /*H*/
#define TESS_M4_INDUCTANCE           (0.001558F)   /*H*/

#define TESS_M1_KE                   (4.252E-3)    /*V/rad/s*/
#define TESS_M2_KE                   (4.252E-3)    /*V/rad/s*/
#define TESS_M3_KE                   (4.252E-3)    /*V/rad/s*/
#define TESS_M4_KE                   (4.516E-3)    /*V/rad/s*/

#define TESS_MAX_REQ_VOLT            (4500)        /*mV*/
#define TESS_MAX_REQ_CURRENT         (3500)        /*mA*/

/*Feedback ratios*/
#define TESS_CURRENT_SENSOR_GAIN     (227.0F)       /*mV/A*/
#define TESS_CURRENT_SENSOR_GAIN_N   (161.5F)       /*mV/A*/
#define TESS_CURRENT_SENSOR_OFFSET   (2599.0F)       /*mV/A*/
#define TESS_VOLTAGE_DIV_RATIO       (3.0F)


#endif /* TESS_SYS_CONSTANTS_H_ */
