/*
 * PORT_Private.h
 *
 *  Created on: Oct 30, 2022
 *      Author: LENOVO
 */

#ifndef MCAL_PORT_HEADER_PORT_PRIVATE_H_
#define MCAL_PORT_HEADER_PORT_PRIVATE_H_

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)         CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_DIR              CONC(PORTA_Pin7_Dir,PORTA_Pin6_Dir,PORTA_Pin5_Dir,PORTA_Pin4_Dir,PORTA_Pin3_Dir,PORTA_Pin2_Dir,PORTA_Pin1_Dir,PORTA_Pin0_Dir)
#define PORTB_DIR              CONC(PORTB_Pin7_Dir,PORTB_Pin6_Dir,PORTB_Pin5_Dir,PORTB_Pin4_Dir,PORTB_Pin3_Dir,PORTB_Pin2_Dir,PORTB_Pin1_Dir,PORTB_Pin0_Dir)
#define PORTC_DIR              CONC(PORTC_Pin7_Dir,PORTC_Pin6_Dir,PORTC_Pin5_Dir,PORTC_Pin4_Dir,PORTC_Pin3_Dir,PORTC_Pin2_Dir,PORTC_Pin1_Dir,PORTC_Pin0_Dir)
#define PORTD_DIR              CONC(PORTD_Pin7_Dir,PORTD_Pin6_Dir,PORTD_Pin5_Dir,PORTD_Pin4_Dir,PORTD_Pin3_Dir,PORTD_Pin2_Dir,PORTD_Pin1_Dir,PORTD_Pin0_Dir)

#define PORTA_InitValue        CONC(PORTA_Pin7InitValue,PORTA_Pin6InitValue,PORTA_Pin5InitValue,PORTA_Pin4InitValue,PORTA_Pin3InitValue,PORTA_Pin2InitValue,PORTA_Pin1InitValue,PORTA_Pin0InitValue)
#define PORTB_InitValue        CONC(PORTB_Pin7InitValue,PORTB_Pin6InitValue,PORTB_Pin5InitValue,PORTB_Pin4InitValue,PORTB_Pin3InitValue,PORTB_Pin2InitValue,PORTB_Pin1InitValue,PORTB_Pin0InitValue)
#define PORTC_InitValue        CONC(PORTC_Pin7InitValue,PORTC_Pin6InitValue,PORTC_Pin5InitValue,PORTC_Pin4InitValue,PORTC_Pin3InitValue,PORTC_Pin2InitValue,PORTC_Pin1InitValue,PORTC_Pin0InitValue)
#define PORTD_InitValue        CONC(PORTD_Pin7InitValue,PORTD_Pin6InitValue,PORTD_Pin5InitValue,PORTD_Pin4InitValue,PORTD_Pin3InitValue,PORTD_Pin2InitValue,PORTD_Pin1InitValue,PORTD_Pin0InitValue)

#endif /* MCAL_PORT_HEADER_PORT_PRIVATE_H_ */
