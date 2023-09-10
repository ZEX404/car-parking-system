#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/UART/UART.h"

#include "../HAL/CLCD/CLCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/Servo/Servo.h"
#include "../MCAL/ADC/ADC.h"


int main(void) {

/*
    UART_voidInit(); // Initialize UART communication

    // Send "Hello, World!" over UART
    char hello[] = "Hello, World!\r\n";
    for (int i = 0; hello[i] != '\0'; i++) {
        UART_voidSendData(hello[i]);
    }

    // Receive and print data
    while (1) {
        char received_data;
        received_data = UART_u8RecieveData();
        // Print received data to some output (e.g., LED, LCD, or another UART transmission)
        printf("Received: %c\r\n", received_data);
    }
*/


/* 	Servo (Gate) Part:

	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);  // Setting Pin 0 of Port D as Output (OC1A) 
	TIMER1_voidCTCINIT();                                      // Initializing Timer1 
	TIMER1_voidSetTopTicks(20000);                             // Setting Top Ticks Value as 20 ms 
	Servo_OpenGate(); 										   // Rotate to 90 degrees to Open Gate 
	Servo_CloseGate(); 										   // Rotate back to 0 degrees to Close Gate 

*/
/*
LDR PART:
	CLCD_voidInit();
	ADC_vidInit();
	LCD_voidClear();
	 f32 LDR;
	while(1)
	{
		LCD_voidClear();
		LDR = ADC_u16ReadChannelSyn(0);
		LDR = (LDR / 1023.0) * 100;
		LCD_voidSendNumber(LDR);
		_delay_ms(100);
        if (LDR <= 40) {
            // Turn off all LEDs
            for (u8 i = 0; i < 8; i++) {
                DIO_SetPinValue(DIO_PORTC, i, DIO_PIN_LOW);
            }
        } else {
            // Turn on all LEDs
            for (u8 i = 0; i < 8; i++) {
                DIO_SetPinValue(DIO_PORTC, i, DIO_PIN_HIGH);
            }
        }

        _delay_ms(100); // Delay for a moment before reading LDR again
    }

	
	
	return 0;
*/

}
