/*
 * GPIO.h
 *
 * Created: 28/04/2022 04:08:45 p. m.
 *  Author: jdgar
 */ 


#ifndef GPIO_H_
#define GPIO_H_

//--Declaracion de funciones
void init_ports(void);

//--Display
#define DISPLAY PORTD

//--Barrido
#define BARRIOD_PORT PORTB
//Miles
#define BARRIDO_M PORTB0
#define BARRIDO_M_OFF  BARRIOD_PORT |=  _BV(BARRIDO_M)
#define BARRIDO_M_ON BARRIOD_PORT &= ~_BV(BARRIDO_M)

//Centenas
#define BARRIDO_C PORTB1
#define BARRIDO_C_OFF  BARRIOD_PORT |=  _BV(BARRIDO_C)
#define BARRIDO_C_ON BARRIOD_PORT &= ~_BV(BARRIDO_C)

//Decenas
#define BARRIDO_D PORTB2
#define BARRIDO_D_OFF  BARRIOD_PORT |=  _BV(BARRIDO_D)
#define BARRIDO_D_ON BARRIOD_PORT &= ~_BV(BARRIDO_D)

//Unidades
#define BARRIDO_U PORTB3
#define BARRIDO_U_OFF  BARRIOD_PORT |=  _BV(BARRIDO_U)
#define BARRIDO_U_ON BARRIOD_PORT &= ~_BV(BARRIDO_U)


//LED4
#define LED4 PORTB4
#define LED4_ON  PORTB |=  _BV(LED4)
#define LED4_OFF PORTB &= ~_BV(LED4)


//--Entradas




#endif /* GPIO_H_ */