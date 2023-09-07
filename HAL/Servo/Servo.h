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

#define OK 1
#define NOT_OK 0

// FAST PWM
void TIMER1_voidINIT();
void TIMER1_voidSetChannelACompareMatch(u16 Copy_u16CompareMatch); //OCR1A
void TIMER1_voidSetTopTicks(u16 Copy_u16TopTicks); //ICR

u16 u8SetRequiredValue(u16 entered_value);
u8 isValidAngle(const u8* str);

#endif /* SERVO_H_ */
