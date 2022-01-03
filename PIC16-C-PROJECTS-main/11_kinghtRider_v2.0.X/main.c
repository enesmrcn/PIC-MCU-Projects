/*
 * File:        main.c
 * Author:      Enes Mercan
 *
 * Created on   Sept, 2020
 * 
 * Scenario :   leds (rb0~rb7) will shift to left 6 times. Then, will shift
 *              to right 6 times. 
 *              Control the event with the button on RA0
 * 
 * Purpose :	PRACTICE
 * 
 */

#include "config.h"
#include <stdint.h>
#include <stdbool.h>

#define _XTAL_FREQ 10000000

const uint8_t led[8] = {1, 2, 4, 8, 16, 32, 64, 128};
const uint8_t ON_TIME = 35;
const uint8_t OFF_TIME = 10;

void main(void) {
    
    PORTB = 0;
    TRISB = 0;
    
    int8_t i = 0;    // counts for 6 times repeating
    
    while (true)
    {
        
        if ( RA0 == 0 )
        {
            i = 0;   // reset the counter
            while (i<=6)    // go RB0 to RB7 6 times
            {
                for (int8_t j = 0; i<8; j++)        // goes left to right
                {
                    PORTB = led[j];
                    __delay_ms(ON_TIME);

                    PORTB = 0;
                    __delay_ms(OFF_TIME);
                }

                i++;
                __delay_ms(10);
            }


            __delay_ms(100);    // put some time delay


            i = 0;   // reset the counter
            while (i<=6)
            {
                for (int8_t j = 7; j<=0; j--)
                {

                    PORTB = led[j];
                    __delay_ms(ON_TIME);

                    PORTB = led[j];
                    __delay_ms(OFF_TIME);
                }
                i++;
                __delay_ms(10);
            }

            __delay_ms(1000);     // put some time delay
        }
    }
    return;
}
