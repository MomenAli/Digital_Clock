/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:        GPIO.h
 * Author:      Momen Ali
 * Comments:    this file contain definitions and functions of GPIO
 * Revision history: 3/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __GPIO_H
#define	__GPIO_H

#include <xc.h> // include processor files - each processor file is guarded.  


#include "HW.h"

#define PIN_0 (0)
#define PIN_1 (1)
#define PIN_2 (2)
#define PIN_3 (3)
#define PIN_4 (4)
#define PIN_5 (5)
#define PIN_6 (6)
#define PIN_7 (7)

/* GPIO port operations */
#define GPIO_Set_Dir_Port(DIRECTION_REG , DIRECTION)    ((DIRECTION_REG)=(DIRECTION)?(~0):(0))
#define GPIO_Write_Port(DATA_REG , DATA)                ((DATA_REG)=(DATA))
#define GPIO_Read_Port(DATA_REG)                        (DATA_REG)


/* GPIO pin operations */
#define GPIO_Set_Dir_Pin(DIRECTION_REG ,PIN, DIRECTION)     ((DIRECTION_REG)=(DIRECTION_REG & ~(1<<PIN))|(DIRECTION<<PIN))
#define GPIO_Write_Pin(DATA_REG ,PIN, DATA)                 ((DATA_REG)=(DATA_REG & ~(1<<PIN))|(DATA<<PIN))
#define GPIO_Read_Pin(DATA_REG ,PIN)                        ((DATA_REG >> PIN)& 1)



u8_t GPIO_Init_Port(u8_t * DirRegAddress/*direction register address*/,u8_t dir/* DIRECTION*/);
u8_t GPIO_Init_Pin(u8_t * DirRegAddress/*direction register address*/,u8_t pin_number,u8_t dir/* I/O*/);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

