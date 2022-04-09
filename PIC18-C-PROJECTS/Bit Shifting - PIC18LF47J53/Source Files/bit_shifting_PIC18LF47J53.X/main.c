 /*********************************************************************
 *
 *      Bit Shifting Exercise
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    "configuration.h"  <stdint.h>    <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC18LF46J53
 *
 * Complier:        MPLAB XC8
 *                  MPLAB X IDE v5.40
 * Author:          Enes MERCAN
 * 
 * Created on:      Sept, 2021
 * 
 * Platform:        PIC18LF46J53
 *
 *********************************************************************
 *
 * Software License Agreement
 *  
 *   "THE KEBAB-WARE LICENSE" (Revision 42):
 * <enesmercan1453@gmail.com> wrote this file.  As long as you retain this 
 * notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff worth it, you can buy me a Turkish Kebab in return.
 *						- Enes Mercan
 *
 *********************************************************************
 * 
 * In this program: 
 *              from RD0 to RD7, there are red leds connected to the pins
 *              at start, the RD0 LED will be turned on. Then you will
 *             shift the from left to right and from right to left the LEDs
 *             with some delay
 * 
 *             LATD << 3    shits three times to left
 *             LATD >> 2    shifts two times to right
 * 
 * Purpose :	understanding bit shifting in embedded systems
 *              
 *
 **********************************************************************/

#ifndef __XC_H_
#include <xc.h>
#endif /* __XC_H_ */

#define _XTAL_FREQ  16000000
#define DELAY       100

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

uint8_t i = 0;

void main(void) {
    
    
    LATD = 0x00;    //  
    PORTD = 0x00;
    
    TRISD = 0x00;
    LATD = 0x01;
    
    while (true)
    {
        LATD = 0x01;
        
        for (i = 0; i < 8; i++)
        {
            __delay_ms(DELAY);
            LATD = LATD << 1;
        }
        
        LATD = 0x80;
                
        for (i=9; i > 1; i--)
        {
            
            __delay_ms(DELAY);
            LATD = LATD >> 1;
            
        }
        
    }
    
    return;
}
