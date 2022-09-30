/*
 * debouncing.c
 *
 * Created: 26/04/2022 03:36:23 p. m.
 *  Author: jdgar
 */ 

#include <avr/io.h>
#include "debouncing.h"

//Variables globales
uint8_t estadoActual = 0;
uint8_t estadoAnterior = 0;

uint8_t debounce_switch(uint8_t pin)
{
	estadoAnterior = estadoActual;
	estadoActual = bit_is_clear(SWITCH_PIN,pin);

	//Se presiono
	if ( estadoAnterior == 0 && estadoActual == 1)
	{
		return 1;
	} //Sigue presionado
	else if (estadoAnterior == 1 && estadoActual == 1)
	{
		return 0;
	}// Cualquier otra opcion
	else
	{
		return 0;
	}
}
