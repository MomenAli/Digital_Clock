/*
 * File:   Digital_Clock.c
 * Author: engmo
 *
 * Created on January 5, 2020, 12:21 AM
 */


#include <xc.h>
#include "Port.h"
#include"GPIO.h"
#include"SSD.h"

void main(void) {
    //Initialization
    SSD_Init();
    // GPIO_Write_Port(SSD_DATA_PORT)
    // set symbols
    SSD_Set_Symbol(1,SSD_MINUTES_UNITS);
    SSD_Set_Symbol(2,SSD_MINUTES_TENS);
    SSD_Set_Symbol(3,SSD_HOURS_UNITS);
    SSD_Set_Symbol(4,SSD_HOURS_TENS);
    //call update 
    SSD_Update();
    __delay_ms(1000);
    SSD_Update();
    __delay_ms(1000);
    SSD_Update();
    __delay_ms(1000);
    SSD_Update();
    __delay_ms(1000);
    SSD_Update();
    __delay_ms(1000);
    //super loop
    while(1);
    return;
}
