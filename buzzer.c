#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"integer.h"
unsigned char i=0;
unsigned int onc,offc;
void buzzer_on()
{
   DDRD|= 0x20;
   PORTD|=0x20; 
}
void buzzer_off()
{
    PORTD&=~0x20; 
}



void play_buzzer(unsigned char on,unsigned char  off,unsigned char sec)
{
  char tmr=0;
  
  TCCR1A|=(1<< COM1A0);
  TCCR1B |= (1 << CS12)  |(1<< WGM12);
   
  TIMSK |= (1 << OCIE1A);
  
  TCNT1=0;
  OCR1A=3125;
  onc=3125*on;
  offc=3125*off;
  
  sei();
  
  while(tmr<sec){
  _delay_ms(100);
  tmr++;
  }
  TCCR1A=0;
  TCCR1B=0;
  TIMSK=0;
}


ISR(TIMER1_COMPA_vect)
{
  
  i^=0x01;
  if(i)
  {
   OCR1A=onc;
  }
  if(!i)
  {
   OCR1A=offc;
  }
 
}