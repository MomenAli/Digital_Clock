/*
 * File:   Digital_Clock.c
 * Author: Momen Ali
 *
 * Created on January 5, 2020, 12:21 AM
 */


#include <xc.h>
#include "Port.h"
#include"GPIO.h"
#include"SSD.h"
#include "SW.h"
#include "Clock.h"

void main(void) {
    //Initialization
    u8_t i = 0;
    SSD_Init();
    // GPIO_Write_Port(SSD_DATA_PORT)
    // set symbols
    SSD_Set_Symbol(i,SSD_MINUTES_UNITS);
    SSD_Set_Symbol(2,SSD_MINUTES_TENS);
    SSD_Set_Symbol(3,SSD_HOURS_UNITS);
    SSD_Set_Symbol(4,SSD_HOURS_TENS);
    
    //init clock
    CLOCK_Init();
    
    //super loop
    while(1)
    {
        __delay_ms(5);
        SW_Update();
        CLOCK_Update();
        SSD_Update();
    }  
    
}
