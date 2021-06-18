/*
 * tess_sys_constants.h
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_SYS_CONSTANTS_H_
#define TESS_SYS_CONSTANTS_H_

#define TESS_TS                   (0.0005F)
#define TESS_mV_V                 (0.001F)
/*Motor Param*/
#define TESS_GEAR_RATIO           (17.9F) /*16.9*/
#define TESS_MOTOR_NUMBERS        (4U)
#define TESS_MOTOR_RESISTANCE     (1.9F)        /*1.35*//*Ohm*/
#define TESS_MOTOR_INDUCTANCE     (0.001558F)   /*H*/
#define TESS_MOTOR_KE             (3.584E-4)    /*V/rad/s*/

/*Feedback ratios*/
#define TESS_CURRENT_SENSOR_GAIN  (0.46F)       /*mV/A*/
#define TESS_VOLTAGE_DIV_RATIO    (3.0F)


#endif /* TESS_SYS_CONSTANTS_H_ */
