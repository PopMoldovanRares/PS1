

#ifndef PWM_H_
#define PWM_H_

//#define LEDPWM 0x08

void timer0Initializare();
void control_led_pwm();
ISR(TIMER0_OVF_vect);

#endif /* PWM_H_ */