/*
 * File:   main.c
 * Author: Enes Mercan
 *
 * Created on Sept, 2020
 * 
 * Scenario :   2 LEDs connected to RB0 and RB1
 *              only one led will blink at once in every 400ms
 * 
 * Purpose :	just practicing with easy things
 * 
 */


#include "config.h"

#define _XTAL_FREQ 10000000

#define LED_1   RB0
#define LED_2   RB1


void main(void) {
    
    TRISB = 0x00;
    
    while (1)
    {   
        // PORTB = 0x01;
        LED_1 = 0;
        LED_2 = 1;
        
        __delay_ms(400);
        
        // PORTB = 0x02;
        LED_1 = 1;
        LED_2 = 0;
        
         __delay_ms(400);
    }
    
    return;
}
