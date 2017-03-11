#define e 0x01
#define d 0x02
#define c 0x04
#define g 0x10
#define f 0x20
#define a 0x40
#define b 0x80
#define buton 0x04
int contor =0;
int apasare = 0;
void setup() 
{
  // put your setup code here, to run once:
  DDRD|=0xFF;
  DDRB |=e;
  DDRB |=d;
  
  DDRB&=~(0x10); //setare port 12 ca input
  PORTB|=0x10; //setare puul up
}

void nr0()
{
  PORTD |= a;
  PORTD |= b;
  PORTD |= c;
  PORTB |= d;
  PORTB |= e;
  PORTD |= f;
  
  PORTD &=~g;  
}

void nr1()
{
  PORTD |= b;
  PORTD |= c;  
 
  PORTD &=~a;
  PORTB &=~d;
  PORTB &=~e;
  PORTD &=~f;
  PORTD &=~g;
}

void nr2()
{
  PORTD |= a;
  PORTD |= b;   
  PORTD |= g;
  PORTB |= e;
  PORTB |= d;
  
  PORTD &=~f;
  PORTD &=~c;
}

void nr3()
{
  PORTD |= a;
  PORTD |= b;
  PORTD |= c;
  PORTB |= d;
  PORTD |= g;
  
  PORTB &=~e;
  PORTD &=~f;
}

void nr4()
{
  PORTD |= f;
  PORTD |= g;
  PORTD |= b;
  PORTD |= c;  

  PORTD &=~a;
  PORTB &=~d;
  PORTB &=~e;
}

void nr5()
{
  PORTD |= a;
  PORTD |= f;
  PORTD |= g;
  PORTD |= c;
  PORTB |= d;
  
  PORTD &=~b;
  PORTB &=~e;  
}

void nr6()
{
  PORTD |= a;
  PORTD |= f;
  PORTD |= g;
  PORTD |= c;
  PORTB |= d;
  PORTB |= e;  

  PORTD &=~b;
}

void nr7()
{
  PORTD |= a;
  PORTD |= b;
  PORTD |= c;
  
  PORTB &=~d;
  PORTB &=~e;
  PORTD &=~f;
  PORTD &=~g;  
}

void nr8()
{
  PORTD |= a;
  PORTD |= b;
  PORTD |= f;
  PORTD |= g;
  PORTD |= c;
  PORTB |= d;
  PORTB |= e; 
    
}

void nr9()
{
  PORTD |= a;  
  PORTD |= b;
  PORTD |= f;
  PORTD |= g;
  PORTD |= c;
  PORTB |= d; 

  PORTB &=~e;
}
void loop() 
{
  
  
  
/*  if(contor > 100 && apasare == 1)
  {
    nr1();
    //apasare++;
  }
  if(contor <10)
  {
    nr0();
    apasare++;
  }
/*
  switch (apasare)
  {
    case 0: nr0();  break;
    case 1: nr1();  break;
  }
  /*
  PORTB |= e;
  delay(500);
  //PORTD &=~(e);
  //delay(500);

  PORTD |= d;
  delay(500);
  //PORTD &=~(d);
  //delay(500);
 
  PORTD |= g;
  delay(500);
  //PORTD &=~(g);
  //delay(500);

  PORTD |= f;
  delay(500);
  //PORTD &=~(f);
  //delay(500);
  
  PORTD |= a;
  delay(500);
  //PORTD &=~(a);
  //delay(500);
/*
  PORTD |= b;
  delay(500);
  //PORTD &=~(b);
  //delay(500);

  PORTD |= c;
  delay(500);
  //PORTD &=~(c);
  //delay(500);
  delay(2000);
  //inchidere pe rand
  
  PORTD &=~(a);
  delay(500);
  PORTD &=~(b);
  delay(500);
  PORTD &=~(c);
  delay(500);
  PORTD &=~(d);
  delay(500);
  PORTD &=~(e);
  delay(500);
  PORTD &=~(g);
  delay(500);
  PORTD &=~(f);
  delay(500);

  
  
  if( (PINB & 0x04) == 0)
  {
    if(contor < 255)
    {
      contor++;
      if(contor == 255)
      {
        apasare = 1;
        nr0();
      }
    }
  }
  else
      {
        if(contor > 10 && apasare == 1)
        {
          contor--;
          if(contor == 10)
          {
            apasare = 2;
            nr1();  
          }
        }
      }
  */
  /*
  nr0();
  delay(1000);
  nr1();
  delay(1000);
  nr2();
  delay(1000);
  nr3();
  delay(1000);
  nr4();
  delay(1000);
  nr5();
  delay(1000);
  nr6();
  delay(1000);
  nr7();
  delay(1000);
  nr8();
  delay(1000);
  nr9();
  delay(1000);*/
}
