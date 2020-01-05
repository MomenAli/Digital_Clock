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
 * File:        Port
 * Author:      Momen Ali
 * Comments:    this file contain all the definitions related to schematic 
 * Revision history: 1/2/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __PORT_H
#define	__PORT_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "HW.h"
#include "GPIO.h"

/************************************port***********************************
 *                               description                               *
 * this header included all the configuration depend on your schematic     *
 * please change the configuration if you change board 3                   *                             *
 ***************************************************************************/

//sw NUMBER 1
#define  SW_P_PORT GPIO_PORTB_DATA
#define  SW_P_DIR  GPIO_PORTB_DIR
#define  SW_P_PIN  PIN_0
//sw NUMBER 2
#define  SW_M_PORT GPIO_PORTB_DATA
#define  SW_M_DIR  GPIO_PORTB_DIR
#define  SW_M_PIN  PIN_1
//sw NUMBER 3
#define  SW_S_PORT GPIO_PORTB_DATA
#define  SW_S_DIR  GPIO_PORTB_DIR
#define  SW_S_PIN  PIN_2
//sw NUMBER 4
#define  LED_4_PORT GPIO_PORTB_DATA
#define  LED_4_DIR  GPIO_PORTB_DIR
#define  LED_4_PIN  PIN_3


// SSD
#define SSD_DATA_PORT   GPIO_PORTD_DATA
#define SSD_DATA_DIR    GPIO_PORTD_DIR
// SSD MINUTES UNITS
#define SSD_MINUTES_UNITS_PORT  GPIO_PORTB_DATA
#define SSD_MINUTES_UNITS_DIR   GPIO_PORTB_DIR
#define SSD_MINUTES_UNITS_PIN   PIN_4
// SSD MINUTES TENS
#define SSD_MINUTES_TENS_PORT GPIO_PORTB_DATA
#define SSD_MINUTES_TENS_DIR  GPIO_PORTB_DIR
#define SSD_MINUTES_TENS_PIN  PIN_5
// SSD HOURS UNITS
#define SSD_HOURS_UNITS_PORT  GPIO_PORTB_DATA
#define SSD_HOURS_UNITS_DIR   GPIO_PORTB_DIR
#define SSD_HOURS_UNITS_PIN   PIN_6
// SSD HOURS TENS
#define SSD_HOURS_TENS_PORT  GPIO_PORTB_DATA
#define SSD_HOURS_TENS_DIR   GPIO_PORTB_DIR
#define SSD_HOURS_TENS_PIN   PIN_7





#endif	/* XC_HEADER_TEMPLATE_H */

