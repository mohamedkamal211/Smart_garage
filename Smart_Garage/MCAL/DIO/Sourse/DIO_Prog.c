/*
 * DIO_Prog.c
 *
 *  Created on: Oct 22, 2022
 *      Author: LENOVO
 */

#include "../Header/DIO_Interface.h"

#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macros.h"
#include "../../../Common/STD_Types.h"


void DIO_VoidSetPinNumDir(u8 GroupNum,u8 PinNum ,u8 Dir){
	if ( GroupNum <= DIO_GroupD && GroupNum >= DIO_GroupA && PinNum <= DIO_Pin7&& PinNum >= DIO_Pin0 )
	{
		if(Dir == Output_Pin){
			switch (GroupNum){
			case DIO_GroupA : Set_Bit(DIO_DDRA,PinNum); break ;
			case DIO_GroupB : Set_Bit(DIO_DDRB,PinNum); break ;
			case DIO_GroupC : Set_Bit(DIO_DDRC,PinNum); break ;
			case DIO_GroupD : Set_Bit(DIO_DDRD,PinNum); break ;
			}
		}
		else if(Dir == Input_Pin){
			switch (GroupNum){
			case DIO_GroupA : Clear_Bit(DIO_DDRA,PinNum); break ;
			case DIO_GroupB : Clear_Bit(DIO_DDRB,PinNum); break ;
			case DIO_GroupC : Clear_Bit(DIO_DDRC,PinNum); break ;
			case DIO_GroupD : Clear_Bit(DIO_DDRD,PinNum); break ;
			}
		}
	}
}
void DIO_VoidSetPinNumValue(u8 GroupNum,u8 PinNum ,u8 value){
	if ( GroupNum <= DIO_GroupD && GroupNum >= DIO_GroupA && PinNum <= DIO_Pin7&& PinNum >= DIO_Pin0 ){
		if(value == High_Pin){
			switch (GroupNum){
			case DIO_GroupA : Set_Bit(DIO_PORTA,PinNum); break ;
			case DIO_GroupB : Set_Bit(DIO_PORTB,PinNum); break ;
			case DIO_GroupC : Set_Bit(DIO_PORTC,PinNum); break ;
			case DIO_GroupD : Set_Bit(DIO_PORTD,PinNum); break ;
			}
		}
		if(value == Low_Pin){
			switch (GroupNum){
			case DIO_GroupA : Clear_Bit(DIO_PORTA,PinNum); break ;
			case DIO_GroupB : Clear_Bit(DIO_PORTB,PinNum); break ;
			case DIO_GroupC : Clear_Bit(DIO_PORTC,PinNum); break ;
			case DIO_GroupD : Clear_Bit(DIO_PORTD,PinNum); break ;

			}
		}
	}
}
u8   DIO_U8GetPinNumValue(u8 GroupNum,u8 PinNum ){
	if ( GroupNum <= DIO_GroupD && GroupNum >= DIO_GroupA && PinNum <= DIO_Pin7 && PinNum >= DIO_Pin0 ){
		switch(GroupNum){
		case DIO_GroupA : return Get_Bit(DIO_PINA,PinNum);
		case DIO_GroupB : return Get_Bit(DIO_PINB,PinNum);
		case DIO_GroupC : return Get_Bit(DIO_PINC,PinNum);
		case DIO_GroupD : return Get_Bit(DIO_PIND,PinNum);

		}
	}
	return -1 ;
}

void DIO_VoidSetPortDir(u8 GroupNum,u8 Dir){
	if (GroupNum <= DIO_GroupD && GroupNum >= DIO_GroupA ){
		switch (GroupNum){
		case DIO_GroupA : DIO_DDRA = Dir ; break ;
		case DIO_GroupB : DIO_DDRB = Dir ; break ;
		case DIO_GroupC : DIO_DDRC = Dir ; break ;
		case DIO_GroupD : DIO_DDRD = Dir ; break ;
		}
	}
}
void DIO_VoidSetPortValue(u8 GroupNum,u8 value){
	if (GroupNum <= DIO_GroupD && GroupNum >= DIO_GroupA ){
		switch (GroupNum){
		case DIO_GroupA : DIO_PORTA = value ; break ;
		case DIO_GroupB : DIO_PORTB = value ; break ;
		case DIO_GroupC : DIO_PORTC = value ; break ;
		case DIO_GroupD : DIO_PORTD = value ; break ;
		}
	}
}
u8   DIO_U8GetPortValue(u8 GroupNum){
	if (GroupNum <= DIO_GroupD && GroupNum >= DIO_GroupA ){
		switch (GroupNum){
		case DIO_GroupA : return DIO_PINA ;
		case DIO_GroupB : return DIO_PINB ;
		case DIO_GroupC : return DIO_PINC ;
		case DIO_GroupD : return DIO_PIND ;
		}
	}
	return -1 ;
}
