/*
 * File:   GPIO.c
 * Author: Momen Ali
 *
 * Created on January 3, 2020, 1:15 AM
 */


#include "HW.h"
#include "GPIO.h"



u8_t GPIO_Init_Port(u8_t * DirRegAddress/*direction register address*/,u8_t dir/* DIRECTION*/)
{
    u8_t ret =1;
    /*check if the address valid*/
    if(*DirRegAddress != GPIO_PORTA_DIR && *DirRegAddress != GPIO_PORTB_DIR &&
       *DirRegAddress != GPIO_PORTC_DIR && *DirRegAddress != GPIO_PORTD_DIR &&
       *DirRegAddress != GPIO_PORTE_DIR)
    {
       /*invalid input return 0 */
       ret =0;
    }
    else
    {
        GPIO_Set_Dir_Port(*DirRegAddress ,dir);

    }
    return ret;
}


u8_t GPIO_Init_Pin(u8_t *DirRegAddress/*direction register address*/,u8_t pin_number,u8_t dir/* DIRECTION*/)
{
    u8_t ret = 1;
    /*check if the address valid*/
    if(*DirRegAddress != GPIO_PORTA_DIR && *DirRegAddress != GPIO_PORTB_DIR &&
       *DirRegAddress != GPIO_PORTC_DIR &&*DirRegAddress != GPIO_PORTD_DIR &&
       *DirRegAddress != GPIO_PORTE_DIR)
    {
       /*invalid input return 0 */
       ret = 0;
    }
    else
    {      
        GPIO_Set_Dir_Pin(*DirRegAddress,pin_number,dir);
    }
    return ret;
}

