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

/************************************port***********************************
 *                               description                               *
 * this header included all the configuration depend on your schematic     *
 * please change the configuration if you change board 3                   *                             *
 ***************************************************************************/

//LED NUMBER 1
#define  LED_1_PORT GPIO_PORTB_DATA
#define  LED_1_DIR  GPIO_PORTB_DIR
#define  LED_1_PIN  PIN_0
//LED NUMBER 2
#define  LED_2_PORT GPIO_PORTB_DATA
#define  LED_2_DIR  GPIO_PORTB_DIR
#define  LED_2_PIN  PIN_1
//LED NUMBER 3
#define  LED_3_PORT GPIO_PORTB_DATA
#define  LED_3_DIR  GPIO_PORTB_DIR
#define  LED_3_PIN  PIN_2
//LED NUMBER 4
#define  LED_4_PORT GPIO_PORTB_DATA
#define  LED_4_DIR  GPIO_PORTB_DIR
#define  LED_4_PIN  PIN_3



#endif	/* XC_HEADER_TEMPLATE_H */

