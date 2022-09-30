// Interrupcion Interna - Timer 0 y Timer 1

#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

#define	LED			PORTB0
#define LED_TGGLE	PORTB ^= _BV(LED)

void init_ports();

void init_timer0();
void timer0_on();
void timer0_off();

void init_timer1();
void timer1_on();
void timer1_off();

uint8_t seg = 0;

int main(void)
{
	cli();
	init_ports();
	init_timer0();
	timer0_on();
	sei();
	
	while (1)
	{
	}
}

void init_ports()
{
	// Salida
	DDRB  |=  ( _BV(LED) ); // Salida
	PORTB &= ~( _BV(LED) ); // LOW - Source
	
}

void init_timer0()
{
	/******* 1 - Inicializar Modo *******/
	// CTC			- 0 1 0
	TCCR0A &= ~( _BV(WGM00) );	// 0
	TCCR0A |=  ( _BV(WGM01) );	// 1
	TCCR0B &= ~( _BV(WGM02) );	// 0
	// TCCR01 - Timer Counter Control Register A
	// TCCR01 - Timer Counter Control Register B
	// WGM##  - Waveform Generator Mode #
	OCR0A = 97; // 0.1 s // Modo CTC - Cambio del TOP
	// OCR0A - Output Compare Register 0A - Tiene un valor de 8 bits 
	// y está constantemente comparado con el TCNT0 (Timer Counter Register)
	
	/******* 2 - Habilitar interrupción *******/
	TIMSK0 |= ( _BV(OCIE0A) );
	// TIMSK0 - Timer Interrupt Mask 0A
	// OCIE0A - Output Compare Interruption Enable
	
}
void timer0_on()
{
	/******* 1 - Inicializar TCNT0 *******/
	TCNT0 = 0;
	// TCN0 - Timer Counter Register 0 - Variable contadora con la que se compara 
	// el OCR0A (Output Compare Register)
	
	/******* 2 - Habilitar Reloj *******/
	// Prescaler 1024	- 1 0 1
	TCCR0B |=  ( _BV(CS00) );	// 1
	TCCR0B &= ~( _BV(CS01) );	// 0
	TCCR0B |=  ( _BV(CS02) );	// 1
	// TCCR01 - Timer Counter Control Register 0B
	// CS0#   - Clock Select 0#
}
void timer0_off()
{
	/******* 1 - Desabilitar reloj *******/
	// Apagado			- 0 0 0
	TCCR0B &= ~( _BV(CS00) );	// 0
	TCCR0B &= ~( _BV(CS01) );	// 0
	TCCR0B &= ~( _BV(CS02) );	// 0
	// TCCR01 - Timer Counter Control Register 0B
	// CS0#   - Clock Select 0#
}


void init_timer1()
{
	/******* 1 - Inicializar Modo *******/
	// CTC			- 0 1 0 0 
	TCCR1A &= ~( _BV(WGM10) );	// 0
	TCCR1A &= ~( _BV(WGM11) );	// 0
	TCCR1B |=  ( _BV(WGM12) );	// 1
	TCCR1B &= ~( _BV(WGM13) );	// 0
	
	// TCCR1A - Timer Counter Control Register 1A
	// TCCR1B - Timer Counter Control Register 1B
	// WGM##  - Waveform Generator Mode #
	OCR1A = 7500; // 1 minuto // Modo CTC - Cambio del TOP
	// OCR0A - Output Compare Register 1A - Tiene un valor de 8 bits
	// y está constantemente comparado con el TCNT0 (Timer Counter Register)
	
	/******* 2 - Habilitar interrupción *******/
	TIMSK1 |= ( _BV(OCIE1A) );
	// TIMSK1 - Timer Interrupt Mask 1A
	// OCIE1A - Output Compare Interruption Enable 1A
	
}
void timer1_on()
{
	/******* 1 - Inicializar TCNT0 *******/
	TCNT1 = 0;
	// TCN0 - Timer Counter Register 1 - Variable contadora con la que se compara
	// el OCR0A (Output Compare Register)
	
	/******* 2 - Habilitar Reloj *******/
	// Prescaler 1024	- 1 0 1
	TCCR1B |=  ( _BV(CS10) );	// 1
	TCCR1B &= ~( _BV(CS11) );	// 0
	TCCR1B |=  ( _BV(CS12) );	// 1
	// TCCR01 - Timer Counter Control Register 1B
	// CS1#   - Clock Select 1#
}
void timer1_off()
{
	/******* 1 - Desabilitar reloj *******/
	// No clock source	- 0 0 0
	TCCR1B &= ~( _BV(CS10) );	// 0
	TCCR1B &= ~( _BV(CS11) );	// 0
	TCCR1B &= ~( _BV(CS12) );	// 0
	// TCCR01 - Timer Counter Control Register 1B
	// CS1#   - Clock Select 1#
}

