/*
 * File:   main.c
 * Author: Enes Mercan
 *
 * Created on Sept, 2020
 * 
 * Scenario :   LEDs connected to RB0 ~ RB6
 *              will count in binary format
 * 
 * Purpose :	just practicing with easy things
 * 
 */


#include "config.h"
#include "stdint.h"

#define _XTAL_FREQ 10000000


void main(void) {
    
    uint8_t counter = 0;
    
    PORTB = 0;
    TRISB = 0;
    
    while (1)
    {
        counter++;
        
        PORTB = counter;
        
        if (counter == 255)
        {
            counter = 0;
        }
        
        __delay_ms(100);
    }
    
    return;
}
