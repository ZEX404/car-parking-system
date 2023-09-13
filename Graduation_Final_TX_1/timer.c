/*
 * timer.c
 *
 *  Created on: Aug 27, 2023
 *      Author: M
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer.h"
#include "../DIO/DIO.h"
#include "GIE.h"
#include <avr/io.h>

void (* TIMRE1_PtrCallback)(void) = NULL;

void TIMER1_void_Init(){
	//set waveform generation to CTC mode (TOP: OCR1A)
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);
	//compare match value
	OCR1A = 250;
	//enable Output Compare Match interrupt and general interrupt (GIE)
	SET_BIT(TIMSK, TIMSK_OCIE1A);
	GIE_void_Enabled();
	//prescaler = 256
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	CLR_BIT(TCCR1B, TCCR1B_CS11);
	SET_BIT(TCCR1B, TCCR1B_CS12);
}
void __vector_7(void) __attribute__((signal));
void __vector_7(void){
	if(TIMRE1_PtrCallback != 0){
		TIMRE1_PtrCallback();
	}
}

u8 TIMER1_u8_SetCallback(void (* PtrCallback)){
	u8 ErrorStatus_local_u8 = OK;
	if(PtrCallback != NULL){
		TIMRE1_PtrCallback = PtrCallback;
	}
	else {
		ErrorStatus_local_u8 = NotOK;
	}
	return ErrorStatus_local_u8;
}