ISR(TIMER0_COMPA_vect)
{
	seg++;
	if ( seg >= 10 )
	{
		LED_TGGLE;
		seg = 0;
	}
}

//ISR(TIMER1_COMPA_vect)
//{
//
	//LED_TGGLE;
//
//}


















////--Biblioteca del AVR--
//#include <avr/io.h>
////--Velocidad del CPU 1MHz--
//#define F_CPU 1000000UL //1 MHz
////Biblioteca de interrupciones externas
//#include <avr/interrupt.h>
//
//
//
////SALIDAS-----------------------------------//
//#define DISPLAY PORTD
////LED5
//#define LED5 PORTB0
//#define LED5_ON PORTB|= _BV(LED5)
//#define LED5_OFF PORTB&=~_BV(LED5)
////TOGGLE ---> EXOR ----> Cambia el valor
//#define LED5_TGLE PORTB ^= _BV(LED5)
//volatile uint8_t conteo = 0;
//
//
//
//
////Funciones*********************
////Declaracion de Funciones****************
//void initialize_ports(void); // Función para inicializar puertos
////Para dar de alta timers
//void init_timer0(void);
//void on_timer0(void);
//void off_timer0(void);
//
//
////Programa principal******************
//int main(void)
//{
	////Inicialización
	//cli();
	//initialize_ports(); // va hacía la inicialización
	//sei();
	//init_timer0();
	//on_timer0();
	////Ejecución
	//while (1)
	//{
	//} // END loop infinito
//} // END MAIN
//
//
//
//
////initialize_ports : inicializa los puertos de entrada o salida
////*************************
//void initialize_ports(void)
//{
//
	////---------------------------SALIDAS-----------------------------------//
	//DDRB |= 0x10; //Salida del LED DE ESTATUS
	//DDRD = 0xFF; //Salida en el Puerto D
//}
//
//
//
////--------INICIALIZACION-----TIMER------------//
//void init_timer0(void)
//{
	////Modo CTC
	//TCCR0B &= ~_BV(WGM02); //Ponemos un 0
	//TCCR0A |= _BV(WGM01); //Ponemos un 1
	//TCCR0A &= ~_BV(WGM00); //Ponemos un 0
//
	////TOP 0.1 segundo
	//OCR0A = 97;
//
	////ENABLE //TIMSK0 |= _BV(TOIE0); incorrecto
	//TIMSK0 |= _BV(OCIE0A);
//}
//
//
//
//void on_timer0 (void)
//{
	////Reinicia el conteo
	//TCNT0 = 0;
//
	////Preescaler 1024
	//TCCR0B |= _BV(CS02); //Ponemos un 1
	//TCCR0B &= ~_BV(CS01); //Ponemos un 0
	//TCCR0B |= _BV(CS00); //Ponemos un 1
//}
//
//
//
//void off_timer0(void)
//{
	////STOP
	//TCCR0B &= ~_BV(CS02); //Ponemos un 0
	//TCCR0B &= ~_BV(CS01); //Ponemos un 0
	//TCCR0B &= ~_BV(CS00); //Ponemos un 0
//}
//
//
//
//
//
////-----VECTOR---TIMER----------------//
//ISR (TIMER0_COMPA_vect)
//{
	////La variable conteo suma 1
	//conteo++;
	////Si cuenta 10 veces 0.1s entonces
	//if(conteo >= 10)
	//{
		////Enciende el LED5 = LED_ESTATUS
		//LED5_TGLE;
		////Reinicia el conteo
		//conteo = 0;
	//}
//}











//
//
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//volatile uint16_t counter;
//
//int main(void)
//{
	//DDRB |= (1<<PB0);
	//OCR1A = 80-1; // at 16MHz you need 160 cycles to reach 10us pulse...
	//TCCR1A = 0; // no output compare and WGM1 to 00
	//TCCR1B |= (1 << WGM12)|(1 << CS10); // set prescaler to 1 and CTC mode
	//TIMSK1 |= (1 << OCIE1A);         // set compare A interrupt
	//sei();                          // enable interrupts
//
//
	//while (1)
	//{
		//// Main loop
	//}
//}
//
//ISR (TIMER1_COMPA_vect) // check this too
//{ // what was the counter stuff for? it only made things slower...
	//
	//counter++;
	//
	//if (counter>=10)
	//{
		//PORTB ^= _BV(PB0);
		//
		//counter = 0;
	//}
//
	//// keep the ISR as quick as posible, it takes about 1us gettin' in & out
//}