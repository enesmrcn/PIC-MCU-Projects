/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 24, 2020, 8:55 PM
 */


#include "config.h"

void main(void) {
    
    PORTB= 0;        //  Clear initial values
    PORTD = 0;       //  Clear initial values
    TRISD = 0;
    TRISB = 0x07;    //  Buttons on RB0, RB1, RB2
    
    while (1)
    {
        if (RB1)          // forward
            PORTD = 5;
        if (RB2)     //  backward
            PORTD = 10;
        if (RB0)     //  stop / brake
            PORTD = 0;
    }
    
    return;
}
