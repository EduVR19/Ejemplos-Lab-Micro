// Interrupcion Interna - Timer 1

#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

#define	LED			PORTB0
#define LED_TGGLE	PORTB ^= _BV(LED)

void init_ports();

void init_timer1();
void timer1_on();
void timer1_off();

int main(void)
{
	cli();
	init_ports();
	init_timer1();
	timer1_on();
	sei();
	
	while (1)
	{
	}
}

void init_ports()
{
	// Salida
	DDRB  |=  ( _BV(LED) ); // Salida
	PORTB |=  ( _BV(LED) ); // LOW - Source
	
}


void init_timer1()
{
	/******* 1 - Inicializar Modo *******/
	// CTC			- 0 1 0 0
	TCCR1A &= ~( _BV(WGM10) );	// 0
	TCCR1A &= ~( _BV(WGM11) );	// 0
	TCCR1B |=  ( _BV(WGM12) );	// 1
	TCCR1B &= ~( _BV(WGM13) );	// 0
	
	// TCCR1A - Timer Counter Control Register 1A
	// TCCR1B - Timer Counter Control Register 1B
	// WGM##  - Waveform Generator Mode #
	OCR1A = 58593; // 1 minuto // Modo CTC - Cambio del TOP
	// OCR0A - Output Compare Register 1A - Tiene un valor de 8 bits
	// y está constantemente comparado con el TCNT0 (Timer Counter Register)
	
	/******* 2 - Habilitar interrupción *******/
	TIMSK1 |= ( _BV(OCIE1A) );
	// TIMSK1 - Timer Interrupt Mask 1A
	// OCIE1A - Output Compare Interruption Enable 1A
	
}
void timer1_on()
{
	/******* 1 - Inicializar TCNT0 *******/
	TCNT1 = 0;
	// TCN0 - Timer Counter Register 1 - Variable contadora con la que se compara
	// el OCR0A (Output Compare Register)
	
	/******* 2 - Habilitar Reloj *******/
	// Prescaler 1024	- 1 0 1
	TCCR1B |=  ( _BV(CS10) );	// 1
	TCCR1B &= ~( _BV(CS11) );	// 0
	TCCR1B |=  ( _BV(CS12) );	// 1
	// TCCR01 - Timer Counter Control Register 1B
	// CS1#   - Clock Select 1#
}
void timer1_off()
{
	/******* 1 - Desabilitar reloj *******/
	// No clock source	- 0 0 0
	TCCR1B &= ~( _BV(CS10) );	// 0
	TCCR1B &= ~( _BV(CS11) );	// 0
	TCCR1B &= ~( _BV(CS12) );	// 0
	// TCCR01 - Timer Counter Control Register 1B
	// CS1#   - Clock Select 1#
}

ISR(TIMER1_COMPA_vect)
{
	LED_TGGLE;
}
