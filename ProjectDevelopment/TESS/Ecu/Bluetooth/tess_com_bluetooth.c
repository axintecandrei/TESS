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
	Tess_ComBL_DecodeFrame();
}

static void Tess_ComBT_DecodeFrame()
{

}
