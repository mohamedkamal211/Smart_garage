/*
 * main.c
 *
 *  Created on: Oct 22, 2022
 *      Author: LENOVO
 */
#include <util/delay.h>

#include "../MCAL/DIO/Header/DIO_Interface.h"
#include "../MCAL/EXTI/Header/EXTI_Interface.h"
#include "../MCAL/GIE/Header/GIE_Interface.h"
#include "../MCAL/ADC/Header/ADC_Interface.h"
#include "../MCAL/PORT/Header/PORT_Interface.h"

#include "../Common/Macros.h"
#include "../Common/Bit_Math.h"
#include "../Common/STD_Types.h"

#include "../HAL/LCD/Header/LCD_Interface.h"
#include "../HAL/SERVO_MOTOR/HEADER/SERVO_Interface.h"

#include "Confige.h"


void main()
{

	DIO_VoidSetPortDir(DIO_GroupB,Output_Pin);
	DIO_VoidSetPinNumDir(LDR_Port,LDR_Pin,Input_Pin);//LDR
	DIO_VoidSetPinNumDir(DHT22_Port,DHT22_Pin,Input_Pin);//DHT22
	DIO_VoidSetPinNumDir(Buzzer_Port,Buzzer_Pin,Output_Pin);//Buzzer
	DIO_VoidSetPinNumDir(LEDS_Port,LEDS_Pin,Output_Pin);//LEDS
	ADC_VoidInit();
	LCD_VoidInit();
	Servo_VoidInitD4();
	servo_init();


	while(1)
	{
		static  u8 All_Places   = 5 ;
		static  u8  Used_Places = 0 ;
		static 	u16 Get_Light   = 0 ;
		static 	u16 Get_Temp    = 0 ;
		static  u8  New_Car     = 1 ;
		static  u8  Departing_Car = 1;
		u8 Get_IR1 = DIO_U8GetPinNumValue(IR_Port,IR1_Pin);
		u8 Get_IR2 = DIO_U8GetPinNumValue(IR_Port,IR2_Pin);
		u8 Get_IR3 = DIO_U8GetPinNumValue(IR_Port,IR3_Pin);
		u8 Get_IR4 = DIO_U8GetPinNumValue(IR_Port,IR4_Pin);
		//LCD display Available barking
		LCD_VoidSendDataString(" Available ");
		LCD_VoidSendNumber(All_Places - Used_Places);
		//LCD display degree of temprature
		LCD_VoidGoToXY(1,0);
		LCD_VoidSendDataString("Temperature ");
		LCD_VoidSendNumber(Get_Temp);

		Get_Light = ADC_U8GetChannelReading(ADC0);
		Get_Temp  = LM35_U8GetChannelReading(ADC1)/3;
		//if IR Sensor 1 read movement And there are available places , the Servo 1 will open the door
		if(Get_IR1 == 0 &&  Used_Places < All_Places)
		{
			Servo_VoidRotateAngleD4(90);
			_delay_ms(200);
		}
		//If IR sensor 2 read movement The Servo 1 will close the door & LCD count available less 1
		if(Get_IR2 == 0) {
			_delay_ms(200);
			Servo_VoidRotateAngleD4(0);
			if(New_Car == 1 && Used_Places < All_Places) {
				Used_Places++;
				New_Car = 0 ;
			}


		} else {
			New_Car = 1 ;
		}
		//if IR Sensor 3 read movement , the Servo 2 will open the door
		if(Get_IR3 == 0 && Used_Places > 0)
		{
			servo_set_angle(0);
			_delay_ms(200);
		}
		//If IR sensor 4 read movement The Servo 2 will close the door & LCD count available more 1
		if(Get_IR4 == 0) {
			_delay_ms(200);
			servo_set_angle(90);
			if(Departing_Car == 1 && Used_Places > 0) {
				Used_Places--;
				Departing_Car = 0 ;
			}

		} else {
			Departing_Car = 1;
		}
		//If Light bigger than 150 Deg , LEDS will work
		if (Get_Light <150)
		{
			DIO_VoidSetPinNumValue(LEDS_Port,LEDS_Pin,High_Pin);
			_delay_ms(50);
		}
		else if (Get_Light >=150)
		{
			DIO_VoidSetPinNumValue(LEDS_Port,LEDS_Pin,Low_Pin);
			_delay_ms(50);
		}

		//If Temp bigger than 50 Deg , Buzzer will work
		if (Get_Temp >=50)
		{
			DIO_VoidSetPinNumValue(Buzzer_Port,Buzzer_Pin,High_Pin);
			_delay_ms(50);
		}
		else if (Get_Temp <50)
		{
			DIO_VoidSetPinNumValue(Buzzer_Port,Buzzer_Pin,Low_Pin);
			_delay_ms(50);
		}


		LCD_VoidClear();
	}
}




