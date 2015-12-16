#define  GAP 250
#define  GAP1 250
#include"avr/io.h"
#include"util/delay.h"

void print_braille_char(unsigned char ch)
{
  switch(ch)
  {
    case ' ':
	 PORTD^=0xC0;
	 break;
    case '!':
	 PORTA=0b00011011;
     break;	
	case '"':
	 PORTA=0b00100000 ;
     break;	
	case '#':
	 PORTA=0b00111010 ;
     break;	
	case '$':
	 PORTA=0b00001111 ;
     break;	
	case '%':
	 PORTA=0b00001110 ;
     break;	
	case '&':
	 PORTA=0b00011111 ;
     break;	
	case '\'':
	 PORTA=0b00010000 ;
     break;	
	case '(':
	 PORTA=0b00111101 ;
     break;	
	case ')':
	 PORTA=0b00111011 ;
     break;	
	case '*':
	 PORTA=0b00001100 ;
     break;	
	case '+':
	 PORTA=0b00011010 ;
     break;	
	case ',':
	 PORTA=0b00001000 ;
     break;	
	case '_':
	 PORTA=0b00011000 ;
     break;	
	case '.':
	 PORTA=0b00001010 ;
     break;	
	case '/':
	 PORTA=0b00010010 ;
     break;	
	case '0':
	 PORTA=0b00111000 ;
     break;	
	case '1':
	 PORTA=0b00000001 ;
     break;	
	case '2':
	 PORTA=0b00010001 ;
     break;	
	case '3':
	 PORTA=0b00100001 ;
     break;	
	case '4':
	 PORTA=0b00101001 ;
     break;	
	case '5':
	 PORTA=0b00001001 ;
     break;	
	case '6':
	 PORTA=0b00110001 ;
     break;	
	case '7':
	 PORTA=0b00111001 ;
     break;	
	case '8':
	 PORTA=0b00011001 ;
     break;	
	case '9':
	 PORTA=0b00110000 ;
     break;	
	case ':':
	 PORTA=0b00101100 ;
     break;	
	case ';':
	 PORTA=0b00101000 ;
     break;	
	case '<':
	 PORTA=0b00001101 ;
     break;	
	case '=':
	 PORTA=0b00111111 ;
     break;	
	case '>':
	 PORTA=0b00110010 ;
     break;	
	case '?':
	 PORTA=0b00101110 ;
     break;	
	case '@':
	 PORTA=0b00000010 ;
     break;	
	case 'A' | 'a':
	 PORTA=0b00000100 ;
     break;	
	case 'B' | 'b':
	 PORTA=0b00000101 ;
     break;	
	case 'C' | 'c':
	 PORTA=0b00000110 ;
     break;	
	case 'D' | 'd':
	 PORTA=0b00100110 ;
     break;	
	case 'E' | 'e':
	 PORTA=0b00100100 ;
     break;	
	case 'F' | 'f':
	 PORTA=0b00000111 ;
     break;	
	case 'G' | 'g':
	 PORTA=0b00100111 ;
     break;	
	case 'H' | 'h':
	 PORTA=0b00100101 ;
     break;	
	case 'I' | 'i':
	 PORTA=0b00000011 ;
     break;	
	case 'J' | 'j':
	 PORTA=0b00100011 ;
     break;	
	case 'K' | 'k':
	 PORTA=0b00010101 ;
     break;	
	case 'L' | 'l':
	 PORTA=0b00010101 ;
     break;	
	case 'M' | 'm':
	 PORTA=0b00010110 ;
     break;	
	case 'N' | 'n':
	 PORTA=0b00110110 ;
     break;	
	case 'O' | 'o':
	 PORTA=0b00110100 ;
     break;	
	case 'P' | 'p':
	 PORTA=0b00010111 ;
     break;	
	case 'Q' | 'q':
	 PORTA=0b00110111 ;
     break;	
	case 'R' | 'r':
	 PORTA=0b00110101 ;
     break;	
	case 'T' | 't':
	 PORTA=0b00010011 ;
     break;	
	case 'U' | 'u':
	 PORTA=0b00011100 ;
     break;	
	case 'V' | 'v':
	 PORTA=0b00011101 ;
     break;	
	case 'W' | 'w':
	 PORTA=0b00101011 ;
     break;	
	case 'X' | 'x':
	 PORTA=0b00011110 ;
     break;	
	case 'Y' | 'y':
	 PORTA=0b00111110 ;
     break;	
	case 'Z' | 'z':
	 PORTA=0b00111100 ;
     break;	
	case '[':
	 PORTA=0b00001011 ;
     break;	
	case '\\':
	 PORTA=0b00101101 ;
     break;	
	case ']':
	 PORTA=0b00101111 ;
     break;	
	case '^':
	 PORTA=0b00100010 ;
     break;	
	case '-':
	 PORTA=0b00101010 ;
     break;	
		
	default:
     PORTA=0;
	 
  }
  _delay_ms(GAP);
  
  PORTA=0;
   _delay_ms(GAP1);
}