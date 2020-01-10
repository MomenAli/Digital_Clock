/*
 * File:   Clock.c
 * Author: Momen Ali
 *
 * Created on January 7, 2020, 6:50 AM
 */


#include <xc.h>

#include "Clock.h"
#include "SW.h"
#include"Timer.h"
#include "GPIO.h"
#include "Port.h"

/*lets assume it 20 till we make dynamic design*/
#define CLOCK_UPDATE_TICK (20)



/*
 * increment the time with the tick period
 */
void CLOCK_Increment(void);
/*
 * send pointer to min or hours and check if plus or minus was pressed
 */
void set_mode_process(u8_t * var, u8_t limit);

/*
 * Create static object of the struct to hold the current time
 */
static Time_t CurrentTime;

/*
 * Create static object of the enum to hold the current mode
 */
static Mode_t CurrentMode;


/* 
 * initialize the time 
 * initialize the mode
 * start the timer  
 */
void CLOCK_Init(void)
{
    //initialize the time 
    CurrentTime.hours = 0;
    CurrentTime.minuts = 0;
    CurrentTime.seconds = 0;
    CurrentTime.mSeconds = 0;
    
    //initialize the mode
    CurrentMode = CL_NORMAL;
    //start the timer
    /*NOT DONE*/
    /*test code*/
    GPIO_Set_Dir_Pin(LED_4_DIR,LED_4_PIN,GPIO_OUT);
    GPIO_Write_Pin(LED_4_PORT,LED_4_PIN,1);
    /*end of test code*/
    
}
/*
 * Return the current mode
 */
Mode_t CLOCK_GetMode(void)
{
    //Return the current mode
    return CurrentMode;
}
/*
 *  current time 
 */
void CLOCK_GetTime(Time_t * t)
{
    // copy the time the passed variable
    t->hours = CurrentTime.hours;
    t->minuts = CurrentTime.minuts;
    t->seconds = CurrentTime.seconds;
    t->mSeconds = CurrentTime.mSeconds;
}
/*
 * increment the time with the tick period
 */
void CLOCK_Increment(void)
{
    // add the tick value to the mSeconds
    CurrentTime.mSeconds+=CLOCK_UPDATE_TICK;
    //check if mSeconds bigger than or equal 1000 
    /* 
     * our calculation is every 8 timer tick 1 ms 
     * clock tick = 5 * 1 = 5 ms 
     * 200 * 5 ms = 1 s
     * we have error 8 * 128us = 1024 us
     * tick = 5 * 1024 = 5120 us
     * 200 * 5120 us = 1024 ms  error 24+ in the second
     * 196 * 5120 us = 1003 ms
     */
    if(CurrentTime.mSeconds >= 980 /* 1000  changed to correct the error */)
    {
        //false return
        //true mSeconds = 0 Second++
        CurrentTime.mSeconds = 0;
        CurrentTime.seconds += 1;
        //check if Second bigger than or equal 60 
        if(CurrentTime.seconds>=60)
        {
            //false return
            //true Second = 0 minutes++
            CurrentTime.seconds = 0;
            CurrentTime.minuts += 1;
            //check if minutes bigger than or equal 60 
            if(CurrentTime.minuts>=60)
            {
                //false return
                //true minutes = 0 hours++
                CurrentTime.minuts = 0;
                CurrentTime.hours += 1;
                //check if hours bigger than or equal 24 
                if(CurrentTime.hours>=24){
                    //false return
                    //true hours = 0 
                    CurrentTime.hours = 0;
                }
            }
        }
    }
}
/*
 * periodic function called every tick period to update 
 * the statues of the clock 
 */
void CLOCK_Update(void)
{
     /*
     * create static variable to hold time
     */
    static u8_t CLOCK_Time_Counter = 10; 
    CLOCK_Time_Counter += OS_TICK;
    //check if it's my tick 
    if(CLOCK_Time_Counter != CLOCK_UPDATE_TICK)
    {
        return;
    }
    CLOCK_Time_Counter = 0;
    
    //check if set button is pressed
    if(SW_GetState(SW_SET) == SW_PRE_PRESSED)
    {
        
        // change the mode if true
        switch(CurrentMode)
        {
            case CL_NORMAL:
                CurrentMode = CL_SET_HOURS;
                break;
            case CL_SET_HOURS:
                CurrentMode = CL_SET_MINUTES;
                break;
            case CL_SET_MINUTES:
                CurrentMode = CL_NORMAL;
                break;
            default:
                break;
        }
    }
    
    //normal
    if(CurrentMode == CL_NORMAL)
    {
        CLOCK_Increment();
    }
    else
    {
        switch(CurrentMode)
        {

            case CL_SET_HOURS:
                // set hours
                set_mode_process(&CurrentTime.hours , 24);
                break;
            case CL_SET_MINUTES:
                //set minutes
                set_mode_process(&CurrentTime.minuts , 60);
                break;
            default:
                break;
        }
    }
}


void set_mode_process(u8_t * var , u8_t limit)
{
    if(SW_GetState(SW_PLUS) == SW_PRE_PRESSED)
    {
        // check if plus is pressed 
        //increment the var if true
        *var += 1;
        if(*var == limit)*var = 0;
    }
    if(SW_GetState(SW_MINUS) == SW_PRE_PRESSED)
    {
        // check if minus is pressed 
        //decrement the var if true
        if(*var == 0)*var = limit;
        *var -= 1;
    }
    
}