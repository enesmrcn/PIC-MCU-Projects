 /*********************************************************************
 *
 *      segment7Counter
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <configuration.h>  <stdbool.h>   <xc.h>  <stdint.h>
 *                  
 *                  
 * Processor:       PIC32MX
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Author:          Enes MERCAN (Embedded Software Developer)
 * 
 * Created on:      DEC, 2020
 * 
 * Platform:        PIC16F84A
 *
 *********************************************************************
 *
 * Software License Agreement
 *  
 *   "THE KEBAB-WARE LICENSE" (Revision 42):
 * <enesmercan1453@gmail.com> wrote this file.  As long as you retain this 
 * notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff is worth it, you can buy me a Turkish Kebab in return.
 *						- Enes Mercan
 *
 *********************************************************************
 * 
 * In this program: 
 *              
 *     Two independent 7-segment display connected on RB0~RB6.
 *     Two transistors on RA0 and RA1 will control the each individual
 *     displays. Counter is going to count from 1 to 99, and it will
 *     be shown on the displays
 * 
 * Purpose :	driving common cathode 7-segment displayer
 * 
 **********************************************************************
 * 
 * Note :
 *  
 *
 *  
 **********************************************************************/


#ifndef __CONFIGURATION_H__
#include <xc.h>
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)
#endif /* __CONFIGURATION_H__ */


#define _XTAL_FREQ  4000000

#include "configuration.h"
#include <stdint.h>
#include <stdbool.h>

// each array member (below) holds the code for each number...
// ...will be shown at 7-segment displayer
uint8_t ledArray[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 
                                0x6D, 0x7C, 0x07, 0x7F, 0x6F};

void main(void) {
    
    TRISB = 0x00;   //  (display connected here)
    PORTB = 0;
    
    TRISA = 0x00;   // RA0 is output (transistor on it)
    PORTA = 0x03;   // Turn off displays in the beginning
    
    __delay_ms(10); // delay little bit
    
    while (true)
    {
        RA0 = 1;    // First display is off
        RA1 = 1;    // Second display is off
        __delay_ms(1000);   // delay little bit more :)
        
        for (int8_t i = 0; i<10; i++)
        {
            for (int8_t j = 0; j<10; j++)
            {
                for (int8_t k = 0; k<20; k++)
                {
                    
                    RA0 = 0;    // First display is on
                    PORTB = ledArray[i];
                    __delay_ms(7);
                    RA0 = 1;    // First display is off
                    
                    
                    RA1 = 0;    // Second display is on
                    PORTB = ledArray[j];
                    __delay_ms(7);
                    RA1 = 1;    // Second display is off
                            
                }
            }
        }
        
    }
    
    return;
}
