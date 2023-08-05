/*
 * PORT_Prog.c
 *
 *  Created on: Oct 30, 2022
 *      Author: LENOVO
 */

#include "../../../Common/STD_Types.h"
#include "../../../Common/Bit_Math.h"
#include "../Header/PORT_Config.h"
#include "../Header/PORT_Interface.h"
#include "../Header/PORT_Private.h"
#include "../Header/PORT_Register.h"


void PORT_VoidInit()
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;

	PORTA = PORTA_InitValue ;
	PORTB = PORTB_InitValue ;
	PORTC = PORTC_InitValue ;
	PORTD = PORTD_InitValue ;
}
