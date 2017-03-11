
#ifndef ADCTEMP_H_
#define ADCTEMP_H_

void adc_init();
uint16_t read_adc(uint8_t channel);
float temperatura_celsius();
void control_Led_temp();
void afisare_temp();
//ISR(USART_RX_vect);

#endif /* ADCTEMP_H_ */