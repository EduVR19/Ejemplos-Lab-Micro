/*
 * debounce.h
 *
 * Created: 08/04/2022 09:20:36 a. m.
 *  Author: jdgar
 */ 



#ifndef DEBOUNCE_H_
#define DEBOUNCE_H_

#include <avr/io.h>

//--Declaraciones
//Constantes
#define SWITCH_PIN PINC

//Funciones
uint8_t debounce_switch(uint8_t pin);

#endif /* DEBOUNCE_H_ */