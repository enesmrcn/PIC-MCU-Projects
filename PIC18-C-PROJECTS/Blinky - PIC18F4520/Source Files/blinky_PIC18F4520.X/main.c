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
    
    LATB &= ~(0xFF);
    TRISB &= ~(1 << 0);     //  TRISBbits.RB0 = 0;
    
    LATB &= ~(0xFF);
    
    while (1)
    {
        
        LATB |= 1 << 0;
        __delay_ms(500);
        
        LATB &= ~( 1 << 0);
        __delay_ms(500);
    }
    
    
    return;
}
