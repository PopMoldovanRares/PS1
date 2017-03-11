/*
 * Timer1.h
 *
 * Created: 1/17/2017 11:44:25 PM
 *  Author: didi
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#define  LEDPWM 0x08
void timer1_pwm();
void initializare_timer1();
ISR(TIMER1_OVF_vect);

#endif /* TIMER1_H_ */