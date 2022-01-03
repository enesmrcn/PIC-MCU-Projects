/*
 * File:        main.c
 * Author:      Enes Mercan
 *
 * Created on   Sept, 2020
 * 
 * Scenario :   LEDs connected to RB0 ~ RB6
 *              the 8 LEDs (rb0~rb7) will shift from left to right and from 
 *              right to left one by one repeatedly
 *		        
 * 
 * Purpose :	practicing
 * 
 */

#include "config.h"
#include <stdint.h>

#define _XTAL_FREQ 10000000

const uint8_t ON_TIME = 35;
const uint8_t OFF_TIME = 10;

uint8_t led [8] = {1, 2, 4, 8, 16, 32, 64, 128};

void main(void) {
    
    
    PORTB = 0;          // Clear initial values
    TRISB = 0;          // All RBn pins are as output
    
    
    while (1)            // forever loop
    {
        
        for (int8_t i = 0; i<8; i++)   // goes from RB0 to RB7
        {
            PORTB = led[i];          // blink led
            __delay_ms(ON_TIME);    // for 120ms
            
            if ( i == 7)            // for the last led, keep it on
                continue;           // skip turning off it
            
            PORTB = 0;              // turn it off
            __delay_ms(OFF_TIME);    //  wait 100ms
        }
        
        
        __delay_ms(ON_TIME);        // wait little bit more at the very left
        
        
        for (int8_t i = 7; i>=0; i--)      // goes from RB7 to RB0
        {
            PORTB = led[i];
            __delay_ms(ON_TIME);
            
            
            PORTB = 0;
            __delay_ms(OFF_TIME);
            
        }
        
        __delay_ms(ON_TIME);        // wait little bit more at the right left
        
    }
    
    return;
}
