#define LEDSerial 0x10
#define LEDTimer 0x20

int led =13;
int led2 = 12;

void setup()
{
  DDRB |= 0x20;
  DDRB |= 0x10;
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  /*
  PORTB |= LEDSerial;
  delay(500);
  PORTB &= ~(LEDSerial);
  delay(500);
*/
  PORTB |= LEDTimer;
  delay(500);
  PORTB &= ~(LEDTimer);
  delay(500);

  
  

  delay(1000);
}
