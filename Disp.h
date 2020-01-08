

/* 
 * File:        Disp.h 
 * Author:      Momen Ali   
 * Comments:    this is the layer connect between SSD and Clock brain 
 *              it know how to show different modes and times
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __DISP_H
#define	__DISP_H

#include <xc.h> // include processor files - each processor file is guarded.  

void Disp_Init(void);
void Disp_Update(void);

#endif	/* XC_HEADER_TEMPLATE_H */

