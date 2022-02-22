/*
 * tess_com_bluetooth.h
 *
 *  Created on: Jan 29, 2022
 *      Author: axinteandrei
 */

#ifndef ECU_BLUETOOTH_TESS_COM_BLUETOOTH_H_
#define ECU_BLUETOOTH_TESS_COM_BLUETOOTH_H_

#include "StandardTypes.h"
#include "Rte_ComBT.h"
#include "Rte_actuatormanager.h"

uint8 TessBT_RX_Buff[TESS_BT_BUFF_LEN];
tess_bt_frame_t TessBTFrame;

#endif /* ECU_BLUETOOTH_TESS_COM_BLUETOOTH_H_ */
