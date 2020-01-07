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
}
void Disp_Upate(void)
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
