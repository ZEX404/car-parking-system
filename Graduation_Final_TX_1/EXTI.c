/*
 * EXTI.c
 *
 *  Created on: Sep 10, 2023
 *      Author: LENOVO
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI.h"
#include<avr/io.h>


void EXTI_void_INT0(void)
{
	/*set Falling Edge*/
	/*set Sense Control for INT0*/
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);

	/*Peripheral Interrupt enable for INT0*/
	SET_BIT(GICR, GICR_INT0);//key of access the interrupt

}
