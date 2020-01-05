/*
 * File:   Digital_Clock.c
 * Author: engmo
 *
 * Created on January 5, 2020, 12:21 AM
 */


#include <xc.h>
#include "Port.h"
#include"GPIO.h"

void main(void) {
    //Initialization
    GPIO_Init_Port(&SSD_DATA_DIR,GPIO_OUT);
    GPIO_Init_Pin(&SSD_MINUTES_TENS_DIR,SSD_MINUTES_TENS_PIN,GPIO_OUT);
    GPIO_Write_Port(SSD_DATA_PORT,0xff);
    GPIO_Write_Pin(SSD_MINUTES_TENS_PORT,SSD_MINUTES_TENS_PIN,1);
    //super loop
    while(1);
    return;
}
