#include <avr/interrupt.h>
#include <avr/io.h>
#include "Timer1.h"


int main(void)
{
    /* Replace with your application code */
	DDRD |= 0x08;
	initializare_timer1();
	
    while (1) 
    {
		PORTD |= 0x08;
    }
}

