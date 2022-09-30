/*
 * timer0.c
 *
 * Created: 26/04/2022 04:42:34 p. m.
 *  Author: jdgar
 */ 

#include <avr/io.h>
#include "timer0.h"

void timer0_init(void)
{
	// Modo CTC
	TCCR0A &=~_BV(WGM00);
	TCCR0A |= _BV(WGM01);
	TCCR0B &=~_BV(WGM02);
	//Top
	OCR0A = 42; //60hz
	//Enable
	TIMSK0   |= _BV(OCIE0A);
}

void timer0_on()
{
	//
	TCNT0 = 0; //conteo se reinicia
	//Prescaler 1024
	TCCR0B |= _BV(CS00);
	TCCR0B &=~_BV(CS01);
	TCCR0B |= _BV(CS02);
}

void timer0_off()
{
	//Prescaler 1024
	TCCR0B &=~_BV(CS00);
	TCCR0B &=~_BV(CS01);
	TCCR0B &=~_BV(CS02);
}
