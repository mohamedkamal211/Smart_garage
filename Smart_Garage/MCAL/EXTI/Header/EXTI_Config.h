/*
 * EXTI_Config.h
 *
 *  Created on: Nov 7, 2022
 *      Author: LENOVO
 */

#ifndef MCAL_EXTI_HEADER_EXTI_CONFIG_H_
#define MCAL_EXTI_HEADER_EXTI_CONFIG_H_
/*Options
 * 1- LOW_LEVEL
 * 2- ON_CHANGE
 * 3- FALLING_EDGE
 * 4- RISING_EDGE
 * */
#define INT0_SENSE  FALLING_EDGE
#define INT1_SENSE  FALLING_EDGE
#define INT2_SENSE  FALLING_EDGE

/*Options
 * 1- ENABLE
 * 2- DISABLE
 * */
#define INT0_INIT_STATE    ENABLE
#define INT1_INIT_STATE    ENABLE
#define INT2_INIT_STATE    ENABLE


#endif /* MCAL_EXTI_HEADER_EXTI_CONFIG_H_ */
