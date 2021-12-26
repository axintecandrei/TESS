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
    Tess_Act_StateMachine();
    Tess_MotCtrl_Main();

}

void TessMainInit(void)
{
    Tess_Act_StateMachineInit();
    Tess_Mip_Init();
    Tess_MotCtrl_Init();
    /*Tess_MotDrv_Init();*/
}
