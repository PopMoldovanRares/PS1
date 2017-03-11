#define ledSerial 0x04
#define led1secunda 0x08

int primesteComanda = 0;
bool raspuns = 0;
bool intrerupere = 0;

void timer1_1s()
{
  cli(); //stop intreruperi

  /* Setare timer care sa genereze o intrerupere la 1s */
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// setare tot registrul TCCR1A pe 0
  TCCR1B = 0;// setare tot registrul TCCR1B pe 0
  
  //timmer/counter register, contine valoarea timer-ului
  TCNT1  = 0;//initilizare contor cu 0
  
  // setare registru comparare pentru incrementearea cu 1hz
  // output compare register
  OCR1A = 15624;
  // = (16*10^6) / (1*1024) - 1 (must be <65536)
  // pornire mod CTC
  TCCR1B |= (1 << WGM12);
  // Setare biti CS10 si CS12 pentru de prescaler 1024 
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // permite intreruperi timer compare
  TIMSK1 |= (1 << OCIE1A);

  sei(); //da drumul la intreruperi
}
void setup()
{

  DDRD |= 0xFF;
  Serial.begin(9600);
  timer1_1s();

}

ISR(TIMER1_COMPA_vect) 
{ 
  //timerul1 genereaza o intrerupere la toggle 1Hz 
  //generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
  if (intrerupere) 
  {
      PORTD |= led1secunda;
      intrerupere = 0;
  }
  else 
  {
      PORTD &=~(led1secunda);
      intrerupere = 1;
  }
}

void Serial_citire_comanda()
{
  primesteComanda = Serial.read();
}

int Serial_conditie_aprindeLED(bool raspuns)
{
  if (primesteComanda == 'A')
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
  if (primesteComanda == 'S')
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
     Aprinde led cinectat la digital input 2
     digital input 2 = 0x04
  */
  PORTD |= ledSerial;
}

void Serial_stinge_led()
{
  /**
     Stinge led cinectat la digital input 2
     digital input 2 = 0x04
  */
  PORTD &= ~(ledSerial);
}

void loop()
{
  if (Serial.available() > 0)
  {
    Serial_citire_comanda();
    if ( Serial_conditie_aprindeLED(raspuns) == 1 )
    {
      Serial_aprinde_led();
      delay(500);
    }
    if ( Serial_conditie_stingeLED(raspuns) == 1 )
    {
      Serial_stinge_led();
      delay(500);
    }

  }
}
