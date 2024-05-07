#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
// constants declaration
volatile uint8_t count = 0;    //Counter to indicate the 7-segment count
const uint8_t segment_lookup[] = {
	
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


int main(void){
	//FIRST CONFIGURATION
	DDRD &=~(1<<2);                //PD2 as input
	PORTD |= (1<<2);              //Pull-up Resistor
	EICRA |=(1<<ISC00);           //Any logical change
	EIMSK |=(1<<INT0);           //INT0 Enabled
	sei();                       //Global interrupt enabled
	DDRC=0XFF;                   //PORTC as output
	
	//SECOND CONFIGURATION
	DDRD &=~(1<<3);              //PD3 as input
	PORTD |=(1<<3);              //Pull-up Resistor
	EICRA|=(1<<ISC10);           //Any logical change
	EIMSK|=(1<<INT1);            //INT1 enabled
	sei();                       //Global interrupt enabled
	DDRB=0XFF;                   //PORTB as output
	//Continuous Code
	while(1){
		PORTC=0X00;
		PORTB = segment_lookup[count % 10];
	}
}

//INT0 Execution
ISR(INT0_vect)
{
	for (int i=0;i<8;i++)
	{
		PORTC=0X00;           //rotate a single ON LED across output port
		PORTC|=(1<<i);
		_delay_ms(500);
	}
}

//INT1 Execution
ISR(INT1_vect)
{
	count++;    //Incrementing the 7 Segment Code
}