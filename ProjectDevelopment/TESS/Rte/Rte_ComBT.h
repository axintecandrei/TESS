/*
 * Rte_ComBL.h
 *
 *  Created on: Jan 29, 2022
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_COMBT_H_
#define RTE_RTE_COMBT_H_

#include "StandardTypes.h"

#define TESS_BT_BUFF_LEN    (2U)

typedef struct
{
	uint8 Ignition;
	uint8 Command;
}tess_bt_frame_t;

extern uint8 TessBT_RX_Buff[TESS_BT_BUFF_LEN];
extern tess_bt_frame_t TessBTFrame;


extern void Tess_ComBT_RXClbk(void);

#endif /* RTE_RTE_COMBT_H_ */
