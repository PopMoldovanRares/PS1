#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

//Declaration of our functions
void adc_init(void);
uint16_t read_adc(uint8_t channel);
float temperatura_celsius();
void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);

char String[]="oiee";    //String[] is in fact an array but when we put the text between the " " symbols the compiler threats it as a String and automatically puts the null termination character in the end of the text

int main(void){
	//system_tick();
	sei();
	USART_init();  
	//UCSR0B |= (1 << RXCIE0);      //Call the USART initialization code
	UCSR0B |= (1<<RXEN0)|(1<<RXCIE0);
	
	//DDRB |= 0x10;
	
	while(1)
	{       
		
	}
	
	return 0;
}
float voltage=0;
float Temperature=0;
float temperatureCelsius=0;
int reading;

void adc_init()
{
	//selectare factor de divizare 128
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
	//AVCC cu capacitor extern
	ADMUX |= 1<<REFS0;
	//permite caract ADC
	ADCSRA |= 1<<ADEN;
	//start conversie
	ADCSRA |= 1<<ADSC;
	DDRC |= 0x0;
}

uint16_t read_adc(uint8_t channel)
{
	ADMUX &= 0xF0;  //set input AO to A5
	ADMUX |= channel; //select chanel AO to A5
	ADCSRA |= (1<<ADSC);  //start conversion
	while(ADCSRA & (1<<ADSC)) ;//wait wile adc conversion are not updated
	return ADCW;
}

float temperatura_celsius()
{
	adc_init();
	
	reading=read_adc(0);
	voltage=reading*5.0;
	voltage/=1024.0;
	temperatureCelsius=(voltage-0.5)*100;
	return temperatureCelsius;
}

void USART_init(void){
	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);	 //UBR0H = 0000 0000
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);	//UBR0L = 0110 0111
	//enable la transmitere si primire
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);	//RXEN0=0 nu se pot recepta date, TXEN0=1 nu se pot trans date
	//UCSR0C = (3<<UCSZ00);	//setare biti de stop 2
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

unsigned char USART_receive(void){
	
	while(!(UCSR0A & (1<<RXC0)));	//cat timp mai sunt date neprimite
	{
		//se transmit datele necitite
	}
	return UDR0;
	
}

void USART_send( unsigned char data){
	
	while(!(UCSR0A & (1<<UDRE0)));	//cat timp bufferul de transmisie poate accepta noi date
	
	UDR0 = data;	//se salveaza in buffer
	//UDR0 = temperatura_celsius();
}

void USART_putstring(char* StringPtr)
{
	
	while(*StringPtr != 0x00)
	{
		USART_send(*StringPtr);
		StringPtr++;
	}
}


/*void USART_Flush( void )
{
	unsigned char dummy;
	while ( UCSR0A & (1<<RXC0) ) dummy = UDRn;
}
*/

ISR(USART_RX_vect)
{
	char ReceivedByte;
	ReceivedByte = UDR0; // Fetch the received byte value into the variable "ByteReceived"
	UDR0 = ReceivedByte; // Echo back the received byte back to the computer
	/*if(ReceivedByte == 'A')
	{
		PORTB |= 0x10;
	}
	else
	if(ReceivedByte == 'S')
	{
		PORTB &=~(0x10);
	}
	*/
	//USART_putstring(String);
}