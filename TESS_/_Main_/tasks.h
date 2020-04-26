#ifndef __TASKS_H
#define __TASKS_H

#include "../LowLevelDrivers/MCULegacy/HAL/Inc/stm32f4xx_hal.h"
#include "../Communication/FreeMaster/freemaster.h"
#include "../Communication/FreeMaster/freemaster_private.h"

#include "../LowLevelDrivers/UserDefined/lld_adc.h"
#include "../Communication/AqPlot/tess_data_acq_output.h"

void _100US_LOOP (void);

void _2MS_LOOP (void);

void _10MS_LOOP (void);


#endif /*__TASKS_H*/
