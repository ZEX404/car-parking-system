#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/Timer/timer.h"

#include "../HAL/CLCD/CLCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/Servo/Servo.h"

#include "TimeCalc.h"

void TIMER1_OVFmode_ISR(void);
timestamp CurrentTime;

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
	/*******TIMER*******/
	u8 SpotsNum = 10;  //TODO: determine total number of spots
	//assume initial time is 7am
	CurrentTime.hours = 7;
	CurrentTime.minutes = 0;
	CurrentTime.seconds = 0;

	spotInfo SpotsArr[SpotsNum];
	TIMER1_void_Init();
	TIMER1_u8_SetCallback(&TIMER1_OVFmode_ISR);

	/*TODO:
	 * save entering time once the car reserves a spot successfully
	 * 		SpotEnteringTime(SpotsArr["spot index"], &CurrentTime);
	 * save leaving time
	 * 		SpotLeavingTime(SpotsArr["spot index"], &CurrentTime);
	 * display parking duration when leaving
	 * 		CalcParkingDuration(&(SpotsArr["spot index"]));
	 */


	return 0;

}


void TIMER1_OVFmode_ISR(void){
	static u16 count = 0;
	count++;
	if(count == 31250){
		AddOneSecond(&CurrentTime);
		count = 0; //reset counter
	}
}

