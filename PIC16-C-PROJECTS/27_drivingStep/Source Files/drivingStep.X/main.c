/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 27, 2020, 1:46 PM
 */



#define _XTAL_FREQ  4000000

#include "config.h"
#include <stdint.h>
#include <stdbool.h>

void __interrupt() myIntHandler();

uint8_t step[] = {1, 3, 2, 6, 4, 12, 8, 9};
int8_t i = 0;
int16_t delay = 2000;

void main(void) {
    
    TRISC = 1;
    TRISB = 0;
    
    
    while (true)
    {
        PORTB = step[i];
        __delay_ms(1500);
        
        if ( RC0 == 0)
        {
            if ( i == 7)
                i = -1;
            
            i++;
        }
        else
        {
            if ( i == 0)
                i = 8;
            
            i--;
        }
        
    }
    
    return;
}


void __interrupt() myIntHandler()
{
    
    
}
