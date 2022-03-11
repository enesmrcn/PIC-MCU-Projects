/*
 * File:   main.c
 * Author: enes
 *
 * Created on 06 October 2021, 19:43
 */


#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 1000000

void main(void) {
    
    LATB &=~(0xFF);
    TRISB &=~(0xFF);
    
    TRISD |= ((1 << 6) | (1 << 7));
    
    LATB &=~(0xFF);
    
    while (1)
    {
        if ( PORTD & (1 << 7))
            LATB |= (1 << 0);
        else
            LATB &=~(0x01);
        
        if ( PORTD & (1 << 6))
            LATB |= (1 << 1);
        else
            LATB &=~(0x02);
    }
    
    
    return;
}
