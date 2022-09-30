// Interrupcion Interna

#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/interrupt.h>

#define LED			PORTB0
#define LED_TGLE	PORTB ^= _BV(LED)

void init_ports();
uint8_t counter = 0;
void init_timer0();
void timer0_on();
void timer0_off();

int main(void)
{
	cli(); // Clear Interruptions
	init_ports();
	init_timer0();
	timer0_on();
	sei(); // Set Interruptions
    while (1) 
    {
		if ( TCNT0 == 97 ) //0.1 segundos
		{
			counter++;
			
			TCNT0 = 0;
			
			if ( counter == 5 )
			{
				LED_TGLE;
				counter = 0;
				
			}
		}
    }
}

void init_ports()
{
	// Salidas
	DDRB  |=  _BV(LED);
	PORTB &= ~_BV(LED);
}
void init_timer0()
{
	// Normal			- 0 0 0
	TCCR0A &= ~( _BV(WGM00) );	// 0
	TCCR0A &= ~( _BV(WGM01) );	// 0
	TCCR0B &= ~( _BV(WGM02) );	// 0
	// TCCR01 - Timer Counter Control Register A
	// TCCR01 - Timer Counter Control Register B
	// WGM##  - Waveform Generator Mode #	
}
void timer0_on()
{
	// Encendido
	
	TCNT0 = 0;
	// TCN0 - Timer Counter Register
	
	// Prescaler 1024	- 1 0 1
	TCCR0B |=  ( _BV(CS00) );	// 1
	TCCR0B &= ~( _BV(CS01) );	// 0
	TCCR0B |=  ( _BV(CS02) );	// 1
	// TCCR01 - Timer Counter Control Register B
	// CS##   - Clock Select #
}
void timer0_off()
{
	// Apagado			- 0 0 0
	TCCR0B &= ~( _BV(CS00) );	// 0
	TCCR0B &= ~( _BV(CS01) );	// 0
	TCCR0B &= ~( _BV(CS02) );	// 0
	// TCCR01 - Timer Counter Control Register B
	// CS##   - Clock Select #
}
