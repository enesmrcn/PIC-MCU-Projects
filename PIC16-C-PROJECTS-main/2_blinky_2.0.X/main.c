/*
 * File:   main.c
 * Author: Enes Mercan
 *
 * Created on Sept, 2020
 * 
 * Scenario :   Turning on the group1 LEDs connected to RB0, RB1, RB2, RB3
 *              and then turning on the LEDs on RB4, RB5, RB5, RB6, RB7
 *              continuously
 * 
 * Purpose :	hello world to embedded systems
 */


#include "configuration.h"     // include my header files !!!
#include <stdbool.h>    // we need this library to use "true"

#define _XTAL_FREQ 10000000 // 10MHz external rc oscillator used here

void main(void) {
    
    PORTB = 0;  // Clear Portb pins for first use
    TRISB = 0;  // set all Portb pins as output
    
    
    // microcontroller will repeat here forever
    while (true)
    {
        
        // turn on the first group
        PORTB = 0x0F;   // 0x is the hex representation of numbers
        
        //wait 400 milliseconds
        __delay_ms(400);
        
        
        //turn off the LED
        PORTB = 0xF0;
        
        //wait 400 ms
        __delay_ms(400);
        
    }
    
    return;
}
