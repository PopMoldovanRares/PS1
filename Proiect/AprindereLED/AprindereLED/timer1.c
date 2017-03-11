/*
 * timer1.c
 *
 * Created: 11/8/2016 8:16:07 PM
 *  Author: didi
 */ 
#include <avr/io.h>
#include <time.h>
#include "timer1.h"
#include "LED.h"
#include <avr/interrupt.h>

int intrerupere = 0;

void timer1_1s()
{
	cli(); //stop intreruperi

	/* Setare timer care sa genereze o intrerupere la 1s */
	//set timer1 interrupt at 1Hz
	TCCR1A = 0;// setare tot registrul TCCR1A pe 0
	TCCR1B = 0;// setare tot registrul TCCR1B pe 0
	
	//timmer/counter register, contine valoarea timer-ului
	TCNT1  = 0;//initilizare contor cu 0
	
	// setare registru comparare pentru incrementearea cu 1hz
	// output compare register
	OCR1A = 15624;
	// = (16*10^6) / (1*1024) - 1 (must be <65536)
	// pornire mod CTC
	TCCR1B |= (1 << WGM12);
	// Setare biti CS10 si CS12 pentru de prescaler 1024
	TCCR1B |= (1 << CS12) | (1 << CS10);
	// permite intreruperi timer compare
	TIMSK1 |= (1 << OCIE1A);

	sei(); //da drumul la intreruperi
}

ISR(TIMER1_COMPA_vect)
{
	//timerul1 genereaza o intrerupere la toggle 1Hz
	//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
	if (intrerupere)
	{
		PORTD |= LEDS;
		intrerupere = 0;
	}
	else
	{
		PORTD &=~(LEDS);
		intrerupere = 1;
	}
}
