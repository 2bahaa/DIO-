/*
 * AVR_INTERRUPT.h
 *
 * Created: 5/6/2024 3:51:39 PM
 *  Author: Mohamed Bahaa and bahram
 */ 


#ifndef AVR_INTERRUPT_H_
#define AVR_INTERRUPT_H_
#include <avr/io.h>

#if defined(__DOXYGEN__)
/** \def sei()

    Enables interrupts by setting the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead.

*/
#define sei()
#else  /* !DOXYGEN */
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#endif /* DOXYGEN */




#if defined(__DOXYGEN__)
/** \def ISR(vector [, attributes])

    Introduces an interrupt handler function (interrupt service
    routine) that runs with global interrupts initially disabled
    by default with no attributes specified.

*/
#  define ISR(vector, [attributes])
#else  /* real code */

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || (__GNUC__ > 4)
#  define __INTR_ATTRS used, externally_visible
#else /* GCC < 4.1 */
#  define __INTR_ATTRS used
#endif

#ifdef __cplusplus
#  define ISR(vector, ...)            \
    extern "C" void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#else
#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#endif

#endif /* DOXYGEN */




#endif /* AVR_INTERRUPT_H_ */