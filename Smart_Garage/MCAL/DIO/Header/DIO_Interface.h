/*
 * DIO_Interface.h
 *
 *  Created on: Oct 22, 2022
 *      Author: LENOVO
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_


#include "../../../Common/STD_Types.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_Register.h"



void DIO_VoidSetPinNumDir(u8 GroupNum,u8 PinNum ,u8 Dir);
void DIO_VoidSetPinNumValue(u8 GroupNum,u8 PinNum ,u8 value);
u8   DIO_U8GetPinNumValue(u8 GroupNum,u8 PinNum );

void DIO_VoidSetPortDir(u8 GroupNum,u8 Dir);
void DIO_VoidSetPortValue(u8 GroupNum,u8 value);
u8   DIO_U8GetPortValue(u8 GroupNum);


#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
