
#include <time.h>
#include <avr/interrupt.h>

#ifndef TIMER1_H_
#define TIMER1_H_

void timer1_1s();
ISR(TIMER1_COMPA_vect);


#endif /* TIMER1_H_ */