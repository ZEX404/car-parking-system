#include <stdio.h>
#include <stdlib.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/CLCD/CLCD.h"
#include "../HAL/Servo/Servo.h"
#include "../HAL/Keypad/Keypad.h"
#include <util/delay.h>
#include <avr/io.h>


int main(void) {
/* 	Servo (Gate) Part:

	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);  // Setting Pin 0 of Port D as Output (OC1A) 
	TIMER1_voidCTCINIT();                                      // Initializing Timer1 
	TIMER1_voidSetTopTicks(20000);                             // Setting Top Ticks Value as 20 ms 
	Servo_OpenGate(); 										   // Rotate to 90 degrees to Open Gate 
	Servo_CloseGate(); 										   // Rotate back to 0 degrees to Close Gate 

*/
	
	
	return 0;

}
