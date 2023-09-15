#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO.h"
#include "../MCAL/timer.h"
#include "../MCAL/GIE.h"
#include "../MCAL/EXTI.h"
#include "../HAL/CLCD.h"
#include "../HAL/Keypad.h"
#include "../APP/TimeCalc.h"
#include "../APP/Global.h"
#include <avr/io.h>



u8 Local_u8Key=0,Emergency = 0;

timestamp CurrentTime;

spotInfo SpotsArr[5];


int main(void){

	//LCD
	DIO_SetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);

	DIO_SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);

	DIO_SetPinDirection(DIO_PORTC, DIO_PIN6, DIO_PIN_OUTPUT); // Led
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN7, DIO_PIN_OUTPUT); // Buzzer
	DIO_SetPinDirection(EXTI0_PORT, EXTI0_PIN, DIO_PIN_INPUT); // Push Button

	DIO_SetPinValue(EXTI0_PORT, EXTI0_PIN, DIO_PIN_HIGH);
	EXTI_void_INT0();
	GIE_void_Enabled();

	CurrentTime.hours = 7;
	CurrentTime.minutes = 0;
	CurrentTime.seconds = 0;

	UART_voidINIT_TX();
	KPD_INIT();
	CLCD_voidInit();
	TIMER1_void_Init();
	TIMER1_u8_SetCallback(&TIMER1_CTCmode_ISR);

	UART_voidSendData_TX(1);
	UART_voidSendData_TX(0);

	while(1)
	{
		CLCD_voidLCDClear();
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString(" Welcome to our");
		CLCD_voidGoToXY(2,0);
		CLCD_voidSendString(" Parking Garage");
		delay(500);
		CLCD_voidLCDClear();

		CLCD_voidSendString("1.Reserve Spot");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("2.Available");
		CLCD_voidGoToXY(2,0);
		CLCD_voidSendString("3.Reserved Spots");
		CLCD_voidGoToXY(3,0);
		CLCD_voidSendString("4.Checkout");

		do {
			Local_u8Key = KPD_GetPressedKey();
		} while (Local_u8Key == 0xFF && Emergency != 1);

		switch(Local_u8Key){
		case '1':{
			reserve();
			delay(2000);
			break;
		}
		case '2':{
			available_places();
			delay(2000);
			break;
		}
		case '3':{
			reserved_places();
			delay(2000);
			break;
		}
		case '4':{
			Checkout();
			delay(2000);
			break;
		}
		default:{
			CLCD_voidLCDClear();
			CLCD_voidSendString(" Invalid Key ! ");
			delay(500);
		}
		}
		EmergencyState();
	}
	return 0;
}

void EmergencyState(){

	while(Emergency == 1)
		{
			// Led
			DIO_SetPinValue(DIO_PORTC, DIO_PIN6, DIO_PIN_HIGH);
			delay(100);
			DIO_SetPinValue(DIO_PORTC, DIO_PIN6, DIO_PIN_LOW);
			delay(100);

			// Buzzer
			// Ascending pitch
			for (int frequency = 100; frequency <= 1000; frequency += 100)
			{
				DIO_SetPinValue(DIO_PORTC, DIO_PIN7, DIO_PIN_HIGH);
				delay(1000 / frequency);
				DIO_SetPinValue(DIO_PORTC, DIO_PIN7, DIO_PIN_LOW);
				delay(1000 / frequency);
			}
			// Descending pitch
			for (int frequency = 1000; frequency >= 100; frequency -= 100)
			{
				DIO_SetPinValue(DIO_PORTC, DIO_PIN7, DIO_PIN_HIGH);
				delay(1000 / frequency);
				DIO_SetPinValue(DIO_PORTC, DIO_PIN7, DIO_PIN_LOW);
				delay(1000 / frequency);
			}

			// Servo
			//Servo_OpenGate();
		}
}


void TIMER1_CTCmode_ISR(void){
	static u8 count = 0;
	count++;
	if(count == 125){
		AddOneSecond(&CurrentTime);
		count = 0; //reset counter
	}
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	Emergency = !Emergency;
}
