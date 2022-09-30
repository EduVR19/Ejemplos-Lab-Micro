#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

#define BTN_INT0 PIND2
#define BTN_INT1 PIND3

void init_ports();
void init_int();
void pwm_init();

const uint8_t TIEMPO = 20;

int main(void)
{

    cli();
    init_ports();
	pwm_init();
    init_int();
	DDRB |= (1<<DDB1);
    sei();
	

    while (1) 
    {
		DDRB |= (1<<DDB1);
		_delay_ms(TIEMPO);
    }
}

// Inicializar puertos
void init_ports()
{
	// Entradas
	DDRD  &= ~( _BV(BTN_INT0) | _BV(BTN_INT1) ); // Entrada - 0
	PORTD |=  ( _BV(BTN_INT0) | _BV(BTN_INT1) ); // Pull up - HIGH No es necesario por el debounce en hardware
		
}


void pwm_init()
{
	//Non-inverting mode
	TCCR1A |=  _BV(COM1A1);
	TCCR1A &=~ _BV(COM1A0);
	
	//FastPWM mode 10 bit
	//--Modo no invertido canal A PIN B1
	TCCR1A |=   (1<<WGM11) | (1<<WGM10);
	TCCR1B |=   (1<<WGM12);
	TCCR1B &=  ~_BV(WGM13);
	//Prescaler
	//--No prescaler clock interno
	TCCR1B  &=~ _BV(CS12);
	TCCR1B  &=~ _BV(CS11);
	TCCR1B  |=  _BV(CS10);
	
	//Duty cycle
	OCR1A = 0; //50% 512 = 2.5V -> 100% 1024 = 5V
}



// Inicializar interrupciones
void init_int()
{
	
	// Control INT0 - Low Mode
	EICRA &= ~( _BV(ISC01) );
	EICRA &= ~( _BV(ISC00) );
	// EICRA - External Interrupt Control Register A
	// ISC	 - Interrupt Sense Control - Control de Detecci?n de Interrupciones
	// Inicializar INT0
	EIMSK |=  ( _BV(INT0) ); // Habilitar interrupci?n
	// EIMSK - External Interrupt Mask
	
	// Control INT1 - Low Mode
	EICRA &= ~( _BV(ISC11) );
	EICRA &= ~( _BV(ISC10) );
	// EICRA - External Interrupt Control Register A
	// ISC	 - Interrupt Sense Control - Control de Detecci?n de Interrupciones
	// Inicializar INT1
	EIMSK |=  ( _BV(INT1) ); // Habilitar interrupci?n
	// EIMSK - External Interrupt Mask

}

ISR(INT0_vect)
{
	if (OCR1A < 1020)
	{
		OCR1A = OCR1A + 102;	
	}
}
// ISR	- Interruption Service Routine - Maneja el desbordamiento
// INTO_vect - External Interrupt Request 0

ISR(INT1_vect)
{
	flag = 2; // Toggle 1 y 0, cada vez que se presiona cambia el valor entre 1 y 0
	if (OCR1A > 0)
	{
		OCR1A = OCR1A - 102;	
	}

}
// ISR	- Interruption Service Routine - Maneja el desbordamiento
// INTO_vect - External Interrupt Request 0