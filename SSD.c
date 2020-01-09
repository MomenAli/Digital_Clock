/*
 * File:   SSD.c
 * Author: Momen Ali
 *
 * Created on January 5, 2020, 11:21 AM
 */
#include"Port.h"
#include"SSD.h"
#include"Timer.h"

/*
 * define number of ticks need to update
 * MIN FREQ TO UPDATE SSD = 20 HZ    =>  MAX TIME = 1/20 = 50 ms 
 * MAX FREQ TO UPDATE SSD = 50 HZ    =>  MIN TIME = 1/50 = 20 ms
 * we have 4 SSD in this application
 * MAX TIME = MAX TIME PER SSD / NUMBER OF SSD = 50/4 = 12.5 ms
 * MIN TIME = MIN TIME PER SSD / NUMBER OF SSD = 20/4 = 5 ms
 * 10 ms 
 */
#define SSD_UPDATE_TICK (5)
/*
 * Buffer for the current displayed values
 */

void SSD_Disable(SSD_t s);
void SSD_Enable(SSD_t s);
void SSD_Data_write(void);




static SSD_Symbol_t Buffer[NUMBER_SSD];
/*
 * Buffer for the current displayed values
 */
static u8_t currentSSD = 0;

static tSSD_State Second_Dot_State;
#ifdef _12_MODE
static tSSD_State PM_Dot_State;
#endif
/*
 * LOOK UP TABLE
 * edit this table to add new symbols
 */ 
static u8_t SSD_LOT_ARR[] = 
{ 
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b00000000
};


void SSD_Init()
{
    //initialize to data port
    GPIO_Init_Port(&SSD_DATA_DIR,GPIO_OUT);
  
    //initialize MINUTES UNITS enable pin
    GPIO_Init_Pin(&SSD_MINUTES_UNITS_DIR,SSD_MINUTES_UNITS_PIN,GPIO_OUT);
    GPIO_Write_Pin(SSD_MINUTES_UNITS_PORT,SSD_MINUTES_UNITS_PIN,SSD_OFF);
    //initialize MINUTES TENS enable pin
    GPIO_Init_Pin(&SSD_MINUTES_TENS_DIR,SSD_MINUTES_TENS_PIN,GPIO_OUT);
    GPIO_Write_Pin(SSD_MINUTES_TENS_PORT,SSD_MINUTES_TENS_PIN,SSD_OFF);
    //initialize HOURS UNITS enable pin
    GPIO_Init_Pin(&SSD_HOURS_UNITS_DIR,SSD_HOURS_UNITS_PIN,GPIO_OUT);
    GPIO_Write_Pin(SSD_HOURS_UNITS_PORT,SSD_HOURS_UNITS_PIN,SSD_OFF);
    //initialize HOURS TENS enable pin
    GPIO_Init_Pin(&SSD_HOURS_TENS_DIR,SSD_HOURS_TENS_PIN,GPIO_OUT);
    GPIO_Write_Pin(SSD_HOURS_TENS_PORT,SSD_HOURS_TENS_PIN,SSD_OFF);
    
    // initialize the dots
    Second_Dot_State = SSD_OFF;
#ifdef _12_MODE
    PM_Dot_State = SSD_OFF;
#endif
    
}
void SSD_Set_Symbol(SSD_Symbol_t symbol,SSD_t index)
{
    // set the passed symbol in the passed index
    Buffer[index] = symbol;
}
void SSD_Update(void)
{
    /*
     * create static variable to hold time
     */
    static u8_t SSD_Time_Counter = 0; 
    SSD_Time_Counter += OS_TICK;
    //check if it's my tick 
    if(SSD_Time_Counter != SSD_UPDATE_TICK)
    {
        return;
    }
    SSD_Time_Counter = 0;
    
    // disable previous SSD
    SSD_Disable(currentSSD);
    //increment the current index
    currentSSD++;
    if(currentSSD > SSD_HOURS_TENS)currentSSD = 0;  
    // write data on port
    SSD_Data_write();
    //enable the current SSD
    SSD_Enable(currentSSD);
}

void SSD_Disable(SSD_t s)
{
    switch(s)
    {
        case SSD_MINUTES_UNITS:
            GPIO_Write_Pin(SSD_MINUTES_UNITS_PORT,SSD_MINUTES_UNITS_PIN,SSD_OFF);
            break;
        case SSD_MINUTES_TENS:
            GPIO_Write_Pin(SSD_MINUTES_TENS_PORT,SSD_MINUTES_TENS_PIN,SSD_OFF);
            break;
        case SSD_HOURS_UNITS:
            GPIO_Write_Pin(SSD_HOURS_UNITS_PORT,SSD_HOURS_UNITS_PIN,SSD_OFF);
            break;
        case SSD_HOURS_TENS:
            GPIO_Write_Pin(SSD_HOURS_TENS_PORT,SSD_HOURS_TENS_PIN,SSD_OFF);
            break;
        default:
            /*never go here*/;
    }
}

void SSD_Enable(SSD_t s)
{
    switch(s)
    {
        case SSD_MINUTES_UNITS:
            GPIO_Write_Pin(SSD_MINUTES_UNITS_PORT,SSD_MINUTES_UNITS_PIN,SSD_ON);
            break;
        case SSD_MINUTES_TENS:
            GPIO_Write_Pin(SSD_MINUTES_TENS_PORT,SSD_MINUTES_TENS_PIN,SSD_ON);
            break;
        case SSD_HOURS_UNITS:
            GPIO_Write_Pin(SSD_HOURS_UNITS_PORT,SSD_HOURS_UNITS_PIN,SSD_ON);
            break;
        case SSD_HOURS_TENS:
            GPIO_Write_Pin(SSD_HOURS_TENS_PORT,SSD_HOURS_TENS_PIN,SSD_ON);
            break;
        default:
            /*never go here*/;
    }
}



void SSD_Data_write(void)
{
    // output the symbol in the data port
    GPIO_Write_Port(SSD_DATA_PORT,SSD_LOT_ARR[Buffer[currentSSD]]);
    //Blink dot if minutes unit
    if(currentSSD == SSD_MINUTES_UNITS)
    {
        GPIO_Write_Pin(SSD_DATA_PORT,PIN_7,Second_Dot_State);
    }
    
#ifdef _12_MODE
    //on dot if PM and hours tens
    if(currentSSD == SSD_HOURS_TENS)
    {
        GPIO_Write_Pin(SSD_DATA_PORT,PIN_7,PM_Dot_State);
    }
#endif
}


void SSD_Toggle_Second_Dot(void)
{
    Second_Dot_State ^= 1;
}
#ifdef _12_MODE
void SSD_Set_PM_Dot(tSSD_State s)
{
    PM_Dot_State = s;
}
#endif