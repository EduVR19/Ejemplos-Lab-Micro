/****************************************************
 * LLENAR ESTE ESPACIO CON LOS SIGUIENTES DATOS:    *
 * Nombre:                                          *
 * Hora clase:                                      *
 * Día:                                             *
 * N° de lista:                                     *
 * N° de Equipo:                                    *
 * Dispositivo:                                     *
 * Rev:                                             *
 * Propósito de la actividad:                       *
 *                                                  *
 *                                    Fecha:        *
 ***************************************************/

#include <avr/io.h>
#define F_CPU 1000000UL // 1Mhz
#include <util/delay.h> // Biblioteca de retardos
#include <avr/interrupt.h>
#include "debouncing/debouncing.h"
#include "int_ext/ext_int.h"
#include "timer0/timer0.h"


//--Salidas

//--Display
#define DISPLAY PORTD
//--Barrido
#define B1 PORTB0 
#define B2 PORTB1 
#define B3 PORTB2 
#define B4 PORTB3
 

//--Declaracion de funciones
void init_ports(void);


//--Variable global
uint8_t k;
//uint8_t i = 0;
volatile int z = 0;
volatile int val = 0;
volatile int i = 0;
//-Array
                    //0    1    2    3    4    5    6
uint8_t numeros[10] ={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xE6};
uint8_t selector[4];	
////////////-----MAIN-----//////////////////
int main(void)
{
	cli();
	init_ports();
	timer0_init();
	sei();
	timer0_on();
	while (1)
	{     //1234	
		z = 1234;
		selector[0] =  z / 1000; // Display millares 1
		selector[1] = (z % 1000)/100; // Display centenas 2
		selector[2] = (z % 100)/10; // Display decenas 3
		selector[3] =  z % 10; // Display unidades 4
		PORTB = ~(1<<i);
		DISPLAY = numeros[selector[i]];

	} // Fin while
} // Fin main

void init_ports(void)
{
//--Outputs
	//--DISPLAY
	DDRD = 0xFF;
	DDRB |= _BV(B1) | _BV(B2) | _BV(B3) | _BV(B4);
	
}

ISR (TIMER0_COMPA_vect)
{
	if (i >= 3)
	{
		i = 0;
	}
	else
	{
		i++;
	}
}



