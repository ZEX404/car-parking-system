#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <avr/io.h>
#include <util/delay.h>

#ifndef DIO_H_
#define DIO_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_HIGH 1
#define DIO_LOW 0

#define DIO_PORT_INPUT 0
#define DIO_PORT_OUTPUT 0xFF

void DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);
void DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PortDirCopy);

void DIO_SetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinValueCopy);
void DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PortValueCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

#endif /* DIO_H_ */
