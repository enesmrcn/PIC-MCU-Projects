/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 29, 2020, 9:10 PM
 */


#define _XTAL_FREQ  8000000     // 8MHz external oscillator

#include "configuration.h"


void main(void) {
    
    // Uncomment below if you want to use internal oscillator
    // OSCCON = 0x76
    
    PORTB = 0;  //  Reset the initial values
    TRISB = 0;  //  All PORTB pins are output
    ADCON1 = 0x07;  //  Set RB<4:0> digital I/O pins
    
    
    while (1)
    {
        LATBbits.LATB1 = 0; //  Turn on the LED
        __delay_ms(500);    // delay 500 milliseconds
        
        LATBbits.LATB1 = 1; //  Turn off it back
        __delay_ms(500);    // delay 500 milliseconds
    }
    return;
}
