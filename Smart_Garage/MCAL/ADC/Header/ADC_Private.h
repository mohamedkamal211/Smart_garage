/*
 * ADC_Private.h
 *
 *  Created on: Dec 4, 2022
 *      Author: LENOVO
 */

#ifndef MCAL_ADC_HEADER_ADC_PRIVATE_H_
#define MCAL_ADC_HEADER_ADC_PRIVATE_H_

#define Division_Factor2     0b0
#define Division_Factor4     0b010
#define Division_Factor8     0b011
#define Division_Factor16    0b100
#define Division_Factor32    0b101
#define Division_Factor64    0b110
#define Division_Factor128   0b111

#define ADC_PRESC_MASK       0b11111000

//ADC Channels
#define ADC0       0b00000
#define ADC1       0b00001
#define ADC2       0b00010
#define ADC3       0b00011
#define ADC4       0b00100
#define ADC5       0b00101
#define ADC6       0b00110
#define ADC7       0b00111

#endif /* MCAL_ADC_HEADER_ADC_PRIVATE_H_ */
