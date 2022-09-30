#include <avr/io.h>
#define F_CPU 1000000UL //1 Mhz
#include <util/delay.h>



#define LED_0 PORTD0
#define LED_1 PORTD1
#define LED_2 PORTD2
#define LED_3 PORTD3
#define LED_4 PORTD4
#define TIME 500



void init_ports(void);



int main(void)
{
	init_ports();

	while (1)
	{
		PORTD = 0b00000001;
		_delay_ms(TIME);
		PORTD = 0b00000010;
		_delay_ms(TIME);
		PORTD = 0b00000100;
		_delay_ms(TIME);
		PORTD = 0b0001000;
		_delay_ms(TIME);
		PORTD = 0b0010000;
		_delay_ms(TIME);
		PORTD = 0b0001000;
		_delay_ms(TIME);
		PORTD = 0b0000100;
		_delay_ms(TIME);
		PORTD = 0b0000010;
		_delay_ms(TIME);
	}
}



void init_ports(void){
	DDRD = (1<<LED_0) | (1<<LED_1) | (1<<LED_2) | (1<<LED_3) | (1<<LED_4);



}