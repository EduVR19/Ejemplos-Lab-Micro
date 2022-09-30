/****************************************************
 * Nombre: Eduardo Vicente Reyna Villela			*
 * Hora clase: M4-M6								*
 * Día: Jueves										*
 * N° de lista:                                     *
 * N° de Equipo: No aplica					        *
 * Dispositivo: Atmega328P							*
 * Rev: 1.0                                         *
 * Propósito de la actividad:                       *
 * Sistema con 2 botones y un contador mostrado en  *
 * un display de 7 segmentos						*
 *                                Fecha: 27/07/2021 *
 ***************************************************/

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF;
    while (1) 
    {
		PORTB = 0xFF;
		_delay_ms(1000);
		PORTB = 0x00;
		_delay_ms(1000);		
	}
}
