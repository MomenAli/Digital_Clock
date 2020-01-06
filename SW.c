/*
 * File:   SW.c
 * Author: Momen Ali
 *
 * Created on January 6, 2020, 11:18 AM
 */


/*
 * State Struct to hold data 
 * the state of the switch
 * 2 samples of the last situation of the switch
 *   _________________________________________________________________
 *  | state   | last sample (n-1) | present sample (n) |  next state  |
 *  |_________|___________________|____________________|______________|
 *  | pre rel |         0         |        0           |   release    |
 *  |_________|___________________|____________________|______________|
 *  | release |         1         |        1           |   pre pre    |
 *  |_________|___________________|____________________|______________|
 *  | pre pre |         1         |        1           |   pressed    |
 *  |_________|___________________|____________________|______________|
 *  | pressed |         0         |        0           |   pre rel    |
 *  |_________|___________________|____________________|______________|
 * 
 */

typedef struct 
{
    u8_t samples[2];
    u8_t state;
}SW_DATA_t;

/*
 * Create array of structs to hold data
 */

void SW_Init(void)
{
     
    // initialize the the plus switch
    
    // initialize the the Minus switch
    
    // initialize the the SET switch
    
}
u8_t SW_GetState(SW_t sw)
{
    u8_t ret =0;
    
    // return the state of the passed switch
    
    return ret;
}
void SW_Update(void)
{
    //check if it's my tick 
    
    // update samples of plus switch
    
    // update state of plus switch
    
    
    // update samples of minus switch
    
    // update state of minus switch
    
    // update samples of set switch
    
    // update state of set switch
    
}

