/*
 * BIT_MATH.h
 *
 * Created: 5/5/2024 11:43:22 PM
 *  Author: bahaa and bahram
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define	 SET_BIT(reg,bit)	reg|=(1<<bit)               //Text replacement to SET a special bit in a specific register
#define	 CLR_BIT(reg,bit)	reg&=(~(1<<bit))            //Text replacement to Clear a special bit in a specific register

#endif /* BIT_MATH_H_ */