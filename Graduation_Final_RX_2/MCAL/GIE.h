/*
 * GIE.h
 *
 *  Created on: Aug 23, 2023
 *      Author: M
 */

#ifndef GIE_H_
#define GIE_H_

//global interrupt enable
#define SREG_GIE 7

#define EXTI0_PORT DIO_PORTD
#define EXTI0_PIN  DIO_PIN2

void GIE_void_Enabled(void);
void GIE_void_Disabled(void);

#endif /* GIE_H_ */
