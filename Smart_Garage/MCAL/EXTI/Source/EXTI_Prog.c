/*
 * EXTI_Prog.c
 *
 *  Created on: Nov 7, 2022
 *      Author: LENOVO
 */

#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macros.h"
#include "../../../Common/STD_Types.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/EXTI_Interface.h"
#include "../Header/EXTI_Config.h"
#include "../Header/EXTI_Private.h"
#include "../Header/EXTI_Register.h"

void(*INT0_ADDRESS)(void) = NULL;
void(*INT1_ADDRESS)(void) = NULL;
void(*INT2_ADDRESS)(void) = NULL;

void EXTI_voidInt0Init(void)
{
#if 		INT0_SENSE == LOW_LEVEL
			Clear_Bit(MCUCR,MCUCR_ISC01);
			Clear_Bit(MCUCR,MCUCR_ISC00);

#elif		INT0_SENSE == ON_CHANGE
			Clear_Bit(MCUCR,MCUCR_ISC01);
			Set_Bit(MCUCR,MCUCR_ISC00);

#elif		INT0_SENSE == FALLING_EDGE
			Set_Bit(MCUCR,MCUCR_ISC01);
			Clear_Bit(MCUCR,MCUCR_ISC00);

#elif		INT0_SENSE == RISING_EDGE
			Set_Bit(MCUCR,MCUCR_ISC01);
			Set_Bit(MCUCR,MCUCR_ISC00);

#else
#error "Wrong INT0_SENSE configuration option"

#endif

#if			INT0_INIT_STATE == ENABLE
			Set_Bit(GICR,GICR_INT0);
#elif		INT0_INIT_STATE == DISABLE
			Clear_Bit(GICR,GICR_INT0);
#else
#error "Wrong INT0_INIT_STATE configuration option"

#endif
}

void EXTI_voidInt1Init(void)
{
#if 		INT1_SENSE == LOW_LEVEL
			Clear_Bit(MCUCR,MCUCR_ISC11);
			Clear_Bit(MCUCR,MCUCR_ISC10);

#elif		INT1_SENSE == ON_CHANGE
			Clear_Bit(MCUCR,MCUCR_ISC11);
			Set_Bit(MCUCR,MCUCR_ISC10);

#elif		INT1_SENSE == FALLING_EDGE
			Set_Bit(MCUCR,MCUCR_ISC11);
			Clear_Bit(MCUCR,MCUCR_ISC10);

#elif		INT1_SENSE == RISING_EDGE
			Set_Bit(MCUCR,MCUCR_ISC11);
			Set_Bit(MCUCR,MCUCR_ISC10);

#else
#error "Wrong INT1_SENSE configuration option"

#endif

#if			INT1_INIT_STATE == ENABLE
			Set_Bit(GICR,GICR_INT1);
#elif		INT1_INIT_STATE == DISABLE
			Clear_Bit(GICR,GICR_INT1);
#else
#error "Wrong INT1_INIT_STATE configuration option"

#endif
}

