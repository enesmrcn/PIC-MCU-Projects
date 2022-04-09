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
 * Purpose :	learning to use #define to give memorable names
 *               This is not the efficient way. But just to learn...
 */


#include "configuration.h"     // include my header files !!!
#include <stdbool.h>    // we need this library to use "true"

#define _XTAL_FREQ 10000000 // 10MHz external rc oscillator used here

// we use more meaningful names using #define
#define LED0    RB0
#define LED1    RB1
#define LED2    RB2
#define LED3    RB3
#define LED4    RB4
#define LED5    RB5
#define LED6    RB6
#define LED7    RB7

void main(void) {
    
    PORTB = 0;  // Clear Portb pins for first use
    TRISB = 0;  // set all Portb pins as output
    
    
    // microcontroller will repeat here forever
    while (true)
    {
        
        // turn on the first group
        //PORTB = 0xF0;
        LED0 = 1;
        LED1 = 1;
        LED2 = 1;
        LED3 = 1;
        LED4 = 0;
        LED5 = 0;
        LED6 = 0;
        LED7 = 0;
        
        
        //wait 400 milliseconds
        __delay_ms(400);
        
        
        //turn off the LED
        // PORTB = 0x0F;
        LED0 = 0;
        LED1 = 0;
        LED2 = 0;
        LED3 = 0;
        LED4 = 1;
        LED5 = 1;
        LED6 = 1;
        LED7 = 1;
        
        //wait 400 ms
        __delay_ms(400);
        
    }
    
    return;
}
