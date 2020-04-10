/**
  ******************************************************************************
  * File Name          : tess_mip_bemfobs.h
  * Author			       : Axinte Andrei
  * Description        : B-emf and speed estimator module module header file
  ******************************************************************************
**/
#ifndef __tess_mip_bemfest_h__
#define __tess_mip_bemfest_h__


/*INCLUDES*/

#include "tess_mip_bemfest_if.h"

/*DEFINES*/
#define Ts 500
#define RESISTANCE 2    /*Ohm*/
#define INDUCTANCE 651  /*uH*/
#define BEMF_CONST 2.728 /*rpm/v*/

/*FUNCTIONS*/


/*VARIABLES*/
unsigned_int16_t TESS_MIP_BEMFEST_CURRLEFT_K1;
unsigned_int16_t TESS_MIP_BEMFEST_CURRRIGHT_K1;

#endif /*__tess_mip_bemfest_h__*/
