/*
 * LED.c
 *
 * Created: 11/8/2016 7:19:31 PM
 *  Author: didi
 */ 
#include <avr/io.h>
#include "LED.h"

void intializare()
{
	DDRD |= 0x08;
}
void aprinde_led()
{
	PORTD |= LEDS;
}
void stinge_led()
{
	PORTD &=~(LEDS);
}