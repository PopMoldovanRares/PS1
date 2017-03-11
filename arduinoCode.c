int primesteComanda = 0;
bool raspuns = 0;
void setup()
{

DDRD |= 0xFF;
 Serial.begin(9600);
}



void Serial_citire_comanda()
{
    primesteComanda = Serial.read();
}

int Serial_conditie_aprindeLED(bool raspuns)
{
    if(primesteComanda == 'A')
    {
      raspuns = 1;
    }
    else 
    {
        raspuns = 0;
    }
    return raspuns;
}

int Serial_conditie_stingeLED(bool raspuns)
{
    if(primesteComanda == 'S')
    {
      raspuns = 1;
    }
    else 
    {
        raspuns = 0;
    }
    return raspuns;
}
void Serial_aprinde_led()
{
    /**
     * Aprinde led cinectat la digital input 2
     * digital input 2 = 0x04
     */
    PORTD |= 0x04;
}

void Serial_stinge_led()
{
    /**
     * Stinge led cinectat la digital input 2
     * digital input 2 = 0x04
     */
    PORTD &= ~(0x04);
}

void loop() 
{
  if(Serial.available()>0)
  {
      Serial_citire_comanda();
   if( Serial_conditie_aprindeLED(raspuns) == 1 )
        {
            Serial_aprinde_led();
            delay(500);
        }
         if( Serial_conditie_stingeLED(raspuns) == 1 )
        {
            Serial_stinge_led();
            delay(500);
        }
        
  }
}