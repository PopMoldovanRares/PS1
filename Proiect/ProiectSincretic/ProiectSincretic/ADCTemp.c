#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"
#include "ADCTemp.h"

 float voltage=0;
 float Temperature=0;
 float temperatureCelsius=0;
 int reading;
 char output[10];

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
	//sprintf(temperatureCelsius,"temp: %d\n");
}

float temp;

void control_Led_temp()
{
	temp = temperatura_celsius();
	if(temp > 35)
	{
		PORTB |= 0x08;
	} 
	else if(temp <= 35)
	{
		PORTB &=~(0x08);
	}
}

void afisare_temp()
{
	int temperatura = (int) temp;
	
	sprintf(output,"temp %d\n",temperatura);
	USART_citire(output,10);
	_delay_ms(20000);
}