

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
#define TMR_GET_FLAG			(TIMER_I_FLAG)
#define TMR_CLEAR_FLAG			(TIMER_I_FLAG = 0)

void TMR_Init(void);
void TMR_Update(void);
void TMR_Start(void);
void TMR_Stop(void);
u8_t TMR_CheckOverflow(void);

#endif	/* XC_HEADER_TEMPLATE_H */

