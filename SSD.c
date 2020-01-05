/*
 * File:   SSD.c
 * Author: Momen Ali
 *
 * Created on January 5, 2020, 11:21 AM
 */
#include"Port.h"
#include"SSD.h"

/*
 * define number of ticks need to update
 * MIN FREQ TO UPDATE SSD = 20 HZ    =>  MAX TIME = 1/20 = 50 ms 
 * MAX FREQ TO UPDATE SSD = 50 HZ    =>  MIN TIME = 1/50 = 20 ms
 * we have 4 SSD in this application
 * MAX TIME = MAX TIME PER SSD / NUMBER OF SSD = 50/4 = 12.5 ms
 * MIN TIME = MIN TIME PER SSD / NUMBER OF SSD = 20/4 = 5 ms
 * 10 ms 
 */
#define SSD_UPDATE_TICK (10)
/*
 * Buffer for the current displayed values
 */

static SSD_Symbol_t Buffer[NUMBER_SSD];
/*
 * Buffer for the current displayed values
 */
static currentSSD = 0;

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
    
    //initialize MINUTES UNITS enable pin
    
    //initialize MINUTES TENS enable pin
    
    //initialize HOURS UNITS enable pin
    
    //initialize HOURS TENS enable pin
}
void Set_Symbol(SSD_Symbol_t symbol,SSD_t index)
{
    // set the passed symbol in the passed index
    
}
void update(void)
{
    //check if my tick comes
    
    
    
    // disable all the SSDs
    
    //increment the current index
    
    // output the symbol in the data port
    
    //enable the current SSD
    
}