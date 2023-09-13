/*
 * EXTI.h
 *
 *  Created on: Sep 10, 2023
 *      Author: LENOVO
 */

#ifndef EXTI_H_
#define EXTI_H_

#define EXTI0_PORT DIO_PORTD
#define EXTI0_PIN  DIO_PIN2

#define EXTI1_PORT DIO_PORTD
#define EXTI1_PIN  DIO_PIN3

#define EXTI2_PORT DIO_PORTB
#define EXTI2_PIN  DIO_PIN2

#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3

#define MCUCSR_ISC2  6

#define GICR_INT2 5
#define GICR_INT0 6
#define GICR_INT1 7

#define GIFR_INTF2 5
#define GIFR_INTF0 6
#define GIFR_INTF1 7

#define EXTINT_FALLING_EDGE       0
#define EXTINT_RAISING_EDGE       1
#define EXTINT_ANY_LOGICAL_CHANGE 2
#define EXTINT_LOW_LEVEL          3

void EXTI_void_INT0(void);

#endif /* EXTI_H_ */
