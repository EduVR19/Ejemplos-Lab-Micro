#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL //1 Mhz
#include <util/delay.h>
void initialize_ports(void);
void ADC_init(void);
void ADC_on(void);
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
	ADMUX &=~ _BV(REFS1);
	ADMUX |=  _BV(REFS0);
	//--Referencia externa
	//ADMUX &=~ _BV(REFS1);
	//ADMUX &=~ _BV(REFS0);
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
	if (ADCH >= 0 && ADCH <= 127) //Rango inferior
	{
		PORTD = 0x0F;
	}
	if (ADCH >= 128 && ADCH <= 255)//Rango superior
	{
		PORTD = 0xF0;
	}
	//PORTD = ADCH; //0 a 5V -> 0 a 255bits
}