#include <avr/io.h>
#include "segment.h"
#include "buton.h"

int contor =0;
int apasare = 0;

void initializare_buton()
{
	
	  DDRB&=~(0x10); //setare port 12 ca input
	  PORTB|=0x10; //setare puul up
}

void functionare_buton()
{
	if(PINB&0x10)
	{
		
		if(contor < 255)
		{
			contor++;
			if(contor == 255)
			{
				switch(apasare)
				{
					case 0: nr0(); break;
					case 1: nr1(); break;
					case 2: nr2(); break;
					case 3: nr3(); break;
					case 4: nr4(); break;
					case 5: nr5(); break;
					case 6: nr6(); break;
					case 7: nr7(); break;
					case 8: nr8(); break;
					case 9: nr9(); apasare = -1; break;
				}
				apasare++;
			}
		}
	}
	else
	{
		if(contor>0)
		{
			contor--;
		}
	}
}