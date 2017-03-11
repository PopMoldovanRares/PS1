/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

void setup()
{
  // put your setup code here, to run once:
  DDRD |= 0xFF;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  PORTD |= 0x04;
  delay(500);
  //PORTD &=~(0x04);
  //delay(500);
}
