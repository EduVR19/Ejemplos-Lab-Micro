/*
 * GPIO.c
 *
 * Created: 28/04/2022 04:09:17 p. m.
 *  Author: jdgar
 */ 

#include <avr/io.h>
#include "GPIO.h"

void init_ports(void)
{
//--Outputs
	//DISPLAY
	DDRD = 0xFF;
	//BARRIDO
	DDRB |= _BV(BARRIDO_M)|_BV(BARRIDO_C)|_BV(BARRIDO_D)|_BV(BARRIDO_U);//Salidas
	//LEDS
	DDRB  |= _BV(LED4);//Salidas
}