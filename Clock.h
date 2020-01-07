

/* 
 * File:        Clock.h
 * Author:      Momen Ali
 * Comments:    Time counting , Mode activation , setup the timer
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __CLOCK_H
#define	__CLOCK_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include"HW.h"
/*
 * Create new struct type to hold the time format HH:MM:SS
 */
typedef struct 
{
    u8_t hours;
    u8_t minuts;
    u8_t seconds;
    u8_t mSeconds;
}Time_t;

/*
 * Modes of operation in the clock
 */
typedef enum
{
    CL_NORMAL,
    CL_SET_HOURS,
    CL_SET_MINUTES        
}Mode_t;


/* 
 * initialize the time 
 * initialize the mode
 * start the timer  
 */
void CLOCK_Init(void);
/*
 * Return the current mode
 */
Mode_t CLOCK_GetMode(void);
/*
 *  current time 
 */
void CLOCK_GetTime(Time_t * t);
/*
 * increment the time with the tick period
 */
void CLOCK_Increment(void);
/*
 * periodic function called every tick period to update 
 * the statues of the clock 
 */
void CLOCK_Update(void);

/*
 * send pointer to min or hours and check if plus or minus was pressed
 */
void set_mode_process(u8_t * var);


#endif	/* XC_HEADER_TEMPLATE_H */

