/*
 * timer.h
 *
 *  Created on: Aug 27, 2023
 *      Author: M
 */

#ifndef TIMER_H_
#define TIMER_H_

/**************CONFIGURATIONS**************/

/*****TIMER0*****/
//TCCR0 (control register)
#define TCCR0_WGM00	6
#define TCCR0_WGM01	3
#define TCCR0_CS02	2
#define TCCR0_CS01	1
#define TCCR0_CS00	0
//TIMSK (interrupt mask)
#define TIMSK_TOIE0	0



/*****TIMER1 (16-bit)*****/
//TCCR1A (control register channel A)
#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6
#define TCCR1A_WGM11	1
#define TCCR1A_WGM10	0
//TCCR1B (control register channel B)
#define TCCR1B_WGM13	4
#define TCCR1B_WGM12	3
#define TCCR1B_CS12		2
#define TCCR1B_CS11		1
#define TCCR1B_CS10		0
//TIMSK (interrupt mask)
#define TIMSK_TICIE1 	5
#define TIMSK_OCIE1A	4
#define TIMSK_OCIE1B	3
#define TIMSK_TOIE1		2


#define OK 		1
#define NotOK 	0

/**************PROTOTYPES**************/
void TIMER0_void_Init();
void delay(u16 milliseconds);

void TIMER1_void_Init();
u8 TIMER1_u8_SetCallback(void (* PtrCallback));

#endif /* TIMER_H_ */
