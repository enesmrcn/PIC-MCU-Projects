/*
 * File:   main.c
 * Author: Enes Mercan
 *
 * Created on Sept, 2020
 * 
 * Scenario :   2 LEDs connected to RB0 and RB3
 *              using the button on RA0, blink them one by one
 * 
 * Purpose :	just practicing with easy things
 * 
 */


#include "configuration.h"     // include my header files !!!
#include <stdbool.h>    // we need this library to use "true"

#define _XTAL_FREQ 10000000 // 10MHz external rc oscillator used here

void main(void) {
    
    PORTB = 0;      // clear initial values
    
    TRISB = 0x00;   // Port-B output
    TRISA = 0x01;   // RA0 is input
    
    CMCON = 07;     // disable comparator modules
    
    
    
    while (1)
    {
        
        if (RA0 == 1)
        {
            RB0 = 0;
            RB3 = 1;
        }
        else{
            RB0 = 1;
            RB3 = 0;
        }
    }
    
    return;
}
