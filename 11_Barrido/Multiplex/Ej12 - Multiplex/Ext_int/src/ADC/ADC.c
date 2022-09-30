/*
 * ADC.c
 *
 * Created: 10/05/2022 04:08:56 p. m.
 *  Author: jdgar
 */ 

#include "ADS.h"

void ADC_init(void)
{
	//ADMUX = 0b01100101;
	
	//Avcc como pin de referencia
	ADMUX &=~ (1<<REFS1);
	ADMUX &=~ (1<<REFS0);
	
	//Ajustar a 8 bits
	ADMUX |= (1<<ADLAR);
	
	// Escoger el PIN a leer ADC1
	ADMUX &=~ (1<<MUX3);
	ADMUX &=~ (1<<MUX2);
	ADMUX &=~ (1<<MUX1);
	ADMUX |=  (1<<MUX0);
	
	//Freeruning
	ADCSRA |= (1<<ADATE);
	
	//Enable interrupt
	ADCSRA |= (1<<ADIE);
	
	//velocidad de muestreo
	// 1 MHz clock / 8 = 125 kHz ADC clock debe de estar entre 50 - 200Khz
	ADCSRA &=~ (1<<ADPS0);
	ADCSRA |= (1<<ADPS1);
	ADCSRA |= (1<<ADPS2);
}
void ADC_on(void)
{
	//Encendemos el ADC
	ADCSRA |= (1<<ADEN);
	// Iniciar la conversión
	ADCSRA |= (1 << ADSC);
}
