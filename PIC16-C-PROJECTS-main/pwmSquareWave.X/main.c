/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 24, 2020, 8:22 PM
 */


// 1ms periyodu olan 50% duty cycle dalga uretir

#define _XTAL_FREQ  4000000

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>


void main(void) {
    
    PORTC = 0;
    TRISC = 0;
    
    
    INTCONbits.GIE = 1;
    INTCONbits.INTE = 1;
    
    // PWM mode
    CCP1M3 = 1;
    CCP1M2 = 1;
    
    PR2 = 249;      //  Period length
    CCPR1L = 125;   //  duty cycle length
    
    T2CKPS1 = 0;    //  Prescale
    T2CKPS0 = 1;
    
    TMR2ON = 1;
    
    while (true)
    {
       // nothing to do . . . 
        
    }
    
    return;
}
