/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 30, 2020, 9:59 AM
 */


#define _XTAL_FREQ  8000000     // 8MHz external oscillator

#include "configuration.h"


void main(void) {
    
    PORTB = 0;      //  Clear beginning values
    TRISC = 0x01;   //  RC0 is input
    TRISB = 0;      //  RB0 is output
    
    ADCON1 = 0x07;  //  Digital input configuration for RB ports
    
    
    while (1)
    {
        if (PORTCbits.RC0 == 0)
        {
            
            LATBbits.LATB0 = 1; // Set RB0 high
            __delay_ms(10); //  wait for electromechanical arc for button
        }
        else if (PORTCbits.RC0 == 1)
        {
            LATBbits.LATB0 = 0; // Set RB0 high
             __delay_ms(10); //  wait for electromechanical arc for button
        }
    }
    
    return;
}
