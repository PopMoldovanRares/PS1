/*
 * GccApplication1.c
 *
 * Created: 10/5/2016 4:16:25 PM
 * Author : didi
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	 DDRB = (1 << DDB5);
    while (1) 
    {
		 // LED on
        PORTB = (1 << DDB5);
       // _delay_ms(100);
        // LED off
        //PORTB = 0;
       // _delay_ms(100);
    }
}

