

/* 
 * File:        Timer.h
 * Author:      Momen Ali
 * Comments:    OS module use timer ISR to make time driven application 
 * Revision history: 8/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __TIMER_H
#define __TIMER_H

#include <xc.h>

#include "HW.h" // include processor files - each processor file is guarded.  


/*TIMER INTERUPT FLAG OPERATIONS*/
#define TMR_GET_FLAG			(TMR_I_FLAG)
#define TMR_CLEAR_FLAG			(TMR_I_FLAG = 0)

/* 
 * Time calculation
 * timer0 is 8bit => max count is 256
 * CLKO input in the timer0 is (FOSC/4)
 * XTEL_FREQ = 8000000     => CLKO = 2000000 
 * we are using pre scaler so CLK =  ( CLKO / PRE SCALER )
 * PRE SCALER = 256  => CLK = 7812.5
 * TICK TIME = 1 / CLK   => TICK TIME = 128 us
 * OVERFLOW TIME = TICK TIME * 256  => 128 us * 256 = 32.768 ms
 * TICK TIME = 128 us
 * we need 8 ticks to have 1 ms
 * we can subtract 8 from 256 to every 1 ms
 * TMR0 = 256 - ((TIME) * 8)
 * max ms = 32
 */
#define TMR_LOAD_REGISTER(TIME)		(TMR_REG = 256 - ((TIME) * 8))


#define OS_TICK (1)


void TMR_Init(void);
void TMR_Start(void);
void TMR_Stop(void);
u8_t TMR_CheckOverflow(void);

#endif	/* XC_HEADER_TEMPLATE_H */

