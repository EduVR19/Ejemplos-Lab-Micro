#include "debounce.h"

//flancoSubida : detecta las transisciones positivas de los botones
uint8_t debounce(uint8_t btn)
{
	uint8_t valor_nuevo = bit_is_clear(PIND, btn);
	uint8_t result = ( !(valor_nuevo) && btn );
	btn = valor_nuevo;

	_delay_ms(25);
	return result;
}