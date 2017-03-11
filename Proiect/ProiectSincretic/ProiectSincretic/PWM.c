#include <avr/io.h>
#include <time.h>
#include <avr/interrupt.h>
#include "PWM.h"


int contorTimer0=0;
int val=0;

void timer0Initializare()
{
	
	TCCR0A = (1 << COM0A1) | (1 << WGM01) |(1 << WGM00); //timer in fast pwm mode
	TIMSK0 = (1 << TOIE0);
	TCCR0B=(1 << CS02);   //256 prescaler

}

void control_led_pwm()
{
	
	while(contorTimer0 < 245)
	{
		OCR0A=0; //led stins
		PORTD ^= 0x08;
	}
	
	while(contorTimer0 >= 245 && contorTimer0 < 490)
	{
		if(contorTimer0 != 490)
		{
			val+=1;
			PORTD ^= 0x08;
		}
		OCR0A=val/255;
	}

	while(contorTimer0 >=400 && contorTimer0<735)
	{
		OCR0A=255;
		PORTD ^= 0x08;
	}

	while(contorTimer0 >735 && contorTimer0<980)
	{
		if(contorTimer0 != 980)
		{
			val-=1;
			PORTD ^= 0x08;
		}
		OCR0A=val/255;
	}

	while(contorTimer0 >= 980)
	{
		contorTimer0 = 0;
		PORTD ^= 0x08;
	}
	
	
}

ISR(TIMER0_OVF_vect)
{
	contorTimer0++;
}
