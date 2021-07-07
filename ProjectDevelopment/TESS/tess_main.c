/*
 * tess_main.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */
#include "tess_main.h"


void TessMain(void)
{
    Tess_Mip_Main();
    Tess_MotCtrl_Main();


#if(!FMSTR_DISABLE)
    {
      FMSTR_Poll();
      FMSTR_Recorder();
     }
#endif
}


void TessMainInit(void)
{
    Tess_Act_StateMachineInit();
    Tess_Mip_Init();
    Tess_MotCtrl_Init();
    Tess_MotDrv_Init();


#if !FMSTR_DISABLE
    FMSTR_Init();
#endif
}