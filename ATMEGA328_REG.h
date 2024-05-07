/*
 * ATMEGA328_REG.h
 *
 * Created: 5/5/2024 11:46:02 PM
 *  Author: bahram and bahaa
 */ 


#ifndef ATMEGA328_REG_H_
#define ATMEGA328_REG_H_
#include "../LIB/STD_TYPES.h"

#define PINB_REG	(*(volatile uint8*)0x23)	
#define DDRB_REG	(*(volatile uint8*)0x24)	
#define PORTB_REG	(*(volatile uint8*)0x25)	

#define PINC_REG	(*(volatile uint8*)0x26)                        //PINx_REG for inputs
#define DDRC_REG	(*(volatile uint8*)0x27)	                    //DDRx_REG for direction of port
#define PORTC_REG	(*(volatile uint8*)0x28)	                    //PORTx_REG for output

#define PIND_REG	(*(volatile uint8*)0x29)	
#define DDRD_REG	(*(volatile uint8*)0x2A)	
#define PORTD_REG	(*(volatile uint8*)0x2B)	
#define EICRA_REG   (*(volatile uint8*)0x69)
#define EIMSK_REG   (*(volatile uint8*)0x3D)

//PIN MACROS
// port B
#define	PB0		10
#define PB1		11
#define	PB2		12
#define PB3		13	
#define	PB4		14
#define PB5		15
#define	PB6		16
#define PB7		17
// port C
#define	PC0		20
#define PC1		21
#define	PC2		22
#define PC3		23
#define	PC4		24
#define PC5		25
#define	PC6		26
#define PC7		27
// port D
#define	PD0		30
#define PD1		31
#define	PD2		32
#define PD3		33
#define	PD4		34
#define PD5		35
#define	PD6		36
#define PD7		37

	//PORT MACROS

#define PORTB	1
#define PORTC	2
#define PORTD	3


//define port pin for triggers
#define ISC00 0         
#define ISC01 1
#define ISC10 2
#define ISC11 3

//Define External Hardware Interrupt
#define INT0 0
#define INT1 1

// define pins in PORTD
#define PORTD2 2
#define PORTD3 3


#endif /* ATMEGA328_REG_H_ */