#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include"UART.h"
void UART_voidInit(void)
{
	//register select for UCSRC
	SET_BIT(UCSRC,UCSRC_URSEL);
	//frame format -> 8bit data , 1 stop bit , no parity
	//8 bit data
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(UCSRC,UCSRC_UCSZ1);
	SET_BIT(UCSRC,UCSRC_UCSZ0);
	//1 bit stop
	CLR_BIT(UCSRC,UCSRC_USBS);
	//no parity
	CLR_BIT(UCSRC,UCSRC_UPM0);
	CLR_BIT(UCSRC,UCSRC_UPM1);
	//Baud Rate 9600bps ->UBRR->51
	UBRRL=51;
	//Asynchronous
	CLR_BIT(UCSRC,UCSRC_UMSEL);
	//Enable tx,rx
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
}
void UART_voidSendData(u8 Data_u8Copy)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);
	UDR=Data_u8Copy;
}
u8 UART_u8RecieveData(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;
}
