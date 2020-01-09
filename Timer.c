/*
 * File:   Timer.c
 * Author: Momen Ali
 *
 * Created on January 8, 2020, 6:12 PM
 */


#include <xc.h>

#include "HW.h"
#include "Timer.h"
#include "GPIO.h"
#include "Port.h"

static u16_t tempCounter = 0;

void TMR_Init(void)
{
    // initialize the timer
    // set up the timer pre scaler
    TMR_PRESCALER_256;
    // stop timer
    TMR_DISABLE_CLOCK;
    //test code
    GPIO_Set_Dir_Pin(LED_4_DIR,LED_4_PIN,GPIO_OUT);
    GPIO_Write_Pin(LED_4_PORT,LED_4_PIN,0);
    // end of test code
}
void __interrupt() TMR0_ISR() 
{
    
    // reset the overflow flag
    TMR_CLEAR_FLAG;
    // load the timer register with the tick
    TMR_LOAD_REGISTER(OS_TICK);
    // call tasks
    //test code
    tempCounter++;
    if(tempCounter>500)
    {
        GPIO_Write_Pin(LED_4_PORT,LED_4_PIN,1);
    }
    if(tempCounter >1000)
    {
        tempCounter = 0;
        GPIO_Write_Pin(LED_4_PORT,LED_4_PIN,0);
    }
    // end of test code
}
void TMR_Start(void)
{
    // update the clock flag to start
    TMR_CLEAR_FLAG;
    // load the timer register with the tick
    TMR_LOAD_REGISTER(OS_TICK);
    // enable the ISR
    TMR_ENABLE_INTERRUPT;
    GLOBAL_INTERRUPT_ENABLE;
    // enable the clock
    TMR_ENABLE_CLOCK;
}
void TMR_Stop(void)
{
    // update the clock flag to stop
    TMR_DISABLE_CLOCK;
}
u8_t TMR_CheckOverflow(void)
{
    // return the overflow flag
    return TMR_GET_FLAG;
}