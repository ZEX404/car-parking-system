#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "Servo.h"
#include "LDR.h"
#include "UART_RX.h"
#include <avr/io.h>
#include <util/delay.h>


int main(void){
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A (Timer1) for servo
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
    // Set pin directions for LDR

	UART_voidINIT_RX();
    TIMER1_voidCTCINIT();
    TIMER1_voidSetTopTicks(20000);
    u8 recieved_data = UART_u8RecieveData_RX();
    while(1){
    	LDR();
    	recieved_data = UART_u8RecieveData_RX();
    	if(recieved_data == SIGNAL_OPENGATE){
    		Servo_OpenGate();
    	}
    }

    return 0;
}
