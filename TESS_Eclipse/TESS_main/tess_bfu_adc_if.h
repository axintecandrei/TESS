/**
  ******************************************************************************
  * File Name          : tess_bfu_adc_if.h
  * Author			   : Axinte Andrei
  * Description        : ADC module interface header file
  ******************************************************************************
**/
#ifndef __tess_bfu_adc_if_h__
#define __tess_bfu_adc_if_h__

#include "Arduino.h"
#include "tess_sal_types.h"
#include "tess_conf.h"
#include "tess_bfu_io.h"
#include "tess_moc_speedcurrctrl.h"



/*VARIABLES*/
unsigned_int16_t PORT__TessAdcRawCurrRight;

unsigned_int16_t PORT__TessAdcRawCurrLeft;

unsigned_int16_t PORT__TessAdcRawVoltMRight;

unsigned_int16_t PORT__TessAdcRawVoltMLeft;

unsigned_int16_t PORT__TessAdcRawLeftBemfU;

unsigned_int16_t PORT__TessAdcRawLeftBemfV;

#define Set_TessAdcRawCurrRight(x) (PORT__TessAdcRawCurrRight = (x))
#define Get_TessAdcRawCurrRight()   (*((const unsigned_int16_t *) &PORT__TessAdcRawCurrRight))

#define Set_TessAdcRawCurrLeft(x) (PORT__TessAdcRawCurrLeft = (x))
#define Get_TessAdcRawCurrLeft()   (*((const unsigned_int16_t *) &PORT__TessAdcRawCurrLeft))

#define Set_TessAdcRawVoltMRight(x) (PORT__TessAdcRawVoltMRight = (x))
#define Get_TessAdcRawVoltMRight()   (*((const unsigned_int16_t *) &PORT__TessAdcRawVoltMRight))

#define Set_TessAdcRawVoltMLeft(x) (PORT__TessAdcRawVoltMLeft = (x))
#define Get_TessAdcRawVoltMLeft()   (*((const unsigned_int16_t *) &PORT__TessAdcRawVoltMLeft))

#define Set_TessAdcRawLeftBemfU(x) (PORT__TessAdcRawLeftBemfU = (x))
#define Get_TessAdcRawLeftBemfU()   (*((const unsigned_int16_t *) &PORT__TessAdcRawLeftBemfU))

#define Set_TessAdcRawLeftBemfV(x) (PORT__TessAdcRawLeftBemfV = (x))
#define Get_TessAdcRawLeftBemfV()   (*((const unsigned_int16_t *) &PORT__TessAdcRawLeftBemfV))


/*FUNCTIONS*/
extern void TESS_BFU_ADC_INIT();

extern void TESS_BFU_ADC_MAIN();
#endif /*__tess_bfu_adc_if_h__*/

