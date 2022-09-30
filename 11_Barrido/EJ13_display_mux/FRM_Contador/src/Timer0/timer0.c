/*
 * timer0.c
 *
 * Created: 12/05/2022 04:10:53 p. m.
 *  Author: jdgar
 */ 


#include <avr/io.h>
#include "timer0.h"

void init_timer0(void)
{
	//Modo CTC
	TCCR0B &= ~_BV(WGM02);
	TCCR0A |=  _BV(WGM01);
	TCCR0A &= ~_BV(WGM00);
	
	//Top 0.1s
	OCR0A = 9;
	
	//Enable
	TIMSK0 |=  _BV(OCIE0A);
}
void on_timer0  (void)
{
	//Reinicia el conteo
	TCNT0 = 0;
	
	//Prescaler 1024
	TCCR0B |=  _BV(CS02);
	TCCR0B &= ~_BV(CS01);
	TCCR0B |=  _BV(CS00);
}
void off_timer0 (void)
{
	//STOP
	TCCR0B &= ~_BV(CS02);
	TCCR0B &= ~_BV(CS01);
	TCCR0B &= ~_BV(CS00);
}