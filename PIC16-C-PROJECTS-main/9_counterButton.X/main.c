/*
 * File:   main.c
 * Author: Enes Mercan
 *
 * Created on Sept, 2020
 * 
 * Scenario :   LEDs connected to RB0 ~ RB6
 *              as you push the button on RA0, it will count up one step
 *              as you push the button on RA1, it will count down one step
 *              limits : 0 and 255
 * 
 * Purpose :	just practicing with easy things
 * 
 */


#include "config.h"
#include "stdint.h"

#define _XTAL_FREQ 10000000


void main(void) {
    
    uint8_t counter = 0;
    
    PORTB = 0;
    TRISB = 0;
    
    PORTA = 0;
    TRISA = 0x03;
    CMCON = 0x07;
    
    while (1)
    {
        
        if ( (RA0 == 0) && (counter != 255))
        {
            __delay_ms(30);     // wait for button arc
            
            counter++;
        }
        
        else if ( (RA1 == 0) && (counter != 0))
        {
            __delay_ms(30);     // wait for button arc
            
            counter--;
        }
        
        if (counter > 255)
        {
            __delay_ms(200);
            counter = 100;
            
        }
        PORTB = counter;
        
        __delay_ms(1);
        
    }
    
    return;
}
