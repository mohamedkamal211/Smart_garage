/*
 * EXTI_Interface.h
 *
 *  Created on: Nov 7, 2022
 *      Author: LENOVO
 */

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8Enable(u8 Copy_u8Int);
u8 EXTI_u8Disable(u8 Copy_u8Int);
u8 EXTI_u8Int0Callback(void (*Copy_pvFunc)(void));
u8 EXTI_u8Int1Callback(void (*Copy_pvFunc)(void));
u8 EXTI_u8Int2Callback(void (*Copy_pvFunc)(void));

#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
