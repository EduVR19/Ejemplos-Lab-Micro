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
#include <avr/interrupt.h> //Biblioteca de interrupciones
#include "ext_int/ext_int.h"
#include "GPIO/GPIO.h"
#include "Timer0/timer0.h"

//Etiquetas y marcos
#define delay_barrido 10

//Numeros
#define N0 0xFC
#define N1 0x60
#define N2 0xDA
#define N3 0xF2
#define N4 0x66
#define N5 0xB6
#define N6 0xBE
#define N7 0xE0
#define N8 0xFE
#define N9 0xE6

//--Declaracion de funciones
void showNumber (uint16_t numero);

//Variables globales
                    //0    1    2    3    4    5    6
uint8_t  numeros[10] ={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xE6};
uint8_t  barrido[4];
uint16_t numero = 1234;
uint8_t unidades;
uint8_t decenas;
uint8_t centenas;
uint8_t millares;
volatile uint8_t i = 0;


int main(void)
{
	cli(); 
	init_ports();
	init_timer0();
	sei();
	
	on_timer0  ();

	while (1)
	{		
		millares =  numero / 1000;
		centenas = (numero % 1000)/100;
		decenas  = (numero % 100 )/10;
		unidades =  numero % 10;
		
		
	} // Fin while
} // Fin main

void showNumber (uint16_t numero)
{
	switch (numero)
	{
	case 0:
		DISPLAY = N0;
	break;
	case 1:
		DISPLAY = N1;
	break;
	case 2:
		DISPLAY = N2;
	break;
	case 3:
		DISPLAY = N3;
	break;
	case 4:
		DISPLAY = N4;
	break;
	}
}

ISR (TIMER0_COMPA_vect)
{
	BARRIOD_PORT = ~(1<<i);
	switch (i)
	{
		case 0:
		DISPLAY = numeros[millares];
		break;
		case 1:
		DISPLAY = numeros[centenas];
		break;
		case 2:
		DISPLAY = numeros[decenas];
		break;
		case 3:
		DISPLAY = numeros[unidades];
		break;
	}
	if (i >= 3)
	{
		i = 0;
	}
	else 
	{
		i++;
	}
}

