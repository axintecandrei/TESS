/*
 * tess_com_bluetooth.c
 *
 *  Created on: Jan 29, 2022
 *      Author: axinteandrei
 */

#include "tess_com_bluetooth.h"

static void Tess_ComBT_DecodeFrame();

void Tess_ComBT_Init(void)
{

}

void Tess_ComBT_RXClbk(void)
{
	/*Decode Frame*/
	Tess_ComBT_DecodeFrame();
}

static void Tess_ComBT_DecodeFrame()
{
	Set_TessActMngRemoteEN(STD_ON);
	/*Get all data from DMA buffer*/
	if(TessBT_RX_Buff[0] == 'A')
	{
		TessBTFrame.Ignition = STD_ON;
		TessBTFrame.Command  = TessBT_RX_Buff[1];
	}
	else if(TessBT_RX_Buff[0] == '0')
	{
		TessBTFrame.Ignition = STD_OFF;
		TessBTFrame.Command  = 0xFF;
	}
	else
	{

	}


}
