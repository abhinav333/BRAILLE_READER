#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include<string.h>
#define F_CPU 8000000
#include "integer.h"

#include "pff.h"
#include "pff.c"
//#include"lcd.h"
//#include"lcd.c"
#include"diskio.h"
#include"mmc.c"
#include"buzzer.c"
#include"braillecode.c"


#define FORWARD 1
#define BACKWARD 2
#define PAUSE 3
#define STATE0 0
#define STATE1 1
#define NCHANGE 0
#define CHANGE 1
#define START 0
#define END 1


unsigned int chk_button()
{
 
 if(!(PIND & 0x01))
 {
   
   
   //_delay_ms(170);
   return FORWARD;
 
   

 }
 if(!(PIND & 0x02))
 {
  	
 	//_delay_ms(170);
   return BACKWARD;
	
	

 
 }


 if(!(PIND & 0x08))
 {
   
	
	 //_delay_ms(170);
	 return PAUSE;
	
	
 }
 
 return 0;

}




void getbinary(unsigned char byte11,char *binarr11)
{
 int t,i,bit11=0;
 for(i=7;i>=0;i--)
 {

  t=(int)byte11;

  t&=(1<<i);
  t>>=i;
  bit11=t ? 1 : 0;
  itoa(bit11,&binarr11[7-i],10);
 }



}


int main(void)
{
	//lcd_init(LCD_DISP_ON_CURSOR); /* initialize lcd, display on, cursor on */
                                  /* for more options for*/
    BYTE buf11,dir_status=START;                             /* lcd_init(), view lcd.h file*/
    BYTE schange=CHANGE,state=STATE0;
    UINT bread=1;
	FATFS fs;
	BYTE buff11[8];
	FRESULT fr11='N';
	FILINFO file;
	DIR dr;
	char fpath[25];
  char try=10;;
    //lcd_clrscr();
	//lcd_home();	
	char ocr[4];
    char n=0;	
                      /* run continuously */
    
    
	//button initialization 
   DDRD=0xF0;
   
   PORTD=0x0F;
   PORTD|=0x80;
   PORTD&=~0x40;

	//braille cell init
   DDRA=0xFF;
   PORTA=0; 
	

/*

    fr11=disk_initialize();
	getbinary(fr11,buff11);
	//lcd_puts(buff11);
	_delay_ms(2000);
	//lcd_clrscr();
    //lcd_home();
	_delay_ms(2000);
	*/

/*
	
	init_spi();		
	DESELECT();
	for (n = 20; n; n--) rcv_spi();


     
	 fr11=send_cmd(CMD0, 0);
	
	getbinary(fr11,buff11);
	//lcd_puts(buff11);
	_delay_ms(2000);
	//lcd_clrscr();
    //lcd_home();
	_delay_ms(2000);
	n=10;
	while(n)
	{
     fr11=send_cmd(CMD8,0x01AA);
     n--;
	 if(fr11==1)break;
	}
	
	for (n = 0; n < 4; n++) ocr[n] = rcv_spi();	
  
	getbinary(fr11,buff11);
	//lcd_puts(buff11);
	_delay_ms(2000);
	//lcd_clrscr();
    //lcd_home();
	_delay_ms(2000);
	
  
    
  	
     getbinary(ocr[0],buff11);	  
	 //lcd_puts(buff11);
	_delay_ms(2000);
	//lcd_clrscr();
    //lcd_home();
	_delay_ms(2000);
	
	getbinary(ocr[1],buff11);	  
	//lcd_puts(buff11);
	_delay_ms(2000);
	//lcd_clrscr();
    //lcd_home();
	_delay_ms(2000);
	
	getbinary(ocr[2],buff11);	  
	//lcd_puts(buff11);
	_delay_ms(2000);
	//lcd_clrscr();
    //lcd_home();
	_delay_ms(2000);
	
	getbinary(ocr[3],buff11);	  
	//lcd_puts(buff11);
	_delay_ms(2000);
	//lcd_clrscr();
    //lcd_home();
	_delay_ms(2000);
	*/
	// Pin 7 & 6 of c act as triggers for two cell
	




	while(try)
	{
     fr11=pf_mount(&fs);
     try--;
     if(!fr11) break;    
	}
	if(fr11)
	{
     //lcd_puts("Mount Error");
	 play_buzzer(5,1,20);
      wdt_reset();
	  WDTCR=(1<<WDE) | (1<<WDP2)|(1<<WDP1)|(1<<WDP0);
	  _delay_ms(3000);
	}
	
   	
    fr11=pf_opendir(&dr,"BOOKS");
	if(fr11)
	{
		//lcd_puts("DIR Open Error");
		play_buzzer(5,3,20);
		 
	}
	 
	fr11=pf_readdir(&dr,&file);
	
	if(fr11)
	{
		//lcd_puts("DIR EXp Error");
		play_buzzer(5,5,20);
		 
	}
	//lcd_puts(file.fname);
//temporaryt
	
	play_buzzer(1,1,40);
	
	while(1)
	{
	  if(state==STATE0)
	  {
	   while(chk_button()!=PAUSE)
	   {
	     if(chk_button()==FORWARD && dir_status!=END)
        {   
	      buzzer_on();
		  _delay_ms(50);
		  buzzer_off();
		  _delay_ms(150);
		  schange=CHANGE;
		  //lcd_clrscr();
		  //lcd_home();
		  fr11=pf_readdir(&dr,&file);
	  	  if(fr11)play_buzzer(2,5,20);;
	      if(file.fname[0]==0)dir_status=END;
		  //lcd_puts(file.fname);
		  
		  	}
        if(chk_button()==BACKWARD)
        {
          buzzer_on();
		  _delay_ms(50);
		  buzzer_off();
		  _delay_ms(150);
		  dir_status=START;
		  schange=CHANGE;
		  //lcd_clrscr();
		  //lcd_home();
		  fr11=pf_readdir(&dr,0);
		  fr11=pf_readdir(&dr,&file);
		  if(fr11)play_buzzer(2,5,20);;
		  //lcd_puts(file.fname);
		  dir_status=START;
          
     	} 
   	   }
	    
	    buzzer_on();
		_delay_ms(50);
		buzzer_off();
		_delay_ms(150);
		
	   state=STATE1;
	  }
	  
	  
	  if(state==STATE1)
	  { 
	     if(schange==CHANGE)
		  {
		   sprintf(fpath,"BOOKS/%s",file.fname);
		   fr11=pf_open(fpath);
		   if(fr11)play_buzzer(5,5,20);
		   schange=NCHANGE;
		  }
		
	    //lcd_clrscr();
		//lcd_home();
		while(chk_button()!=PAUSE)
		{
		 
		  fr11=pf_read(&buf11,1,&bread);
          if(!bread) {state=STATE0; break;} 		
	
             //lcd_putc(buf11);
            print_braille_char(buf11);
		} 
	   
	   
	    buzzer_on();
		_delay_ms(50);
		buzzer_off();
		_delay_ms(150);
		
		state=STATE0;
	  }
	}
	

	
	
		
}

