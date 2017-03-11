/**
 * Aprindere/stingere LED prin intermediul comunicatiei seriale. Litera “A”
 *  trimisa de pe PC va aprinde LED-ul iar litera “S” va stinge LED-ul.
 */

//led conectat la Digital Input 2
#define ledSerial 0x04

void Serial_citire_comanda()
void Serial_apride_led();
void Serialstinge_led();
int Serial_conditie_aprinde_stingeLED(bool raspuns);
