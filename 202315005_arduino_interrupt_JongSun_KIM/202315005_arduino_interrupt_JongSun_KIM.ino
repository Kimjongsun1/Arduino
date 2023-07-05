#include <MsTimer2.h>

unsigned int count=0;
char toggle0=1;

void setup() 
{
  pinMode(13, OUTPUT);
  TCCR0A = 0; //TCCR0A initialize
  
  TCCR0B = 0; //TCCR0B initialize
  
  TCNT0 = 0;  //TCNT0 initialize

  OCR0A= 255; 

  TCCR0B |= (1<<WGM02);

  TCCR0B |= (1<<CS02) | (0<<CS00);

  TIMSK0 |= (1<<OCIE0A);

  sei();
}

ISR(TIMER0_COMPA_vect){

  count++;

  if(count>250)
  {
    if (toggle0)
    {
        digitalWrite(13,HIGH);
        toggle0 = 0;
    }
    else
    {
      digitalWrite(13,LOW);
      toggle0 = 1;
    }
    count=0;
    
    TCNT0=0;
  }

}
void loop() {

  // put your main code here, to run repeatedly:

 

}
