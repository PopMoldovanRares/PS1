#include <avr/io.h>
#include <avr/interrupt.h>

// Timer1 overflow interrupt service routine

ISR(TIMER1_OVF_vect)
{
	    OCR1A = 0xFD;
	    PORTB |= 0x02;
}

int main(void)
{

	// Port B initialization
	// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=Out Bit1=In Bit0=Out
	DDRB = 0x02;

	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: 2000,000 kHz
	// Mode: Fast PWM top=ICR1
	// OC1A output: Disconnected
	// OC1B output: Non-Inverted PWM
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer Period: 1,0245 ms
	// Output Pulse(s):
	// OC1B Period: 1,0245 ms Width: 0,12806 ms
	// Timer1 Overflow Interrupt: On
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	TCCR1A = (0 << COM1A1) | (0 << COM1A0) | (1 << COM1B1) | (0 << COM1B0) | (1 << WGM11) | (0 << WGM10);
	TCCR1B = (0 << ICNC1) | (0 << ICES1) | (1 << WGM13) | (1 << WGM12) | (0 << CS12) | (1 << CS11) | (0 << CS10);
	TCNT1 = 0;
	ICR1 = 2048;
	OCR1A = 0;
	OCR1B = 256;

	// Timer/Counter 1 Interrupt(s) initialization
	TIMSK1 = (0 << ICIE1) | (0 << OCIE1B) | (0 << OCIE1A) | (1 << TOIE1);

	// Global enable interrupts
	sei();

	while(1)
	{
		// Place your code here

	}
}*/

#include <avr/io.h>
#include <avr/interrupt.h>
#define LEDPWM 0x02 //PB3

int contorTimer0=0;
int val=0;
int contorflick=0;

void timer0Initializare()
{
	TCCR0A = (1 << COM0A1) | (1 << WGM01) |(1 << WGM00); //timer in fast pwm mode
	TIMSK0 = (1 << TOIE0);
	TCCR0B=(1 << CS02);   //256 prescaler
}

  void timer1_setup()
  {
	  TCCR1A = (1 << WGM10);
	  OCR1A = 245;
	  TIMSK1 = (1 << OCIE1A);
	  TCCR1B = (1 << CS12);
  }

void initializare()
{
	// put your setup code here, to run once:
	DDRB = 0xFF;
	//OCR0A = 0x3FFF; //duty cycke 50%
	//TCCR0A |= (1<<COM0A1); //non inverting mode
	//TCCR0A |= (1<<WGM01) | (WGM00); //fast pwm mode
	//TCCR0B |= (1<<CS01);  //prescaler = 8 and start pwm
	
}




int main()
{
	initializare();
	timer0Initializare();
	//timer1_setup();
	sei();
	while(1)
	{
		
		while(contorTimer0 < 250)
		{
			OCR0A=0; //led stins
			//PORTB ^= LEDPWM;
		}	
		
		while(contorTimer0 >= 250 && contorTimer0 < 500)
		{
			if(contorTimer0 != 500)
			{
				val+=1;
				PORTB ^= LEDPWM;
			}
			OCR0A=val/255;
		}

		while(contorTimer0 >=500 && contorTimer0<725)
		{
			OCR0A=255;
			PORTB ^= LEDPWM;
		}

		while(contorTimer0 >725 && contorTimer0<990)
		{
			if(contorTimer0 != 990)
			{
				val-=1;
				PORTB ^= LEDPWM;
			}
			OCR0A=val/255;
		}

		while(contorTimer0 >= 990)
		{
			contorTimer0 = 0;
			PORTB ^= LEDPWM;
		}
	
	}
}

ISR(TIMER0_OVF_vect)
{
	contorTimer0++;
}

/*
ISR(TIMER1_COMPA_vect)
{
	contorflick++;

	if(contorflick > 245)
	{
		contorflick= 0;
		PORTB ^= LEDPWM;
	}
}*/