/*
 * Led.c
 *
 * Created: 10/4/2016 8:48:38 PM
 * Author : didi
 */ 

#include <avr/io.h>

void declarare()
{
	DDRD |= 0xFF;
	//Serial.available();
	
}

void turn_on_off()
{
	PORTD |= 0x10;
	//delay(500);
}

int main(void)
{
    /* Replace with your application code */
	
	
	
    while (1) 
    {
		turn_on_off();
    }
}

