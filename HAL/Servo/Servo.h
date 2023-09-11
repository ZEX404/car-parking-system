/*
 * Servo.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Omar
 */

#ifndef SERVO_H_
#define SERVO_H_

#define TCCR0_WGM00  6  // Waveform Generation Mode
#define TCCR0_COM01	 5
#define TCCR0_COM00	 4
#define TCCR0_WGM01  3  // Waveform Generation Mode
#define TCCR0_CS02   2  // {
#define TCCR0_CS01   1  //  Prescaler
#define TCCR0_CS00   0  // }

#define TIMSK_OCIE0  1 // Output Compare 0 Interrupt Enable
#define TIMSK_TOIE0  1 // Output Overflow 0 Interrupt Enable

#define PRESCALLER_MASK 0b11111000
#define DIVIDE_BY_8     2


/*****TIMER0*****/
// FAST PWM
void TIMER0_voidCTCINIT();
void TIMER0_voidSetChannelACompareMatch(u16 Copy_u16CompareMatch); // OCR0


void Servo_OpenGate(void);
void Servo_CloseGate(void);

#endif /* SERVO_H_ */
