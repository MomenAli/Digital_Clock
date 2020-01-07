/*
 * File:   Clock.c
 * Author: Momen Ali
 *
 * Created on January 7, 2020, 6:50 AM
 */


#include <xc.h>

#include "Clock.h"


/*
 * Create static object of the struct to hold the current time
 */


/*
 * Create static object of the enum to hold the current mode
 */





/* 
 * initialize the time 
 * initialize the mode
 * start the timer  
 */
void CLOCK_Init(void)
{
    //initialize the time 
    
    //initialize the mode
    
    //start the timer
    
}
/*
 * Return the current mode
 */
Mode_t CLOCK_GetMode(void)
{
    //Return the current mode
    
}
/*
 *  current time 
 */
void CLOCK_GetTime(Time_t * t)
{
    // copy the time the passed variable
}
/*
 * increment the time with the tick period
 */
void CLOCK_Increment(void)
{
    // add the tick value to the mSeconds
    
    //check if mSeconds bigger than or equal 60 
    
    //false return
    //true mSeconds = 0 Second++
    
    //check if Second bigger than or equal 60 
    
    //false return
    //true Second = 0 minutes++
    
    //check if minutes bigger than or equal 60 
    
    //false return
    //true minutes = 0 hours++
    
    
    //check if hours bigger than or equal 24 
    
    //false return
    //true hours = 0 
    
}
/*
 * periodic function called every tick period to update 
 * the statues of the clock 
 */
void CLOCK_Update(void)
{
    //check if set button is pressed
    // change the mode if true
    
    //normal
    CLOCK_Increment();
    
    
    //set minutes
    // check if plus is pressed 
    
    //increment the minutes if true
    
    // check if minus is pressed 
    
    //decrement the minutes if true
    
    
    
    // set hours
    // check if plus is pressed 
    
    //increment the hours if true
    
    // check if minus is pressed 
    
    //decrement the hours if true
    
    
}