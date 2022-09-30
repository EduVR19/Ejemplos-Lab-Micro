#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL //1 Mhz
#include <util/delay.h>
void initialize_ports(void);
void ADC_init(void);
void ADC_on(void);

#define DISPLAY PORTD


// Arreglo con los números del contador
uint8_t numeros[10] =
{
	// abcdefg
	0b1111110, // 0
	0b0110000, // 1
	0b1101101, // 2
	0b1111001, // 3
	0b0110011, // 4
	0b1011011, // 5
	0b1011111, // 6
	0b1110000, // 7
	0b1111111, // 8
	0b1110011  // 9
};



int main(void)
{
	cli();
	initialize_ports();
	ADC_init();
	sei();
	ADC_on();
	while (1)
	{
		
	}
}
void initialize_ports(void)
{
	//Outputs
	DDRD  = 0xFF;
	PORTD = 0x00;
}
void ADC_init(void)
{
	//--Referencia +5V
	//ADMUX &=~ _BV(REFS1);
	//ADMUX |=  _BV(REFS0);
	//--Referencia externa
	ADMUX &=~ _BV(REFS1);
	ADMUX &=~ _BV(REFS0);
	//Lecutura de 8 bits
	ADMUX |=  _BV(ADLAR);
	
	// Escoger el PIN a leer ADC4
	ADMUX &=~ (1<<MUX3);
	ADMUX |=  (1<<MUX2);
	ADMUX &=~ (1<<MUX1);
	ADMUX &=~ (1<<MUX0);
	//Freeruning
	ADCSRA |= (1<<ADATE);
	
	//Enable Interrupt
	ADCSRA |= (1<<ADIE);
	//velocidad de muestreo
	// 1 MHz clock / 8 = 125 kHz ADC clock debe de estar entre 50 - 200Khz
	ADCSRA &=~ (1<<ADPS2);
	ADCSRA |=  (1<<ADPS1);
	ADCSRA |=  (1<<ADPS0);
	
}
void ADC_on(void)
{
	//Enable ADC
	ADCSRA |=  (1<<ADEN);
	
	//Iniciar
	_delay_ms(10); //Precalentamiento
	ADCSRA |=  (1<<ADSC);
}
//Interrupt
ISR(ADC_vect)
{
	if (ADCH >= 0 && ADCH <= 63) //Rango inferior
	{
		DISPLAY = numeros[0];
	}
	else if (ADCH >= 64 && ADCH <= 127)//Rango medio
	{
		DISPLAY = numeros[1];
	}
	else if (ADCH >= 128 && ADCH <= 255)//Rango superior
	{
		DISPLAY = numeros[2];
	}
}