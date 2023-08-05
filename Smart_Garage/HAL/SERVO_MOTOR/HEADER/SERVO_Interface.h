/*
 * SERVO_Interface.h
 *
 *  Created on: Sep 28, 2022
 *      Author: mhmd wael
 */

#ifndef HAL_SERVO_MOTOR_HEADER_SERVO_INTERFACE_H_
#define HAL_SERVO_MOTOR_HEADER_SERVO_INTERFACE_H_

#include "SERVO_Config.h"
#include "SERVO_Private.h"
#include <avr/io.h>
#include <util/delay.h>


void Servo_VoidInitD4(void);
void Servo_VoidInitD5(void);

void Servo_VoidRotateAngleD4(u8 Local_u8Angle);
//void Servo_VoidRotateAngleD5(u8 Local_u8Angle);


void servo_init();
void servo_set_angle(int angle);

#endif /* HAL_SERVO_MOTOR_HEADER_SERVO_INTERFACE_H_ */
