/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 24, 2020, 8:55 PM
 */

#define _XTAL_FREQ  4000000

#include "config.h"

void __interrupt() myIntHandler(void);

void main(void) {
    
    GIE = 1;
    RBIE = 1;
    
    // PWM mode for CCP1 module
    CCP1M3 = 1;
    CCP1M2 = 1;
    
    //  Period 1ms and 50$ duty cycle signal settings
    PR2 = 249;
    CCPR1L = 125;
    T2CKPS1 = 0;
    T2CKPS0 = 1;
    
    TMR2ON = 1;
    
    TRISB = 0xFF;  //  All input
    TRISD = 0;     //  All output
    TRISC = 0;
    
    while (1)
    {
        // nothing to do . . .
    }
    
    return;
}

void __interrupt() myIntHandler()
{
    if (RB2 == 0)
            PORTD = 5;
        else
            PORTD = 10;
        
        if (RB1)
        {    
            if (CCPR1L > 246)
                CCPR1L = 1;
            
            CCPR1L += 10;
        }
        
        if (RB0)
        {    
            if (CCPR1L == 0)
                CCPR1L = 245;
            
            CCPR1L -= 10;
        }
    
    RBIF = 0;
}