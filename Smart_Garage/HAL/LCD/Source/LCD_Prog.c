/*
 * LCD_Prog.c
 *
 *  Created on: Oct 24, 2022
 *      Author: LENOVO
 */

#include <util/delay.h>
#include "../Header/LCD_Interface.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_Types.h"
#include "../../../Common/Macros.h"


void LCD_VoidSendCommand(u8 LCD_Command){

	DIO_VoidSetPinNumValue(LCD_CtrlPort,LCD_RsPin,Low_Pin);
	DIO_VoidSetPinNumValue(LCD_CtrlPort,LCD_RwPin,Low_Pin);
	DIO_VoidSetPortValue(LCD_DataPort,LCD_Command);
	DIO_VoidSetPinNumValue(LCD_CtrlPort,LCD_EPin,High_Pin);
	_delay_ms(1);
	DIO_VoidSetPinNumValue(LCD_CtrlPort,LCD_EPin,Low_Pin);
}

void LCD_VoidSendDataChar(u8 LCD_DataChar){

	DIO_VoidSetPinNumValue(LCD_CtrlPort,LCD_RsPin,High_Pin);
	DIO_VoidSetPinNumValue(LCD_CtrlPort,LCD_RwPin,Low_Pin);
	DIO_VoidSetPortValue(LCD_DataPort,LCD_DataChar);
	DIO_VoidSetPinNumValue(LCD_CtrlPort,LCD_EPin,High_Pin);
	_delay_ms(1);
	DIO_VoidSetPinNumValue(LCD_CtrlPort,LCD_EPin,Low_Pin);
}
void LCD_VoidInit(void){
	/* set direction for LCD*/
	DIO_VoidSetPortDir(LCD_DataPort,Output_Port);
	DIO_VoidSetPinNumDir(LCD_CtrlPort,LCD_RsPin,Output_Pin);
	DIO_VoidSetPinNumDir(LCD_CtrlPort,LCD_RwPin,Output_Pin);
	DIO_VoidSetPinNumDir(LCD_CtrlPort,LCD_EPin,Output_Pin);
	/* set Initialize for LCD*/
	_delay_ms(35);
	LCD_VoidSendCommand(0x38);
	_delay_ms(1);
	LCD_VoidSendCommand(0x0C);
	_delay_ms(1);
	LCD_VoidSendCommand(0x01);
	_delay_ms(2);
}
void LCD_VoidSendDataString(const u8* LCD_DataString)
{
	u8 Local_U8Counter = 0;
	while (LCD_DataString[Local_U8Counter] != '\0')
	{
		LCD_VoidSendDataChar(LCD_DataString[Local_U8Counter]);
		Local_U8Counter++ ;
}
}
void LCD_VoidGoToXY(u8 X_Position,u8 Y_Position)
{
	u8 LOCAL_Positon = 0 ;
	if(X_Position == 0){
		LOCAL_Positon = Y_Position ;
	}
	else if (X_Position == 1){
		LOCAL_Positon = Y_Position + 0x40 ;
	}
	Set_Bit(LOCAL_Positon,DIO_Pin7);
	LCD_VoidSendCommand(LOCAL_Positon);
}
void LCD_VoidWriteSpecialChar(u8 *Pattern , u8 Patern_Number ,u8 X_Position,u8 Y_Position)
{
	u8 Counter = 0 ;
	u8 LCD_CGRamAdress = 0 ;
	/*Calculate the CGRAM Address whose each block is 8 bytes */
	LCD_CGRamAdress = Patern_Number*8 ;
	LCD_VoidSendCommand(LCD_CGRamAdress + 64);
for (Counter = 0; Counter < 8 ; Counter ++ ){
	LCD_VoidSendDataChar(Pattern[Counter]);
}
LCD_VoidGoToXY(X_Position,Y_Position);
LCD_VoidSendDataChar(Patern_Number);
}
void LCD_VoidSendNumber(u32 Number)
{
	u8 DigitNumber;
	s8 Counter = -1 , Display;
	u8 Array_Number[10];
	do
	{
		Counter++;
		DigitNumber = Number % 10;
		Array_Number[Counter] = DigitNumber + '0';
		Number /= 10;
	}while(Number != 0);
	for(Display = Counter; Display >= 0; Display--)
	{
		LCD_VoidSendDataChar(Array_Number[Display]);
	}
}

void LCD_VoidClear(void)
{
	LCD_VoidSendCommand(0b0001);
}

