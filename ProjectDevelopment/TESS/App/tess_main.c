/*
 * tess_main.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Axinte Andrei
 */
#include "tess_main.h"

void TessMainInit(void)
{
    Tess_Act_StateMachineInit();
    Tess_Mip_Init();
    Tess_MotCtrl_Init();
}

void TessMain(void)
{
	Tess_ActMng_Inputs();
	Tess_Act_StateMachine();
    Tess_Mip_Main();
    Tess_MotCtrl_Main();
    Tess_Mop_Main();
}


