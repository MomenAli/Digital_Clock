
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

#define SW_NUM (3)


/*
 * Switch type
 * we have three buttons in this application
 * please edit this enum if you change the application.
 */
typedef enum
{
    SW_PLUS,
    SW_MINUS,
    SW_SET
}SW_t;

/*
 * Switch states
 * if release
 */
typedef enum
{
    SW_RELEASED,
    SW_PRE_PRESSED,
    SW_PRESSED,
    SW_PRE_RELEASED
}SW_State_t;




/*
 * Initialize the buttons 
 * Initialize the samples
 */
void SW_Init(void);
/*
 * get the current state of button
 */
u8_t SW_GetState(SW_t sw);
/*
 * update the samples of the situation of button
 * update the state of the button
 */
void SW_Update(void);

/*
 * update the state depend on the previous state the state transition table
 */
void SW_UpdateState(SW_t sw);

#endif	/* XC_HEADER_TEMPLATE_H */

