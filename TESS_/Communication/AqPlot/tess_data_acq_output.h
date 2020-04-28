/**
  ******************************************************************************
  * File Name          : tess_data_acq_output.h
  * Author			   : Axinte Andrei
  * Description        : IO pin mode setting header file
  ******************************************************************************
**/
#ifndef __tess_data_acq_output_h__
#define __tess_data_acq_output_h__


#include "../_Main_/config.h"
#include "tess_ring_buffer.h"
#include "../LowLevelDrivers/UserDefined/lld_usart.h"
/*Include the needed files so the DAS
 * can have access to the variable
 * to be send during measurement*/



/*End Include*/

#if CFG_ACQ_ON

/*DEFINES*/
#define ACQ_BUFFER_SIZE 26

#define ACQ_HEADER      0x55
#define ACQ_FOOTER      0x77

#define DAS_START_MEAS  0x31
#define DAS_STOP_MEAS   0x30
#define DAS_ACK         0x35

typedef enum tess_das_states_e
{
	DAS_StandBy ,
	DAS_SendPackage,
	DAS_StartMeas,
	DAS_ResumePackSend,
	DAS_KeepPacking ,
	DAS_StopOfMeasurement ,
}tess_das_states_t;


/*VARIABLES*/
tess_das_states_t PORT__TessDasStates;
#define Set_TessDasStates(v) (PORT__TessDasStates = (v))
#define Get_TessDasStates()   (*((const tess_das_states_t*) &PORT__TessDasStates))

r_buff_data_t TESS_DATA_ACQ_BUFFER;
r_buff_data_t TESS_DMA_BUFFER;

/*FUNCTIONS*/
void TESS_DAS_INIT();
void TESS_DAS_MAIN();
void TESS_DAS_UPDATE_BUFFER();
void TESS_DAS_GET_COMMANDS(uint8_t command);

#endif /*CFG_ACQ_ON*/
#endif /*__tess_data_acq_output_h__*/

