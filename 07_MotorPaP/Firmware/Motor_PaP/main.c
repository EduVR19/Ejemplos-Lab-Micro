#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


// Definiciones
#define OUT_A PORTB4
#define OUT_B PORTB3
#define OUT_C PORTB2
#define OUT_D PORTB1

#define BTN PORTD0

// Constantes
const int TIME = 50;

// Macros - Inputs
#define OUT_A_ON  PORTB |=  _BV( OUT_A )
#define OUT_A_OFF PORTB &= ~_BV( OUT_A )

#define OUT_B_ON  PORTB |=  _BV( OUT_B )
#define OUT_B_OFF PORTB &= ~_BV( OUT_B )

#define OUT_C_ON  PORTB |=  _BV( OUT_C )
#define OUT_C_OFF PORTB &= ~_BV( OUT_C )

#define OUT_D_ON  PORTB |=  _BV( OUT_D )
#define OUT_D_OFF PORTB &= ~_BV( OUT_D )


#define BTN_PRESSED bit_is_clear(PIND, BTN)


// FSM
enum states
{
	s0,
	s1,
	s2,
	s3	
}state;

uint8_t btn_state = 0;

//Funciones
void init_ports(void);
uint8_t debounce(uint8_t);


int main(void)
{
	init_ports();
	
	state = s0;    
	
	while (1) 
    {
		switch(state)
		{
			//-- State 0
			case s0:
				OUT_A_ON;
				OUT_B_OFF;
				OUT_C_OFF;
				OUT_D_ON;
				if ( BTN_PRESSED )
				{
					state = s1;
				}
				else
				{
					state = s3;
				}
				_delay_ms(TIME);
			break;	
			
			//-- State 1
			case s1:
				OUT_A_ON;
				OUT_B_ON;
				OUT_C_OFF;
				OUT_D_OFF;
				if ( BTN_PRESSED )
				{
					state = s2;
				}
				else
				{
					state = s0;
				}
				_delay_ms(TIME);
			break;	
			
			//-- State 2
			case s2:
				OUT_A_OFF;
				OUT_B_ON;
				OUT_C_ON;
				OUT_D_OFF;
				if ( BTN_PRESSED )
				{
					state = s3;
				}
				else
				{
					state = s1;
				}
				_delay_ms(TIME);
			break;		
			
			//-- State 3
			case s3:
				OUT_A_OFF;
				OUT_B_OFF;
				OUT_C_ON;
				OUT_D_ON;
				if ( BTN_PRESSED )
				{
					state = s0;
				}
				else
				{
					state = s2;
				}
				_delay_ms(TIME);
			break;		
		}// Fin switch
    }// Fin while
}// Fin init main

//init_ports : Inicializa los puertos
void init_ports(void)
{
	// Entradas
	DDRD  &= ~( _BV(BTN) );
	PORTD |=  ( _BV(BTN) );
	
	
	// Salidas
	DDRB |= ( _BV(OUT_A) | _BV(OUT_B)| _BV(OUT_C)| _BV(OUT_D) );
	
}

