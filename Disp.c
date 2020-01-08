/*
 * File:   Disp.c
 * Author: Momen Ali
 *
 * Created on January 7, 2020, 9:10 AM
 */


#include <xc.h>

#include "SSD.h"
#include "Clock.h"


/*
 * WE CAN MAKE TICK OF THE DISP = TICK CYCLE OF SSD 
 */
#define DISP_UPDATE_TICK  (20)
/*counter for blinking*/
static u8_t Disp_Blink_counter;

/*
 * operate the clock at normal mode  
 */
void DISP_Normal_Operation(void);
/*
 * operate the clock at set hours mode  
 */
void DISP_Set_Hours_Operation(void);
/*
 * operate the clock at set minutes mode  
 */
void DISP_Set_Minutes_Operation(void);
/*
 * blink this dot every second as a sign of operation  
 */
void Blink_Minutes_Unit_Dot(void);

#ifdef _12_MODE
/*
 * switch on this dot on pm at 12 hours mode display  
 */
void Hours_Tens_Dot(SSD_t s);
#endif



void Disp_Init(void)
{
    //initialize the SSDs
    SSD_Init();
    //set initial value of ssds
    SSD_Set_Symbol(SSD_0,SSD_MINUTES_UNITS);
    SSD_Set_Symbol(SSD_0,SSD_MINUTES_TENS);
    SSD_Set_Symbol(SSD_0,SSD_HOURS_UNITS);
    SSD_Set_Symbol(SSD_0,SSD_HOURS_TENS);
    //initialize Blink counter
    Disp_Blink_counter = 0;
}
void Disp_Update(void)
{
    //check if it's my tick
    
    switch(CLOCK_GetMode())
    {
        case CL_NORMAL:
            //Normal mode
            DISP_Normal_Operation();
            break;
        case CL_SET_HOURS:
            //set hours mode
            DISP_Set_Hours_Operation();
            break;
        case CL_SET_MINUTES:
            //set minutes mode
            DISP_Set_Minutes_Operation();
            break;
    }
}




/*
 * operate the clock at normal mode  
 */
void DISP_Normal_Operation(void)
{
    // get current time
    Time_t tt;
    CLOCK_GetTime(&tt);
    // update the buffer symbols
#ifndef _12_MODE
    SSD_Set_Symbol(tt.hours/10,SSD_HOURS_TENS);
    SSD_Set_Symbol(tt.hours%10,SSD_HOURS_UNITS);
#endif
    SSD_Set_Symbol(tt.minuts/10,SSD_MINUTES_TENS);
    SSD_Set_Symbol(tt.minuts%10,SSD_MINUTES_UNITS);
    Disp_Blink_counter++;
    if(Disp_Blink_counter>= 25)
    {
        SSD_Toggle_Second_Dot();
        Disp_Blink_counter = 0;
    }
#ifdef _12_MODE
    SSD_Set_Symbol((tt.hours%12)/10,SSD_HOURS_TENS);
    SSD_Set_Symbol((tt.hours%12)%10,SSD_HOURS_UNITS);
    if((tt.hours/12)>0)SSD_Set_PM_Dot(SSD_ON);
    else SSD_Set_PM_Dot(SSD_OFF);
#endif
    
}
/*
 * operate the clock at set hours mode  
 */
void DISP_Set_Hours_Operation(void)
{
    
    // get current time
    Time_t tt;
    CLOCK_GetTime(&tt);
    //set minutes symbols at buffer
    SSD_Set_Symbol(tt.minuts/10,SSD_MINUTES_TENS);
    SSD_Set_Symbol(tt.minuts%10,SSD_MINUTES_UNITS);
    if(Disp_Blink_counter < 25)
    {
        //set symbols to buffer
        SSD_Set_Symbol(tt.hours/10,SSD_HOURS_TENS);
        SSD_Set_Symbol(tt.hours%10,SSD_HOURS_UNITS);
    }
    if(Disp_Blink_counter>25)
    {
        //set null to buffer to generate the blinking
        SSD_Set_Symbol(SSD_NULL,SSD_HOURS_TENS);
        SSD_Set_Symbol(SSD_NULL,SSD_HOURS_UNITS);
    }
    if(Disp_Blink_counter>=50)
    {
        // reset counter
        Disp_Blink_counter = 0;
    }
}
/*
 * operate the clock at set minutes mode  
 */
void DISP_Set_Minutes_Operation(void)
{
    
    // get current time
    Time_t tt;
    CLOCK_GetTime(&tt);
    //set hours symbols at buffer
#ifndef _12_MODE
    SSD_Set_Symbol(tt.hours/10,SSD_HOURS_TENS);
    SSD_Set_Symbol(tt.hours%10,SSD_HOURS_UNITS);
#endif
#ifdef _12_MODE
    SSD_Set_Symbol((tt.hours%12)/10,SSD_HOURS_TENS);
    SSD_Set_Symbol((tt.hours%12)%10,SSD_HOURS_UNITS);
    if((tt.hours/12)>0)SSD_Set_PM_Dot(SSD_ON);
    else SSD_Set_PM_Dot(SSD_OFF);
#endif
    if(Disp_Blink_counter < 25)
    {
        //set symbols to buffer
        SSD_Set_Symbol(tt.minuts/10,SSD_MINUTES_TENS);
        SSD_Set_Symbol(tt.minuts%10,SSD_MINUTES_UNITS);
    }
    if(Disp_Blink_counter>25)
    {
        //set null to buffer to generate the blinking
        SSD_Set_Symbol(SSD_NULL,SSD_MINUTES_TENS);
        SSD_Set_Symbol(SSD_NULL,SSD_MINUTES_UNITS);
    }
    if(Disp_Blink_counter>=50)
    {
        // reset counter
        Disp_Blink_counter = 0;
    }
}