/*
 * Servo.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Omar
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "Servo.h"
#include <util/delay.h>
#include <avr/io.h>

void TIMER0_voidCTCINIT(){

	// Mode FAST PWM
	CLR_BIT(TCCR0, TCCR0_COM01);
	SET_BIT(TCCR0, TCCR0_COM00);

	// Setting waveform generation for FAST PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	// Setting the Prescaler
	TCCR0 &= PRESCALLER_MASK;
	TCCR0 |= DIVIDE_BY_8;
}

void TIMER0_voidSetChannelACompareMatch(u16 Copy_u16CompareMatch){

	OCR0 = Copy_u16CompareMatch;
}

void Servo_OpenGate(void){
	u16 ServoLocal_u16Iterator;
	for(ServoLocal_u16Iterator = 1000 ; ServoLocal_u16Iterator < 1090 ; ServoLocal_u16Iterator++){
		TIMER0_voidSetChannelACompareMatch(ServoLocal_u16Iterator);
		_delay_ms(10);
	}
}

void Servo_CloseGate(void){
    u16 ServoLocal_u16Iterator;
    for(ServoLocal_u16Iterator = 1090 ; ServoLocal_u16Iterator >= 999; ServoLocal_u16Iterator--){
        TIMER0_voidSetChannelACompareMatch(ServoLocal_u16Iterator);
        _delay_ms(10);
    }
}


