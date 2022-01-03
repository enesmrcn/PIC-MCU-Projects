 /*********************************************************************
 *
 *      segment7DrivingTransistor
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
 *     We drive common cathode 7-segment display connected to
 *     RB0~RB6 with an npn-transistor. Each number will be displayed 
 *     every second. The transistor on RA0 is used to protect the mcu       
 *     from high current that 7-segment might consume.             
 * 
 * Purpose :	driving common cathode 7-segment displayer
 * 
 **********************************************************************
 * 
 * Note :
 *  nothing...
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
    PORTA = 1;
    
    while (true)
    {
        int8_t i = 0;
        for(; i<10; i++)
        {
            PORTB = ledArray[i];
            __delay_ms(1000);
        }
    }
    
    return;
}
