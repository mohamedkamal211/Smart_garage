/*
 * ADC_Prog.c
 *
 *  Created on: Dec 4, 2022
 *      Author: LENOVO
 */

#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macros.h"
#include "../../../Common/STD_Types.h"
#include "../Header/ADC_Interface.h"
#include "../Header/ADC_Register.h"

void ADC_VoidInit(void)
{
	//AVCC as reference voltage
	Set_Bit(ADMUX,ADMUX_REFS0);
	Clear_Bit(ADMUX,ADMUX_REFS1);

	//Activate Left adjust result
	Set_Bit(ADMUX,ADMUX_ADLAR);

	//ADC Prescaler Selections
	ADCSRA &= ADC_PRESC_MASK ;
	ADCSRA |= ADC_PRESC      ;

	//Enable peripheral
	Set_Bit(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_U8GetChannelReading(u8 ADC_Channel)
{
	//Clear the MUX bits in ADMUX register
	ADMUX &= 0b11100000  ;
	//Set the required Channel into the MUX bits
	ADMUX |= ADC_Channel ;

	//Start conversion
	Set_Bit(ADCSRA,ADCSRA_ADSC);

	//Polling (busy waiting) until the conversion complete flage is set
	while((Get_Bit(ADCSRA,ADCSRA_ADIF))==0);
	//clear the conversion complete flag
	Set_Bit(ADCSRA,ADCSRA_ADIF);

	//Return the reading
	return ADCH;
}
u8 LM35_U8GetChannelReading(u8 LM35_Channel)
{
	//Clear the MUX bits in ADMUX register
	ADMUX &= 0b11100000  ;
	//Set the required Channel into the MUX bits
	ADMUX |= LM35_Channel ;

	//Start conversion
	Set_Bit(ADCSRA,ADCSRA_ADSC);
	//Polling (busy waiting) until the conversion complete flage is set
	while((Get_Bit(ADCSRA,ADCSRA_ADIF))==0);
	//clear the conversion complete flag
	Set_Bit(ADCSRA,ADCSRA_ADIF);

	//Transformation digital to degree
   u16 TEMP_Degree = (u32)((u32)ADCH*500UL)/256UL;

   return TEMP_Degree ;
}


