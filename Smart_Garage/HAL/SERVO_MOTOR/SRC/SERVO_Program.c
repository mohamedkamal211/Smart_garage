
#include "../../../Common/Macros.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_Types.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/TIMER/Header/Timer_Interface.h"
#include "../HEADER/SERVO_Interface.h"


void Servo_VoidInitD4(void)
{
	/*Notes To use this function :
	 * 1- Timer1 Compare output mode must be set in non inverted pwm channel A or B According to Servo pin
	 * 2- Timer1 Prescaler Must be Divided by 8
	 **********************************************/
	DIO_VoidSetPinNumDir(Servo_Port,Servo_PinD4,Output_Pin);
	TIMER1_VoidInit(TIMER1_FastPWMOnICR1Mode);
	TIMER1_VoidSetICRValue(Servo_PeriodTime);

}

void Servo_VoidRotateAngleD4(u8 Local_u8Angle)
{
	u16 Local_u16OCRValue=0;
	Local_u16OCRValue	=	((5.55555*Local_u8Angle)+1000)	;
#if Servo_PinD4	==	DIO_Pin5
	TIMER_VoidSetCompareMatchValue(TIMER1A,Local_u16OCRValue);
#elif	Servo_PinD4	==	DIO_Pin4
	TIMER_VoidSetCompareMatchValue(TIMER1B,Local_u16OCRValue);
#endif
}

/*void Servo_VoidInitD5(void)
{
	//Notes To use this function :
	 // 1- Timer1 Compare output mode must be set in non inverted pwm channel A or B According to Servo pin
	 //2- Timer1 Prescaler Must be Divided by 8

	DIO_VoidSetPinNumDir(Servo_Port,Servo_PinD5,Output_Pin);
	TIMER1_VoidInit(TIMER1_FastPWMOnICR1Mode);
	TIMER1_VoidSetICRValue(Servo_PeriodTime);

}

void Servo_VoidRotateAngleD5(u8 Local_u8Angle)
{
	u16 Local_u16OCRValue=0;
	Local_u16OCRValue	=	((5.55555*Local_u8Angle)+1000)	;
#if Servo_PinD5	==	DIO_Pin5
	TIMER_VoidSetCompareMatchValue(TIMER1A,Local_u16OCRValue);
#elif	Servo_PinD5	==	DIO_Pin4
	TIMER_VoidSetCompareMatchValue(TIMER1B,Local_u16OCRValue);
#endif
}
*/
void servo_init() {
    SERVO_DDR |= (1 << SERVO_PIN);
}

void servo_set_angle(int angle) {
    int pulse_width = 500 + angle * 11;
    SERVO_PORT |= (1 << SERVO_PIN);
    _delay_us(pulse_width);
    SERVO_PORT &= ~(1 << SERVO_PIN);
    _delay_us(20000 - pulse_width);
}
