/*
 * File:   main.c
 * Author: enes
 *
 * Created on 30 September 2021, 19:26
 */

#ifndef __XC_H_
#include <xc.h>
#endif /* __XC_H_ */

#define _XTAL_FREQ  16000000
#define DELAY       800 

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

const uint8_t matris[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
volatile uint8_t i = 0;
        

void main(void) {
    
    TRISD = 0x00;   //  Initialize PORTC by clearing output data latches
    PORTD = 0x00;   //  Initialize PORTC by clearing output data latches
    
    while (true)
    {
        
        for (i = 0; i < 10; i++)
        {
            LATD = matris[i];
            __delay_ms(DELAY);
        }
        
    }
    
    return;
}
