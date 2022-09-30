/*
 * debounce.c
 *
 * Created: 08/04/2022 09:21:56 a. m.
 *  Author: jdgar
 */ 


//#include <stdlib.h>
#include <avr/io.h>
#include "debounce.h"

//Variables
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
