
#include <avr/io.h>
#include "segment.h"

void initializare_segment()
{
	DDRD|=a;
	DDRD|=b;
	DDRD|=c;
	DDRD|=d;
	DDRD|=e;
	DDRD|=f;
	DDRD|=g;
}

void nr0()
{
	PORTD |= a;
	PORTD |= b;
	PORTD |= c;
	PORTD |= d;
	PORTD |= e;
	PORTD |= f;
	
	PORTD &=~g;
}

void nr1()
{
	PORTD |= b;
	PORTD |= c;
	
	PORTD &=~a;
	PORTD &=~d;
	PORTD &=~e;
	PORTD &=~f;
	PORTD &=~g;
}

void nr2()
{
	PORTD |= a;
	PORTD |= b;
	PORTD |= g;
	PORTD |= e;
	PORTD |= d;
	
	PORTD &=~f;
	PORTD &=~c;
}

void nr3()
{
	PORTD |= a;
	PORTD |= b;
	PORTD |= c;
	PORTD |= d;
	PORTD |= g;
	
	PORTD &=~e;
	PORTD &=~f;
}

void nr4()
{
	PORTD |= f;
	PORTD |= g;
	PORTD |= b;
	PORTD |= c;

	PORTD &=~a;
	PORTD &=~d;
	PORTD &=~e;
}

void nr5()
{
	PORTD |= a;
	PORTD |= f;
	PORTD |= g;
	PORTD |= c;
	PORTD |= d;
	
	PORTD &=~b;
	PORTD &=~e;
}

void nr6()
{
	PORTD |= a;
	PORTD |= f;
	PORTD |= g;
	PORTD |= c;
	PORTD |= d;
	PORTD |= e;

	PORTD &=~b;
}

void nr7()
{
	PORTD |= a;
	PORTD |= b;
	PORTD |= c;
	
	PORTD &=~d;
	PORTD &=~e;
	PORTD &=~f;
	PORTD &=~g;
}

void nr8()
{
	PORTD |= a;
	PORTD |= b;
	PORTD |= f;
	PORTD |= g;
	PORTD |= c;
	PORTD |= d;
	PORTD |= e;
	
}

void nr9()
{
	PORTD |= a;
	PORTD |= b;
	PORTD |= f;
	PORTD |= g;
	PORTD |= c;
	PORTD |= d;

	PORTD &=~e;
}