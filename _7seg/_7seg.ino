#define digital1(val) {DDRD|=0x08;PORTD=(val)?(PORTD|0x04):(PORTD&(~0x04));}
#define digital2(val) {DDRD|=0x02;PORTD=(val)?(PORTD|0x08):(PORTD&(~0x08));}
#define digital3(val) {DDRD|=0x01;PORTD=(val)?(PORTD|0x10):(PORTD&(~0x10));}
#define digital4(val) {DDRD|=0x10;PORTD=(val)?(PORTD|0x20):(PORTD&(~0x20));}
#define digital5(val) {DDRD|=0x40;PORTD=(val)?(PORTD|0x40):(PORTD&(~0x40));}
#define digital6(val) {DDRD|=0x80;PORTD=(val)?(PORTD|0x80):(PORTD&(~0x80));}
#define digital7(val) {DDRC|=0x40;PORTC=(val)?(PORTC|0x01):(PORTC&(~0x01));}
#define digital8(val) {DDRC|=0x10;PORTC=(val)?(PORTC|0x02):(PORTC&(~0x02));}


void setup()
{
  // put your setup code here, to run once:
  DDRD |= 0xFF;
 
}

void write0()
{
    digital2(0x04);
    digital4(0x10); 
    digital5(0x20); 
    digital6(0x40); 
    digital7(0x80);
    digital8(0x01); 
}
void write8()
{
    digital1(0x02);
    digital2(0x04);
    digital4(0x10); 
    digital5(0x20); 
    digital6(0x40);
    digital7(0x80); 
    digital8(0x01);    
}
void loop() 
{
  // put your main code here, to run repeatedly:
  //PORTD |= 0x01; //nu face nimic
  //delay(500);
       write8();
     delay(1000);
  

}
