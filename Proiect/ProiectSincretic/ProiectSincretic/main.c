#include <avr/io.h>
#include <time.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#include "segment.h"
#include "timer1.h"
#include "USART.h"
#include "buton.h"
#include "ADCTemp.h"

void intializare()
{
	
	//initializare 7 seg
	DDRD|=a;
	DDRD|=b;
	DDRD|=c;
	DDRB|=d;
	DDRB|=e;
	DDRD|=f;
	DDRD|=g;
	
	DDRD |= 0x08; //led 1s (POTRD3)
	DDRB |= 0x20; //led serial (PORTB 13)
	DDRB |= 0x08; //led temp (PORTB 10)
	DDRB |= 0x10; //buton (PORTB 11)
	DDRC |= 0x00; //port intrare (PORTC 0 (A0))
	
}

int main()
{
	
	USART_init();
	intializare();
	timer1_1s();
	//timer0Initializare();
	initializare_buton();

	sei();
	//afisare_temp();
	
	while (1)
	{
		functionare_buton();
		control_Led_temp();
		
		//control_led_pwm();
	}
}