void EXTI_voidInt2Init(void)
{
	/*set sens control for INT2 */
#if			INT2_SENSE == FALLING_EDGE
			Clear_Bit(MCUCSR,MCUCSR_ISC2);

#elif		INT2_SENSE == RISING_EDGE
			Set_Bit(MCUCR,MCUCSR_ISC2);

#else
#error "Wrong INT2_SENSE configuration option"

#endif

#if			INT2_INIT_STATE == ENABLE
			Set_Bit(GICR,GICR_INT2);

#elif		INT2_INIT_STATE == DISABLE
			Clear_Bit(GICR,GICR_INT2);
#else
#error "Wrong INT1_INIT_STATE configuration option"

#endif
}
/*Post build Configuration*/

		u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense){
			u8 Local_u8ErrorState = OK;

			switch(Copy_u8Sense){
			case LOW_LEVEL:Clear_Bit(MCUCR,MCUCR_ISC00);Clear_Bit(MCUCR,MCUCR_ISC01);break;
			case ON_CHANGE:Set_Bit(MCUCR,MCUCR_ISC00);Clear_Bit(MCUCR,MCUCR_ISC01);break;
			case FALLING_EDGE:Clear_Bit(MCUCR,MCUCR_ISC00);Set_Bit(MCUCR,MCUCR_ISC01);break;
			case RISING_EDGE:Set_Bit(MCUCR,MCUCR_ISC00);Set_Bit(MCUCR,MCUCR_ISC01);break;
			default:Local_u8ErrorState = NOK;

			}
			return Local_u8ErrorState;

		}

		u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense){
			u8 Local_u8ErrorState = OK;
			switch(Copy_u8Sense){
			case LOW_LEVEL :Clear_Bit(MCUCR,MCUCR_ISC11);Clear_Bit(MCUCR,MCUCR_ISC10);break;
			case ON_CHANGE :Clear_Bit(MCUCR,MCUCR_ISC11);Set_Bit(MCUCR,MCUCR_ISC10);break;
			case FALLING_EDGE :Set_Bit(MCUCR,MCUCR_ISC11);Clear_Bit(MCUCR,MCUCR_ISC10);break;
			case RISING_EDGE :Set_Bit(MCUCR,MCUCR_ISC11);Set_Bit(MCUCR,MCUCR_ISC10);break;
			default :Local_u8ErrorState = 1;


			}

			return Local_u8ErrorState;

		}
		u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense){
			u8 Local_u8ErrorState = OK;
			switch(Copy_u8Sense){
			case FALLING_EDGE :Clear_Bit(MCUCSR,MCUCSR_ISC2);break;
			case RISING_EDGE :Set_Bit(MCUCSR,MCUCSR_ISC2);break;
			default :Local_u8ErrorState = 1;
			}

			return Local_u8ErrorState;

		}
		u8 EXTI_u8Enable(u8 Copy_u8Int){
			u8 Local_u8ErrorState = OK;
			if(Copy_u8Int == INT0_INIT_STATE){
				Set_Bit(GICR,GICR_INT0);
			}
			else if(Copy_u8Int == INT0_INIT_STATE){
				Set_Bit(GICR,GICR_INT1);
			}
			else if(Copy_u8Int == INT2_INIT_STATE){
				Set_Bit(GICR,GICR_INT2);
			}
			else{
				Local_u8ErrorState = NOK;
			}
			return Local_u8ErrorState;

		}
		u8 EXTI_u8Disable(u8 Copy_u8Int){

			u8 Local_u8ErrorState = OK;
			if(Copy_u8Int == INT0_INIT_STATE){
				Clear_Bit(GICR,GICR_INT0);
			}
			else if(Copy_u8Int == INT0_INIT_STATE){
				Clear_Bit(GICR,GICR_INT1);
			}
			else if(Copy_u8Int == INT2_INIT_STATE){
				Clear_Bit(GICR,GICR_INT2);
			}
			else{
				Local_u8ErrorState = NOK;
			}
			return Local_u8ErrorState;

		}


u8 EXTI_u8Int0Callback(void (*Copy_pvFunc)(void)){
	u8 Local_u8ErrorState = OK;

	if(Copy_pvFunc != NULL){

		INT0_ADDRESS = Copy_pvFunc;
	}

	else{
		Local_u8ErrorState = NULL_POINTER;
	}


	return Local_u8ErrorState;

}
u8 EXTI_u8Int1Callback(void (*Copy_pvFunc)(void)){
	u8 Local_u8ErrorState = OK;
	if(Copy_pvFunc != NULL){

		INT1_ADDRESS = Copy_pvFunc;

	}
	else{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8Int2Callback(void (*Copy_pvFunc)(void)){

	u8 Local_u8ErrorState = OK;

	if(Copy_pvFunc != NULL){
		INT2_ADDRESS = Copy_pvFunc;


	}
	else{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;

}

void __vector_1(void)   __attribute__((signal));
void __vector_1(void){

	INT0_ADDRESS();
	INT1_ADDRESS();
	INT2_ADDRESS();
}
