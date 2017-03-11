#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer1.h"

int contorTimer0=0;
int val=0;

void initializare_timer1()
{
	/*TCCR1A = (0 << COM1A1) | (0 << COM1A0) | (1 << COM1B1) | (0 << COM1B0) | (1 << WGM11) | (0 << WGM10);
	TCCR1B = (0 << ICNC1) | (0 << ICES1) | (1 << WGM13) | (1 << WGM12) | (0 << CS12) | (1 << CS11) | (0 << CS10);
	TCNT1 = 0;
	ICR1 = 2048;
	OCR1A = 0;
	OCR1B = 256;
	
		// Timer/Counter 1 Interrupt(s) initialization
	TIMSK1 = (0 << ICIE1) | (0 << OCIE1B) | (0 << OCIE1A) | (1 << TOIE1);
	*/
	
    TCCR1A = TCCR1A | 1 << COM1B1;
    TIMSK1 = TIMSK1 | 1 << OCIE1A;
    //TCCR1A = TCCR1A | 1 << WGM10;
    //TCCR1B = ((TCCR1B | 1 << WGM13) | 1 << WGM12) | 1 << WGM11;
	TCCR1A |= (1 << WGM11) | (1 << WGM10);
	TCCR1B |= (1 << WGM12) | (1 << WGM13);
     OCR1A = 62499;
     
	sei();
	TCCR1B = TCCR1B | 1 << CS12;
}

void timer1_pwm()
{
			while(contorTimer0 < 250)
			{
				OCR0A=0; //led stins
				PORTD ^= LEDPWM;
			}
			
			while(contorTimer0 >= 250 && contorTimer0 < 500)
			{
				if(contorTimer0 != 500)
				{
					val+=1;
					PORTD ^= LEDPWM;
				}
				OCR0A=val/255;
			}

			while(contorTimer0 >=500 && contorTimer0<725)
			{
				OCR0A=255;
				PORTD ^= LEDPWM;
			}

			while(contorTimer0 >725 && contorTimer0<990)
			{
				if(contorTimer0 != 990)
				{
					val-=1;
					PORTD ^= LEDPWM;
				}
				OCR0A=val/255;
			}

			while(contorTimer0 >= 990)
			{
				contorTimer0 = 0;
				PORTD ^= LEDPWM;
			}
			
		
}

ISR(TIMER1_OVF_vect)
{
	contorTimer0++;
}