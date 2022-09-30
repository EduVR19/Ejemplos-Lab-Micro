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
#define F_CPU 1000000UL
#include <util/delay.h>

//Etiquetas
//--Constantes
#define RETARDO 500 
//--Outputs
#define BOBINA1 PORTC0
#define BOBINA1_ON PORTC  |=  _BV(BOBINA1)
#define BOBINA1_OFF PORTC &= ~_BV(BOBINA1)

#define BOBINA2 PORTC1
#define BOBINA2_ON PORTC  |=  _BV(BOBINA2)
#define BOBINA2_OFF PORTC &= ~_BV(BOBINA2)

#define BOBINA3 PORTC2
#define BOBINA3_ON PORTC  |=  _BV(BOBINA3)
#define BOBINA3_OFF PORTC &= ~_BV(BOBINA3)

#define BOBINA4 PORTC3
#define BOBINA4_ON PORTC  |=  _BV(BOBINA4)
#define BOBINA4_OFF PORTC &= ~_BV(BOBINA4)

//--Entradas
//--INPUT0
#define INPUT0 PINB0
#define INPUT0_PRESS bit_is_set(PINB,INPUT0)
//--INPUT1
#define INPUT1 PINB1
#define INPUT1_PRESS bit_is_set(PINB,INPUT1)

//--DISPLAY
#define DISPLAY PORTD
uint8_t numeros [7] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE}; //Global

//Estados     0  1  2  3 
enum states {e0,e1,e2,e3} state;

//Declarar funcion
uint8_t estadoAnterior;
uint8_t estadoActual;
uint8_t debounce(uint8_t port, uint8_t pin);
void init_ports(void);
void motor_0G(void);
void motor_45G(void);
void motor_90G(void);
void motor_135G(void);
void motor_180G(void);
void motor_225G(void);
void motor_270G(void);
void motor_315G(void);

uint8_t i = 0;

int main(void)
{
    init_ports();
	state = e0;
	DISPLAY = numeros[0];
    while (1) 
    {
		DISPLAY = numeros[i];
		if (debounce(1,INPUT0))
		{
			_delay_ms(200);
			if (i >= 6)
			{
				i = 1;
			}
			else
			{
				i++;
			}
		}
    } // Fin while
} // Fin main
void init_ports(void)
{
    //Salidas
	DDRC  |= _BV(BOBINA1) | _BV(BOBINA2)| _BV(BOBINA3) | _BV(BOBINA4);
	PORTC &= ~(_BV(BOBINA1) | _BV(BOBINA2)| _BV(BOBINA3) | _BV(BOBINA4));

	//Display
	DDRD  = 0xFF;
	
	//Entradas
	DDRB &= ~_BV(INPUT0);
	DDRB &= ~_BV(INPUT1);
}
uint8_t debounce(uint8_t port, uint8_t pin)
{
	estadoAnterior = estadoActual;
	
	// Comprobar que puerto se está usando
	if ( port == 0 ) estadoActual = bit_is_clear(PIND, pin);
	else if ( port == 1 ) estadoActual = bit_is_set(PINB, pin);
	else if ( port == 2 ) estadoActual = bit_is_clear(PINC, pin);
	
	if ( estadoAnterior == 0 && estadoActual == 1) // Si se oprime el botón
	{
		return 1;
	}
	else if (estadoAnterior == 1 && estadoActual == 1) // Si se mantiene presionado
	{
		return 1;
	}
	else
	{
		return 0; // Si no se presiona y no se mantiene presionado
	}
}

void motor_45G(void)
{
	BOBINA1_ON;
	BOBINA2_OFF;
	BOBINA3_OFF;
	BOBINA4_OFF;
}
void motor_0G(void)
{
	BOBINA1_ON;
	BOBINA2_ON;
	BOBINA3_OFF;
	BOBINA4_OFF;	
}
void motor_135G(void)
{
	BOBINA1_OFF;
	BOBINA2_ON;
	BOBINA3_OFF;
	BOBINA4_OFF;
}
void motor_90G(void)
{
	BOBINA1_OFF;
	BOBINA2_ON;
	BOBINA3_ON;
	BOBINA4_OFF;
}
void motor_225G(void)
{
	BOBINA1_OFF;
	BOBINA2_OFF;
	BOBINA3_ON;
	BOBINA4_OFF;
}
void motor_180G(void)
{
	BOBINA1_OFF;
	BOBINA2_OFF;
	BOBINA3_ON;
	BOBINA4_ON;
}
void motor_315G(void)
{
	BOBINA1_OFF;
	BOBINA2_OFF;
	BOBINA3_OFF;
	BOBINA4_ON;
}
void motor_270G(void)
{
	BOBINA1_ON;
	BOBINA2_OFF;
	BOBINA3_OFF;
	BOBINA4_ON;	
}

		//switch (state)
		//{
		//case e0:
		//motor_0G();
		//DISPLAY =numeros[0];
		//_delay_ms(RETARDO);
		//if (INPUT0_PRESS)
		//{
		//state = e3;
		//}
		//else
		//{
		//state = e1;
		//}
		//break;
		//
		//case e1:
		//motor_90G();
		//DISPLAY =numeros[1];
		//_delay_ms(RETARDO);
		//if (INPUT0_PRESS)
		//{
		//state = e0;
		//}
		//else
		//{
		//state = e2;
		//}
		//break;
		//
		//case e2:
		//motor_180G();
		//DISPLAY =numeros[2];
		//_delay_ms(RETARDO);
		//if (INPUT0_PRESS)
		//{
		//state = e1;
		//}
		//else
		//{
		//state = e3;
		//}
		//break;
		//
		//case e3:
		//motor_270G();
		//DISPLAY =numeros[3];
		//_delay_ms(RETARDO);
		//if (INPUT0_PRESS)
		//{
		//state = e2;
		//}
		//else
		//{
		//state = e0;
		//}
		//break;
		//
