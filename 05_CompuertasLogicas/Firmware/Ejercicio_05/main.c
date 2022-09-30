
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define PUSH0 PIND0
#define PUSH1 PIND1

#define read_PUSH0 bit_is_clear(PIND, PUSH0)
#define read_PUSH1 bit_is_clear(PIND, PUSH1)

#define LED1  PORTB0
#define LED2  PORTB1
#define LED3  PORTB2
#define LED4  PORTB3
#define LED5  PORTB4
#define LED6  PORTB5
	
#define LED1_ON  PORTB |=  _BV(LED1)
#define LED1_OFF PORTB &= ~_BV(LED1)

#define LED2_ON  PORTB |=  _BV(LED2)
#define LED2_OFF PORTB &= ~_BV(LED2)

#define LED3_ON  PORTB |=  _BV(LED3)
#define LED3_OFF PORTB &= ~_BV(LED3)

#define LED4_ON  PORTB |=  _BV(LED4)
#define LED4_OFF PORTB &= ~_BV(LED4)

#define LED5_ON  PORTB |=  _BV(LED5)
#define LED5_OFF PORTB &= ~_BV(LED5)

#define LED6_ON  PORTB |=  _BV(LED6)
#define LED6_OFF PORTB &= ~_BV(LED6)

void init_ports(void);
int main(void)
{
    init_ports();
    while (1) 
    {
		//AND
		if ( read_PUSH0 && read_PUSH1 )
		{
			LED1_ON;
		}
		else
		{
			LED1_OFF;
		}
		//NAND
		if ( !(read_PUSH0 && read_PUSH1) )
		{
			LED2_ON;
		}
		else
		{
			LED2_OFF;
		}
		
		//OR
		if ( read_PUSH0 || read_PUSH1 )
		{
			LED3_ON;
		}
		else
		{
			LED3_OFF;
		}
		//NOR
		if ( !(read_PUSH0 || read_PUSH1) )
		{
			LED4_ON;
		}
		else
		{
			LED4_OFF;
		}
		
		//EXOR
		if ( read_PUSH0 != read_PUSH1 )
		{
			LED5_ON;
		}
		else
		{
			LED5_OFF;
		}
		//EXNOR
		if ( !(read_PUSH0 != read_PUSH1) )
		{
			LED6_ON;
		}
		else
		{
			LED6_OFF;
		}		
    }
	
}
void init_ports(void)
{
	// Entradas
	DDRD  &= ~( _BV(PUSH0) | _BV(PUSH1) );
	PORTD |=  ( _BV(PUSH0) | _BV(PUSH1) );
	
	// Salidas
	DDRB |=   ( _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4) | _BV(LED5) | _BV(LED6) );
	PORTB &= ~( _BV(LED1) | _BV(LED2) | _BV(LED3) | _BV(LED4) | _BV(LED5) | _BV(LED6) );
}

