/*
 * File:   main.c
 * Author: Enes Mercan
 *
 * Created on Sept, 2020
 * 
 * Scenario :   Drive the LED on RB0 and RA0 using the button RB1 and RA1
 * 
 * Purpose :	to learn reading digital pins
 *              
 */


#include "configuration.h"     // include my header files !!!
#include <stdbool.h>    // we need this library to use "true"

#define _XTAL_FREQ 10000000 // 10MHz external rc oscillator used here

#define BUTTON_A RA1
#define BUTTON_B RB1
#define LED_A    RA0
#define LED_B    RB0


void main(void) {
    
    PORTB = 0;          // clear initial values
    PORTA = 0;
    
    TRISA = 0b00000010; // RA1 is as input RA0 (led0) is output
    TRISB = 0x02;       // 0b00000010 ... RB1 is as input
    CMCON = 0b00000111; // To be able to use RA0~RA4 pins as digital pin
                        //  you shall do this configuration on CMCON register
    
    
    // infinite loop (always repeat)
    while (true)
    {
        
        if ( BUTTON_A == 1) // check the button status on ra1
        {
            LED_A = 0;      // turn on ra0 led
        }
        else
        {
            LED_A = 1;
        }
        
        
        if (BUTTON_B == 1)  // check the button status on rb1
        {
            LED_B = 0;      // turn on rb0 led
        }
        else 
        {
            LED_B = 1;
        }
        
    }
    
    return;
}
