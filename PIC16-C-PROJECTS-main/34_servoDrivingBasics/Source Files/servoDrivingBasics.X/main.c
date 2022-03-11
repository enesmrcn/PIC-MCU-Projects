/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 27, 2020, 7:05 PM
 */


#define _XTAL_FREQ  4000000

#include "configuration.h"
#include <stdint.h>

void __interrupt() myIntHandler();

uint8_t dutyControl = 0;   // controls the duty duration

void main(void) {
    
    GIE = 1;
    RBIE = 1;
    
    TRISB = 0b00110000;
    
    
    while (1)
    {
        switch (dutyControl)
        {
            case 1 : RB0 = 1; __delay_ms(1); RB0 = 0; __delay_ms(19); break;
            case 2 : RB0 = 1; __delay_ms(1.1); RB0 = 0; __delay_ms(18.9); break;
            case 3 : RB0 = 1; __delay_ms(1.2); RB0 = 0; __delay_ms(18.8); break;
            case 4 : RB0 = 1; __delay_ms(1.3); RB0 = 0; __delay_ms(18.7); break;
            case 5 : RB0 = 1; __delay_ms(1.4); RB0 = 0; __delay_ms(18.6); break;
            case 6 : RB0 = 1; __delay_ms(1.5); RB0 = 0; __delay_ms(18.5); break;
            case 7 : RB0 = 1; __delay_ms(1.6); RB0 = 0; __delay_ms(18.4); break;
            case 8 : RB0 = 1; __delay_ms(1.7); RB0 = 0; __delay_ms(18.3); break;
            case 9 : RB0 = 1; __delay_ms(1.8); RB0 = 0; __delay_ms(18.2); break;
            case 10 : RB0 = 1; __delay_ms(1.9); RB0 = 0; __delay_ms(18.1); break;
            case 11 : RB0 = 1; __delay_ms(2); RB0 = 0; __delay_ms(18); break;
        }
    }
    
    return;
}

void __interrupt() myIntHandler()
{
    if (INTCONbits.RBIF)
    {
        if (RB4)
        {
            if (dutyControl != 11)
            dutyControl+=1;
        }
        else if (RB5)
        {
            if (dutyControl != 0)
            dutyControl-=1;
        }
        
        RBIF = 0;
    }
}
