#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

// Inputs
#define PUSH0 PIND0
#define PUSH1 PIND1

// Outputs
#define LED1	PORTB0
#define LED2	PORTB1
#define OUTM1	PORTB2
#define OUTM2	PORTB3
#define OUTMEN  PORTB4

// Outputs - States
#define LED1_ON		PORTB |=  _BV(LED1)
#define LED1_OFF	PORTB &= ~_BV(LED1)

#define LED2_ON		PORTB |=  _BV(LED2)
#define LED2_OFF	PORTB &= ~_BV(LED2)

#define OUTM1_ON	PORTB |=  _BV(OUTM1)
#define OUTM1_OFF	PORTB &= ~_BV(OUTM1)

#define OUTM2_ON	PORTB |=  _BV(OUTM2)
#define OUTM2_OFF	PORTB &= ~_BV(OUTM2)

#define OUTMEN_ON	PORTB |=  _BV(OUTMEN)
#define OUTMEN_OFF	PORTB &= ~_BV(OUTMEN)

// Read
#define read_PUSH0 bit_is_clear(PIND, PUSH0)
#define read_PUSH1 bit_is_clear(PIND, PUSH1)

// Read - States
#define OFF		read_PUSH0 == 0 && read_PUSH1 == 0
#define CW		read_PUSH0 == 0 && read_PUSH1 == 1
#define CCW		read_PUSH0 == 1 && read_PUSH1 == 0
#define STOP	read_PUSH0 == 1 && read_PUSH1 == 1


void init_2inputs(uint8_t input1, uint8_t input2);
void init_5outputs(uint8_t output1, uint8_t output2, uint8_t output3, uint8_t output4, uint8_t output5);

int main(void)
{
	init_2inputs(PUSH0, PUSH1);
	init_5outputs(LED1, LED2, OUTM1, OUTM2, OUTMEN);
	while (1)
	{
		
		if ( OFF )
		{
			LED1_OFF;
			LED2_OFF;
			
			OUTM1_OFF;
			OUTM2_OFF;
			OUTMEN_OFF;
		}
			else if ( CW )
			{
				LED1_OFF;
				LED2_ON;
			
				OUTM1_ON;
				OUTM2_OFF;
				OUTMEN_ON;
			}
				else if ( CCW )
				{
					LED1_ON;
					LED2_OFF;
					
					OUTM1_OFF;
					OUTM2_ON;
					OUTMEN_ON;
				}
					else if ( STOP )
					{
						LED1_ON;
						LED2_ON;
						
						OUTM1_ON;
						OUTM2_OFF;
						OUTMEN_OFF;
					}
		_delay_ms(20);
	}
	
}
void init_2inputs(uint8_t input1, uint8_t input2)
{
	// Entradas
	DDRD  &= ~( _BV(input1) | _BV(input2) );
	PORTD |=  ( _BV(input1) | _BV(input2) );
}

void init_5outputs(uint8_t output1, uint8_t output2, uint8_t output3, uint8_t output4, uint8_t output5)
{
	// Salidas
	DDRB |=   ( _BV(output1) | _BV(output2) | _BV(output3) | _BV(output4) | _BV(output5) );
	PORTB &= ~( _BV(output1) | _BV(output2) | _BV(output3) | _BV(output4) | _BV(output5) );
}

