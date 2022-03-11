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
    
    
    LATB1 = 1;  //  Set RB1 as logic high (output)
    
    while (1)
    {
        LATB ^= 0b00010010;  // Toggle RB1 and RB4
        __delay_ms(500);    //  Delay 500ms
        
    }
    
    // alternative code below for beginners
    /*
    while (1)
    {
        LATBbits.LATB1 = 1; //  Turn on RB1
        LATBbits.LATB4 = 0; //  Turn off RB4
        __delay_ms(500);    // delay 500 milliseconds
        
        
        LATBbits.LATB1 = 0; //  Turn off RB1
        LATBbits.LATB4 = 1; //  Turn on RB4
        __delay_ms(500);    // delay 500 milliseconds
    }
     */
    
    return;
}
