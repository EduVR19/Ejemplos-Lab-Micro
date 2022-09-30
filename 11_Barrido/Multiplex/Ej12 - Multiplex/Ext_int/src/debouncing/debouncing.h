/*
 * debouncing.h
 *
 * Created: 26/04/2022 03:35:27 p. m.
 *  Author: jdgar
 */ 


#ifndef DEBOUNCING_H_
#define DEBOUNCING_H_

#include <avr/io.h>

//Puerto
#define SWITCH_PIN PIND

uint8_t debounce_switch(uint8_t pin);


#endif /* DEBOUNCING_H_ */