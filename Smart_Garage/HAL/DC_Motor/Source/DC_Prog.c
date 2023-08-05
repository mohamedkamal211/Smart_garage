/*
 * DC_Prog.c
 *
 *  Created on: Nov 2, 2022
 *      Author: LENOVO
 */

#include "../../../MCAL/DIO/Header/DIO_Config.h"
#include "../../../MCAL/DIO/Header/DIO_Private.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/DIO/Header/DIO_Register.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macros.h"
#include "../../../Common/STD_Types.h"
#include "../Header/DC_Config.h"
#include "../Header/DC_Interface.h"
#include "../Header/DC_Private.h"

void DC_VoidSetDir(void)
{
	DIO_VoidSetPinNumDir(DC_DDR,DC_LeftPin,Output_Pin);
	DIO_VoidSetPinNumDir(DC_DDR,DC_RightPin,Output_Pin);
}
void DC_VoidRouterRight()
{
	DIO_VoidSetPinNumValue(DC_Port,DC_LeftPin,Low_Pin);
	DIO_VoidSetPinNumValue(DC_Port,DC_RightPin,High_Pin);
}
void DC_VoidRouterLeft(void)
{
	DIO_VoidSetPinNumValue(DC_Port,DC_RightPin,Low_Pin);
	DIO_VoidSetPinNumValue(DC_Port,DC_LeftPin,High_Pin);
}
void DC_VoidRouterStop(void)
{
	DIO_VoidSetPinNumValue(DC_Port,DC_RightPin,Low_Pin);
	DIO_VoidSetPinNumValue(DC_Port,DC_LeftPin,Low_Pin);
}
