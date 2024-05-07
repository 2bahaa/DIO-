/*
 * Project with drivers.c
 *
 * Created: 5/5/2024 11:39:22 PM
 * Author : bahaa and bahram
 */ 
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "..\MCAL\DIO\DIO.h"
#include "..\LIB\BIT_MATH.h"
#include "..\LIB\STD_TYPES.h"




volatile uint8 count = 0;    //Counter to indicate the 7-segment count
int main(void)
{
	// ARRAY for the 7 segment display 
	const uint8 segment_lookup[] = {
		
		0b00111111, // 0
		0b00000110, // 1
		0b01011011, // 2
		0b01001111, // 3
		0b01100110, // 4           //Sequence equivalent to 7 segments pins
		0b01101101, // 5
		0b01111101, // 6
		0b00000111, // 7
		0b01111111, // 8
		0b01101111  // 9
	};
	
	
	

	//First configuration
	
	PIN_MODE(PD2,INPUT);           //PUT PD2 AS INPUT
	SET_BIT(PORTD_REG,PORTD2);     //pull up resistor
	SET_BIT(EICRA_REG,ISC00);      //trigger to any change
	SET_BIT(EIMSK_REG,INT0);       // Enable interrupt
	sei();                         // Enable global interrupt


	//second configuration
	
	PIN_MODE(PD3,INPUT);           //PUT PD2 AS INPUT
	SET_BIT(PORTD_REG,PORTD3);     //pull up resistor
	SET_BIT(EICRA_REG,ISC10);      //trigger to any change
	SET_BIT(EIMSK_REG,INT1);       // Enable interrupt
	sei();                         // Enable global interrupt
	
	
	

	//set ports b and c to be output
	PIN_MODE(PB0,OUTPUT);
	PIN_MODE(PB1,OUTPUT);
	PIN_MODE(PB2,OUTPUT);
	PIN_MODE(PB3,OUTPUT);
	PIN_MODE(PB4,OUTPUT);
	PIN_MODE(PB5,OUTPUT);
	PIN_MODE(PB6,OUTPUT);
	PIN_MODE(PB7,OUTPUT);

	PIN_MODE(PC0,OUTPUT);
	PIN_MODE(PC1,OUTPUT);
	PIN_MODE(PC2,OUTPUT);
	PIN_MODE(PC3,OUTPUT);
	PIN_MODE(PC4,OUTPUT);
	PIN_MODE(PC5,OUTPUT);
	PIN_MODE(PC6,OUTPUT);
	
	
	//Continuous Code
	while(1){
		PORTC_REG=0X00;
		PORTB_REG = segment_lookup[count % 10];
	}

}

//INTERRUPT FOR 1ST PUSH BUTTON (LEDS)
ISR(INT0_vect)
{
	for (int i=0;i<8;i++)
	{
		PORTC_REG=0X00;           //rotate a single ON LED across output port
		SET_BIT(PORTC_REG,i);
		_delay_ms(500);
	}
	
}

//INTERRUPT FOR 2ND PUSH BUTTON (7-SEGMENT)
ISR(INT1_vect)
{
	count++;    //Incrementing the 7 Segment Code
}
