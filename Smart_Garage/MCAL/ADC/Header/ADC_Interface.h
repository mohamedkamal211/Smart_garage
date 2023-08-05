/*
 * ADC_Interface.h
 *
 *  Created on: Dec 4, 2022
 *      Author: LENOVO
 */

#ifndef MCAL_ADC_HEADER_ADC_INTERFACE_H_
#define MCAL_ADC_HEADER_ADC_INTERFACE_H_

#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

void ADC_VoidInit(void);
u8 ADC_U8GetChannelReading(u8 ADC_Channel);
u8 LM35_U8GetChannelReading(u8 LM35_Channel);
u8 LDR_U8GetChannelReading(u8 LDR_Channel);

#endif /* MCAL_ADC_HEADER_ADC_INTERFACE_H_ */
