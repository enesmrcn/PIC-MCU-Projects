/*
 * File:   main.c
 * Author: enes
 *
 * Created on 06 October 2021, 19:43
 */


#include <xc.h>
#include "config.h"
#include <stdint.h>

#define _XTAL_FREQ 1000000

void main(void) {
    
    LATB &=~(0xFF);
    TRISB &=~(0xFF);
    
    TRISD |= ((1 << 6) | (1 << 7));
    
    LATB = 0x01;
    
    while (1)
    {
        if (PORTD & (1 << 7))
        {
            if ( PORTB >= 0x80)
                LATB = 1;
            else
                LATB *=2;
            
            __delay_ms(300);
        }
        
        if (PORTD & (1 << 6))
        {
            if ( PORTB <= 0x01)
                LATB = 0x80;
            else
                LATB /=2;
            
            __delay_ms(300);
        }
        
        asm("NOP");
    }
    
    
    return;
}

