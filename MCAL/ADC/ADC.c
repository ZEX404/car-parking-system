/*
 * ADC.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Menna
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include"ADC.h"

void ADC_voidInit(void)
{
	/*AVCC as reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*Activate Left Adjust result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);
	/*set prescaller to divide by 128*/
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	/*Enable peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	/*step1: clear the MUX bits in ADMUX register*/
	ADMUX &=0b11100000;
	/*set the required channel into MUX bits*/
	ADMUX |=Copy_u8Channel;
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Polling (busy waiting ) until the conversion complete flag is set*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);
	/*clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	/*return the reading */
	return ADCH;
}

