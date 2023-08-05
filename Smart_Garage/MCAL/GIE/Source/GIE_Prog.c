/*
 * GIE_Prog.c
 *
 *  Created on: Nov 7, 2022
 *      Author: LENOVO
 */

#include "../Header/GIE_Interface.h"
#include "../Header/GIE_Register.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_Types.h"
#include "../../../Common/Macros.h"

void GIE_VoidEnable(void)
{
	Set_Bit(SREG,SREG_I);
}
void GIE_VoidDisable(void)
{
	Clear_Bit(SREG,SREG_I);
}

