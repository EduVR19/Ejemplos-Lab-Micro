/*
 * motorpap.c
 *
 * Created: 08/04/2022 10:01:52 a. m.
 *  Author: jdgar
 */ 


#include <avr/io.h>
#include "motorpap.h"

void init_motorpap(void)
{
	MOTOR_REGISTER|=   _BV(BOBINA1_MOTOR)|_BV(BOBINA2_MOTOR)|_BV(BOBINA3_MOTOR)|_BV(BOBINA4_MOTOR);
	MOTOR_PORT    &=~ (_BV(BOBINA1_MOTOR)|_BV(BOBINA2_MOTOR)|_BV(BOBINA3_MOTOR)|_BV(BOBINA4_MOTOR));
}

void motor_posicion_0(void)
{
	BOBINA1_MOTOR_ON;
	BOBINA2_MOTOR_ON;
	BOBINA3_MOTOR_OFF;
	BOBINA4_MOTOR_OFF;
}
void motor_posicion_90(void)
{
	BOBINA1_MOTOR_OFF;
	BOBINA2_MOTOR_ON;
	BOBINA3_MOTOR_ON;
	BOBINA4_MOTOR_OFF;
}
void motor_posicion_180(void)
{
	BOBINA1_MOTOR_OFF;
	BOBINA2_MOTOR_OFF;
	BOBINA3_MOTOR_ON;
	BOBINA4_MOTOR_ON;
}
void motor_posicion_270(void)
{
	BOBINA1_MOTOR_ON;
	BOBINA2_MOTOR_OFF;
	BOBINA3_MOTOR_OFF;
	BOBINA4_MOTOR_ON;
}
