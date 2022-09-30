/*
 * ext_int.c
 *
 * Created: 26/04/2022 04:20:09 p. m.
 *  Author: jdgar
 */ 

#include <avr/io.h>
#include "ext_int.h"

void init_ext_int(void)
{
	//INT0
	//Low level
	EICRA &=~ _BV(ISC00);
	EICRA &=~ _BV(ISC01);
	//Enable
	EIMSK |= _BV(INT0);
	
	//INT1
	//Low level
	EICRA &=~ _BV(ISC10);
	EICRA &=~ _BV(ISC11);
	//Enable
	EIMSK |= _BV(INT1);
}