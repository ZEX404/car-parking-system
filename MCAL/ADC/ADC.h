/*
 * ADC.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Menna
 */

#ifndef ADC_H_
#define ADC_H_

/*Congfigurations */
#define ADC_PORT   DIO_PORTA
#define ADC0_PIN   DIO_PIN0
#define ADC1_PIN   DIO_PIN1
#define ADC2_PIN   DIO_PIN2
#define ADC3_PIN   DIO_PIN3
#define ADC4_PIN   DIO_PIN4
#define ADC5_PIN   DIO_PIN5
#define ADC6_PIN   DIO_PIN6
#define ADC7_PIN   DIO_PIN7

//ADMUX :ADC Multiplexer selection
#define ADMUX_REFS1    7
#define ADMUX_REFS0    6
#define ADMUX_ADLAR    5

//ADCSRA: ADC Control and Status Register A
#define ADCSRA_ADEN     7//ADC Enable
#define ADCSRA_ADSC     6//Start conversion
#define ADCSRA_ADATE    5//Auto trigger enable
#define ADCSRA_ADIF     4//Interrupt flag
#define ADCSRA_ADIE     3//Interrupt  enable
#define ADCSRA_ADPS2    2//prescaller bit2
#define ADCSRA_ADPS1    1//prescaller bit1
#define ADCSRA_ADPS0    0//prescaller bit0

/*prototypes*/
void ADC_voidInit(void);
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);


#endif /* ADC_H_ */
