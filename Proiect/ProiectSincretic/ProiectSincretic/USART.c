#include <avr/io.h>
#include <avr/interrupt.h>
#include "USART.h"
#include "ADCTemp.h"

void USART_init(void)
{
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);	 //UBR0H = 0000 0000
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);	//UBR0L = 0110 0111
	//enable la transmitere si receptie
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);	//RXEN0=0 nu se pot recepta date, TXEN0=1 nu se pot trans date
	UCSR0C = (1<<USBS0)|(3<<UCSZ00); //8 biti de date si 2 biti de stop
	UCSR0B |= (1<<RXEN0)|(1<<RXCIE0);
}

unsigned char USART_receive(void)
{
	while(!(UCSR0A & (1<<RXC0)));	//cat timp mai sunt date neprimite
	{
		//se transmit datele necitite
	}
	return UDR0;
}

void USART_send( unsigned char data)
{
	
	while(!(UCSR0A & (1<<UDRE0)));	//cat timp bufferul de transmisie poate accepta noi date
	
	UDR0 = data;	//se salveaza in buffer
	
}

void USART_citire(char *data, char lungime)
{
	unsigned char i;
	
	while(lungime > 0)
	{
		if(UCSR0A & (1<<UDRE0))
		{
			UDR0 = data[i++];
			lungime--;
		}
	}
}

ISR(USART_RX_vect)
{
	char ReceivedByte;
	ReceivedByte = UDR0; // Fetch the received byte value into the variable "ByteReceived"
	UDR0 = ReceivedByte; // Echo back the received byte back to the computer
	
	if(ReceivedByte == 'A')
	{
		PORTB |= 0x20;
		//PORTB |= (1<<5);
	}
	else
	if(ReceivedByte == 'S')
	{
		//PORTB &=~(1<<5);
		PORTB &=~(0x20);
	}

	afisare_temp();	
	
}