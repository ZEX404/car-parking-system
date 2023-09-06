/*
 * UART.h
 *
 *  Created on: Aug 30, 2023
 *      Author: Menna
 */

#ifndef UART_H_
#define UART_H_

/*configuration bits*/
/*UCSRA */
#define UCSRA_RXC   7
#define UCSRA_TXC   6
#define UCSRA_UDRE  5
#define UCSRA_FE    4
#define UCSRA_DOR   3
#define UCSRA_PE    2
#define UCSRA_U2X   1
#define UCSRA_MPCM  0
/*UCSRB*/
#define UCSRB_RXCIE 7
#define UCSRB_TXCIE 6
#define UCSRB_UDRIE 5
#define UCSRB_RXEN  4
#define UCSRB_TXEN  3
#define UCSRB_UCSZ2 2
#define UCSRB_RXB8  1
#define UCSRB_TXB8  0
/*UCSRC*/
#define UCSRC_URSEL 7
#define UCSRC_UMSEL 6
#define UCSRC_UPM1  5
#define UCSRC_UPM0  4
#define UCSRC_USBS  3
#define UCSRC_UCSZ1 2
#define UCSRC_UCSZ0 1
#define UCSRC_UCPOL 0

void UART_voidInit(void);
void UART_voidSendData(u8 Data_u8Copy);
u8 UART_u8RecieveData(void);

#endif /* UART_H_ */
