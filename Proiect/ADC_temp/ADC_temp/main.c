#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay_basic.h>

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
	ADMUX &= 0xF0;	//set input AO to A5
	ADMUX |= channel;	//select chanel AO to A5
	ADCSRA |= (1<<ADSC);	//start conversion
	while(ADCSRA & (1<<ADSC))	;//wait wile adc conversion are not updated
	return ADCW;
}

int main(void)
{
    /* Replace with your application code */
	unsigned int val;
	
	adc_init();
	val = read_adc(0);
    while (1) 
    {
		if(read_adc(0) != 0)
		{
			PORTB |= 0x10;
			//_delay_ms(1000);
		}
		else
		{
			PORTB &=~(0x10);
		}
			
    }
}

