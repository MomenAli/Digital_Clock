
/* 
 * File:        SW.h
 * Author:      Momen Ali
 * Comments:    SWITCH header file rule is handling the switches press
 * Revision history:    6/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __SW_H
#define	__SW_H

#include <xc.h> // include processor files - each processor file is guarded.  


typedef enum
{
    Plus,
    Minus,
    SET        
}SW_t;


void SW_Init(void);
u8_t SW_GetState(SW_t sw);
void SW_Update(void);

#endif	/* XC_HEADER_TEMPLATE_H */

