/*
 * Servo.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Omar
 */

#ifndef SERVO_H_
#define SERVO_H_

#define TCCR0_WGM00  6  // Waveform Generation Mode
#define TCCR0_WGM01  3  // Waveform Generation Mode
#define TCCR0_CS02   2  // {
#define TCCR0_CS01   1  //  Prescaler
#define TCCR0_CS00   0  // }

#define TIMSK_OCIE0  1 // Output Compare 0 Interrupt Enable
#define TIMSK_TOIE0  1 // Output Overflow 0 Interrupt Enable

#define TCCR1A_COM1A0 6
#define TCCR1A_COM1A1 7
#define TCCR1A_WGM10  0
#define TCCR1A_WGM11  1

#define TCCR1A_WGM12  3
#define TCCR1A_WGM13  4

#define PRESCALLER_MASK 0b11111000
#define DIVIDE_BY_8     2


// FAST PWM
void TIMER1_voidCTCINIT();


void Servo_OpenGate(void);
void Servo_CloseGate(void);

#endif /* SERVO_H_ */
