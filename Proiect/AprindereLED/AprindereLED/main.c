
#include <avr/io.h>
#include "LED.h"
#include <util/delay.h>
#include "timer1.h"
#include <time.h>
#include <avr/interrupt.h>

int main(void)
{
	intializare();
	timer1_1s();
    while (1) 
    {
    }
}

