/*
 * Servo.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Omar
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO.h"
#include "../MCAL/timer.h"
#include "Servo.h"
#include <avr/io.h>


void TIMER1_voidCTCINIT(){

	// Mode FAST PWM
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

	// Setting waveform generation for FAST PWM
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1A_WGM12);
	SET_BIT(TCCR1B,TCCR1A_WGM13);

	// Setting the Prescaler
	TCCR1B &= PRESCALLER_MASK;
	TCCR1B |= DIVIDE_BY_8;
}

void TIMER1_voidSetChannelACompareMatch(u16 Copy_u16CompareMatch){

	OCR1A = Copy_u16CompareMatch;
}


void TIMER1_voidSetTopTicks(u16 Copy_u16TopTicks){

	ICR1 = Copy_u16TopTicks;
}

void Servo_OpenGate(void){
	u16 ServoLocal_u16Iterator;
	for(ServoLocal_u16Iterator = 1000 ; ServoLocal_u16Iterator < 1090 ; ServoLocal_u16Iterator++){
		TIMER1_voidSetChannelACompareMatch(ServoLocal_u16Iterator);
		delay(10);
	}
	delay(3000);
	Servo_CloseGate();
}

void Servo_CloseGate(void){
    u16 ServoLocal_u16Iterator;
    for(ServoLocal_u16Iterator = 1090 ; ServoLocal_u16Iterator >= 999; ServoLocal_u16Iterator--){
        TIMER1_voidSetChannelACompareMatch(ServoLocal_u16Iterator);
        delay(10);
    }
}


