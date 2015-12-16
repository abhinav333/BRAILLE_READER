

#include<avr/io.h>		//This is the header for AVR Microcontroller.
#include<util/delay.h>  //header file to generate time delay.
#define F_CPU 8000000

int main(void)
 {	
				// PortC initiallization as all bits low.
	DDRA=0xFF;			// PortC data direction declaration as out put.
	PORTA=0;
	DDRD=0xFF;
	PORTD=0;
	
	while(1)			//This is for the the infinite loop.
	{

     PORTA=0;
      _delay_ms(2000);
      PORTA=0b11111111;
	 _delay_ms(2000);
	 }
}
