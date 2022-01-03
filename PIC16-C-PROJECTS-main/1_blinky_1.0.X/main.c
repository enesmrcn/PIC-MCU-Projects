/*
 * File:   main.c
 * Author: Enes Mercan
 *
 * Created on Sept, 2020
 * 
 * Scenario :   Turning on the LED attached to RA0
 * Purpose :	hello world to embedded systems
 */


#include "configuration.h"     // include my header files !!!
#include <stdbool.h>    // we need this library to use "true"

#define _XTAL_FREQ 10000000 // 10MHz external rc oscillator used here

void main(void) {
    
    PORTA = 0;  // Clear porta pins for first use
    TRISA = 0;  // set all portA pins as output
    
    
    // microcontroller will repeat here forever
    while (true)
    {
        
        // turn on the LED
        PORTA = 0x01;   // 0x is the hex representation of numbers
        
        //wait 400 milliseconds
        __delay_ms(400);
        
        
        //trun off the LED
        PORTA = 0x00;
        
        //wait 400 ms
        __delay_ms(400);
        
    }
    
    return;
}
