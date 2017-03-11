#ifndef USART_H_
#define USART_H_


#define F_CPU 16000000UL
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_citire(char *data, char lungime);
ISR(USART_RX_vect);



#endif /* USART_H_ */