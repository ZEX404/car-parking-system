/*
 * timer.c
 *
 *  Created on: Aug 27, 2023
 *      Author: M
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO.h"
#include "GIE.h"
#include "timer.h"
#include <avr/io.h>

void (* TIMRE1_PtrCallback)(void) = NULL;

/*****TIMER0*****/
void TIMER0_void_Init(){
	//Normal mode
	CLR_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);
	//counter
	TCNT0 = 125;
	//prescaler = 64
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
	//busy wait for the flag
	while(GET_BIT(TIFR, TOV0) == 0);
	//stop timer0 by clearing the prescaler
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
	//clear the flag
	SET_BIT(TIFR, TOV0);

}
void delay(u16 milliseconds){
	u16 i;
	for(i=0; i<milliseconds; i++){
		TIMER0_void_Init();
	}
}



/*****TIMER1 (16-bit)*****/
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
