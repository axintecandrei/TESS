/*
 * Rte_motorcontrol.h
 *
 *  Created on: Dec 26, 2021
 *      Author: axinteandrei
 */

#ifndef RTE_RTE_MOTORCONTROL_H_
#define RTE_RTE_MOTORCONTROL_H_

#include "tess_moc_types.h"

moc_mot_requests_t PORT__TessMocRequests[4];

#define Set_TessMocSpeedRequest(y,x)    (PORT__TessMocRequests[y].Speed = (x))
#define Get_TessMocSpeedRequest(y)      (PORT__TessMocRequests[y].Speed)

#define Set_TessMocVoltageRequest(y,x)  (PORT__TessMocRequests[y].Speed = (x))
#define Get_TessMocVoltageRequest(y)    (PORT__TessMocRequests[y].Voltage)

#define Set_TessMocCurrentRequest(y,x)  (PORT__TessMocRequests[y].Speed = (x))
#define Get_TessMocCurrentRequest(y)    (PORT__TessMocRequests[y].Current)

extern void Tess_MotCtrl_Init(void);
extern void Tess_MotCtrl_Main(void);

#endif /* RTE_RTE_MOTORCONTROL_H_ */
