/*
 * DIO.c
 *
 * Created: 5/5/2024 11:43:53 PM
 *  Author: bahaa and bahram
 */ 
#include "DIO.h"


void PIN_MODE(uint8 pin , uint8 mode)         // function to state PIN as OUTPUT OR INPUT 
{
	uint8 port = pin/10; 
	switch(port)
	{
		/** PORT B **/
		case PORTB: 
		pin = pin%10;	// Calculate the pin number within PORTB (0-7), The result of pin % 10 will be a value between 0 and 9
		switch(mode)
		{
			case OUTPUT:	
			SET_BIT(DDRB_REG,pin);	// Set pin direction to OUTPUT
			break;
			case INPUT:
			CLR_BIT(DDRB_REG,pin);	// Set pin direction to INPUT 
			break;	
		}
		break;
		/** PORT C **/
		case PORTC:
		pin = pin%10;	// Calculate the pin number within PORTC (0-7)
		switch(mode)
		{
			case OUTPUT:
			SET_BIT(DDRC_REG,pin);	// Set pin direction to OUTPUT
			break;
			case INPUT:
			CLR_BIT(DDRC_REG,pin);	// Set pin direction to INPUT
			break;
		}
		break;
		/** PORT D **/
		case PORTD:
		pin = pin%10;	// Calculate the pin number within PORTD (0-7)
		switch(mode)
		{
			case OUTPUT:
			SET_BIT(DDRD_REG,pin);	// Set pin direction to OUTPUT
			break;
			case INPUT:
			CLR_BIT(DDRD_REG,pin);	// Set pin direction to INPUT
			break;
		}
		break;
	}
}
