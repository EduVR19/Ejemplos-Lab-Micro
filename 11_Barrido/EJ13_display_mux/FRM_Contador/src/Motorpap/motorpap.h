/*
 * motorpap.h
 *
 * Created: 08/04/2022 10:02:01 a. m.
 *  Author: jdgar
 */ 


#ifndef MOTORPAP_H_
#define MOTORPAP_H_
//Constantes
#define DELAY_PAP 500
#define DELAY1S 1000

//--MOTOR a Pasos
#define MOTOR_REGISTER  DDRB
#define MOTOR_PORT      PORTB

//BOBINA1
#define BOBINA1_MOTOR PORTB2
#define BOBINA1_MOTOR_ON  MOTOR_PORT |=  _BV(BOBINA1_MOTOR)
#define BOBINA1_MOTOR_OFF MOTOR_PORT &= ~_BV(BOBINA1_MOTOR)
//BOBINA2
#define BOBINA2_MOTOR PORTB3
#define BOBINA2_MOTOR_ON  MOTOR_PORT |=  _BV(BOBINA2_MOTOR)
#define BOBINA2_MOTOR_OFF MOTOR_PORT &= ~_BV(BOBINA2_MOTOR)
//BOBINA3
#define BOBINA3_MOTOR PORTB4
#define BOBINA3_MOTOR_ON  MOTOR_PORT |=  _BV(BOBINA3_MOTOR)
#define BOBINA3_MOTOR_OFF MOTOR_PORT &= ~_BV(BOBINA3_MOTOR)
//BOBINA4
#define BOBINA4_MOTOR PORTB5
#define BOBINA4_MOTOR_ON  MOTOR_PORT |=  _BV(BOBINA4_MOTOR)
#define BOBINA4_MOTOR_OFF MOTOR_PORT &= ~_BV(BOBINA4_MOTOR)

void init_motorpap(void);
void motor_posicion_0(void);
void motor_posicion_90(void);
void motor_posicion_180(void);
void motor_posicion_270(void);

#endif /* MOTORPAP_H_ */