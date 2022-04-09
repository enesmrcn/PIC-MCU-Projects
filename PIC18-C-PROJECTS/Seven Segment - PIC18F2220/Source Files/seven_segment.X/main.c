/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on January 1, 2021, 10:55 AM
 */


#define _XTAL_FREQ  8000000
#define BUTTON PORTCbits.RC0

#include "seven_segment.h"
#include <stdint.h>

// array that represents each number of the segment in hex value
uint8_t displayMap[]= {0x3F, 0x06, 0x5B, 0x4F, 
                            0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
uint8_t counter = 0;    // counter for which number to be displayed

void main(void) {
    
    PORTB = 0;
    TRISB = 0;          //  All output for segmentDisplay
    TRISCbits.RC0 = 1;  //  Button connected here
    ADCON1 = 0x07;      //  Set RB<4:0> as digital I/O pins
    
    LATB = displayMap[counter]; // Set the display for start-up
    
    while (1)
    {
        if (BUTTON == 0)    //  Button is pushed
        {
            __delay_ms(10); //  delay for the mechanical arc
            
            if (counter != 9)
                counter++;
            else
                counter = 0;
            
            LATB = displayMap[counter];
            
            __delay_ms(800);
        }
        
    }
    
    return;
}
