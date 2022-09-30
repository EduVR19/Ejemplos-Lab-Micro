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

/*******************Bibliotecas****************************/
#include <avr/io.h>
// Velocidad del micro
#define F_CPU 1000000UL
#include <util/delay.h>

/*****************Macros y constantes**********************/
#define BTN   PIND

#define BTN_ROW1 PIND0
#define BTN_ROW2 PIND1
#define BTN_ROW3 PIND2
#define BTN_ROW4 PIND3

#define BTN_COL1 PIND4
#define BTN_COL2 PIND5
#define BTN_COL3 PIND6
#define BTN_COL4 PIND7

#define DISPLAY PORTB
#define TIME 500

#define read_row1 = bit_is_clear(BTN, BTN_ROW1);
#define read_row2 = bit_is_clear(BTN, BTN_ROW2);
#define read_row3 = bit_is_clear(BTN, BTN_ROW3);
#define read_row4 = bit_is_clear(BTN, BTN_ROW4);

#define read_col1 = bit_is_clear(BTN, BTN_COL1);
#define read_col2 = bit_is_clear(BTN, BTN_COL2);
#define read_col3 = bit_is_clear(BTN, BTN_COL3);
#define read_col4 = bit_is_clear(BTN, BTN_COL4);

#define A1 read_row1 == 0 && read_col1 == 0
#define A2 read_row1 == 1 && read_col2 == 1
#define A3 read_row1 == 1 && read_col3 == 1
#define A4 read_row1 == 1 && read_col4 == 1

#define B1 read_row2 == 1 && read_col1 == 1
#define B2 read_row2 == 1 && read_col2 == 1
#define B3 read_row2 == 1 && read_col3 == 1
#define B4 read_row2 == 1 && read_col4 == 1

#define C1 read_row3 == 1 && read_col1 == 1
#define C2 read_row3 == 1 && read_col2 == 1
#define C3 read_row3 == 1 && read_col3 == 1
#define C4 read_row3 == 1 && read_col4 == 1

#define D1 read_row4 == 1 && read_col1 == 1
#define D2 read_row4 == 1 && read_col2 == 1
#define D3 read_row4 == 1 && read_col3 == 1
#define D4 read_row4 == 1 && read_col4 == 1


/*******************Variables globales*********************/
// Máquina de Estados Finita
//enum estados
//{
	//estado_1,
	//estado_2,
	//estado_3,
	//estado_4,
	//estado_5,
	//estado_6,
	//estado_7,
	//estado_8,
	//estado_1,
	//estado_2,
	//estado_3,
	//estado_4,
	//estado_5,
	//estado_6,
	//estado_7,
	//estado_8,
	//
//} estado;
// Arreglo con los números del contador
//uint8_t numeros[10] =
//{
	//// abcdefg
	//0b1111110, // 0
	//0b0110000, // 1
	//0b1101101, // 2
	//0b1111001, // 3
	//0b0110011, // 4
	//0b1011011, // 5
	//0b1011111, // 6
	//0b1110000, // 7
	//0b1111111, // 8
	//0b1110011  // 9
//};
// Variable para mostrar un número específico en el arreglo
//uint8_t i = 0;

/***********************Funciones**************************/
void init_ports(void);
void lectura(void);




/*******************Programa principal*********************/
int main(void)
{
	
	init_ports();
    while (1) 
    {
		//if (A1)
		//{
			PORTB = 0xFF;
		//}
    }
}


voied init_ports(void)
{
	estado = estado_0; // Inicializar estado en estado 0
	
	// Entradas
	DDdddRD = 0x00; // Declarar entradass
	
	// Salidas
	DDRB    = 0xFF; // Declarar salidas
	DISPLAY = 0x00; // Colocar en LOW las salidas
	
}
//void lectura(void)
//{
	//// leer si el botón 0 está vacío (0), como está en HIGH devolverá un 0
	//uint8_t read_0 = bit_is_clear(BTN, BTN_0);
	//_delay_ms(20);
	//// leer si el botón 1 está vacío (0), como está en HIGH devolverá un 0
	//uint8_t read_1 = bit_is_clear(BTN, BTN_1);
	//_delay_ms(20);
	//
	//// condiciones de 4 combinaciones para activar cada estado
	//if ( read_0 == 0 && read_1 == 0 ) estado = estado_0;
		//else if ( read_0 == 1 && read_1 == 0 ) estado = estado_1;
			//else if ( read_0 == 0 && read_1 == 1 ) estado = estado_2;
				//else if ( read_0 == 1 && read_1 == 1 ) estado = estado_3;
//
//}
//void ascendente(void)
//{
	//while (estado == estado_0)
	//{		
		//DISPLAY = numeros[i];
		//_delay_ms(TIME);
//
		//// Lectura para comprobar cambio de estado, si se cambia sale del loop
		//lectura();
		//if (estado == estado_1 || estado == estado_2 || estado == estado_3)
		//{
			//break;
		//}
		//
		//// Candado para reiniciar el contador
		//if (i == 9)
		//{
			//i = -1;
		//}
		//// Aumentar el contador en 1
		//i++;
//
	//}
//}
//void descendente(void)
//{
	//while (estado == estado_1)
	//{		
		//DISPLAY = numeros[i];
		//_delay_ms(TIME);
//
		//// Lectura para comprobar cambio de estado, si se cambia sale del loop
		//lectura();
		//if (estado == estado_0 || estado == estado_2 || estado == estado_3)
		//{
			//break;
		//}
		//// Candado para reiniciar el contador
		//if (i == 0)
		//{
			//i = 10;
		//}
		//
		//// Aumentar el contador en 1
		//i--;
	//}
//}
//
//void velocidad(void)
//{
	//while (estado == estado_2)
	//{
		//DISPLAY = numeros[i];
		//_delay_ms(300);
//
		//// Lectura para comprobar cambio de estado, si se cambia sale del loop
		//lectura();
		//if (estado == estado_0 || estado == estado_1 || estado == estado_3)
		//{
			//break;
		//}
		//
		//// Candado para reiniciar el contador
		//if (i == 9)
		//{
			//i = -1;
		//}
		//// Aumentar el contador en 1
		//i++;
//
	//}
//}
//
//void stop(void)
//{
	//while (estado == estado_3)
	//{
		//DISPLAY = numeros[i];
		//_delay_ms(TIME);
//
		//// Lectura para comprobar cambio de estado, si se cambia sale del loop
		//lectura();
		//if (estado == estado_0 || estado == estado_1 || estado == estado_2)
		//{
			//break;
		//}
	//}
	//
//}


