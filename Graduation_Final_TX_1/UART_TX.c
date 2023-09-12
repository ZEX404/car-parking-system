/*
 * UART.c
 *
 *  Created on: Aug 30, 2023
 *      Author: Omar
 */

#include "UART_TX.h"

#include "STD_TYPES.h"
#include "DIO.h"
#include <avr/io.h>

void UART_voidINIT_TX(void){
	/* 1 Stop Bit */
	CLR_BIT(UCSRC,UCSRC_USBS);

	/* 8 bit Data */
	SET_BIT(UCSRC,UCSRC_UCSZ0);
	SET_BIT(UCSRC,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	/* No Parity */
	CLR_BIT(UCSRC,UCSRC_UPM0);
	CLR_BIT(UCSRC,UCSRC_UPM1);

	/* Asynchronous Operation */
	CLR_BIT(UCSRC,UCSRC_UMSEL);

	/* Set Baud Rate */
	UBRRL = 51;
	UBRRH = 0;

	/* Enable RX, TX */
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);

}

void UART_voidSendData_TX(u8 Data_u8Copy){

	/* Wait Flag UDRE to finish */ /* Register Empty or Not */
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);
	UDR = Data_u8Copy;
}

u8 UART_u8RecieveData_TX(void){

	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
	return UDR ;
}
