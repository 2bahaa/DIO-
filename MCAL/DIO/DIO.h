/*
 * DIO.h
 *
 * Created: 5/5/2024 11:44:10 PM
 *  Author: bahram and bahaa
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../ATMEGA328_REG.h"
#include "../../LIB/BIT_MATH.h"

#define OUTPUT	1           // Text replacement for Output as 1
#define INPUT	0           // Text replacement for Input as 0

void PIN_MODE(uint8 pin , uint8 mode);    //Function to define PIN Mode (input or output)

#endif /* DIO_H_ */