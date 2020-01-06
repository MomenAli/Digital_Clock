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
 * File:        ssd.h
 * Author:      Momen Ali
 * Comments:    header file of ssd driver
 * Revision history: 5/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __SSD_H
#define	__SSD_H


#include <xc.h> // include processor files - each processor file is guarded.  

/*
 * NUMBER OF SSDs IN THIS APPLICATION 
 * please edit this number if you want to increase 
 * or decrease the number of SSDs
 */
#define NUMBER_SSD (4)

/* 
 * SSD symbols
 * please add your symbol here in the opposite 
 * of it's index in LOT 
 */
typedef enum
{
    SSD_0 = 0,
    SSD_1,
    SSD_2,
    SSD_3,
    SSD_4,
    SSD_5,
    SSD_6,
    SSD_7,
    SSD_8,
    SSD_9,
    SSD_NULL
}SSD_Symbol_t;

/* 
 * SSD type
 * please add your type here in the opposite 
 * of it's index in Buffer 
 */
typedef enum
{
    SSD_MINUTES_UNITS,
    SSD_MINUTES_TENS,
    SSD_HOURS_UNITS,
    SSD_HOURS_TENS
}SSD_t;

/* SSD states */
typedef enum
{
    SSD_OFF = 0,
    SSD_ON = 1
}tSSD_State;

void SSD_Init(void);
void SSD_Set_Symbol(SSD_Symbol_t symbol,SSD_t index);
void SSD_Update(void);
void SSD_Disable(SSD_t s);
void SSD_Enable(SSD_t s);
#endif	/* XC_HEADER_TEMPLATE_H */

