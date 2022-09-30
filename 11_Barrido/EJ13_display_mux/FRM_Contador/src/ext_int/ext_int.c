/*
 * ext_int.c
 *
 * Created: 28/04/2022 04:03:09 p. m.
 *  Author: jdgar
 */ 

#include <avr/io.h>
#include "ext_int.h"


void init_extInt(void)
{
	//INT0
	//LOW level
	EICRA &= ~_BV(ISC00);
	EICRA &= ~_BV(ISC01);
	//Enable
	EIMSK |= _BV(INT0);

	//INT1
	//LOW level
	EICRA &= ~_BV(ISC10);
	EICRA &= ~_BV(ISC11);
	//Enable
	EIMSK |= _BV(INT1);
}