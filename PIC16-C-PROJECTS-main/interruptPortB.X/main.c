/*********************************************************************
 *
 *      interruptPortB
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <stdint.h>    <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       QWEFEWF
 *
 * Complier:        MPLAB XC8
 *                  MPLAB IDE
 * Author:          Enes MERCAN
 * 
 * Created on:      DEC, 2020
 * 
 * Platform:        PIC18F84A
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
 *              
 *              
 *              
 *  
 * Purpose :	
 * 
 **********************************************************************
 * 
 * Note :
 *  nothing...
 * 
 **********************************************************************/


#ifndef __CONFIGURATION_H__
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)
#include <xc.h>
#endif  /* __CONFIGURATION_H__ */


#define _XTAL_FREQ 4000000  // 4MHz external oscillator

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

void __interrupt() myInterruptHnadler();  // the interrupt sub-program prototype
void setupInterrupt(void);


void main(void) {
    
    TRISA = 0;
    TRISB = 0xF0;
    PORTA = 0;
    
    setupInterrupt();
    
    while (true)
    {
        PORTB ^= 0x02;
        __delay_ms(500);
    }
    
    return;
}


void __interrupt() myInterruptHandler()
{
    if (INTCONbits.RBIF)
    {
        INTCONbits.RBIE = 0;        // Disable PortB interrupts
        
        if ( RB4 == 0)
        {
            PORTAbits.RA0 = ~ (PORTAbits.RA0);
        }
        
        if ( RB5 == 0)
        {
            PORTAbits.RA1 = ~ (PORTAbits.RA1);
        }
        
        if ( RB6 == 0)
        {
            PORTAbits.RA2 = ~ (PORTAbits.RA2);
        }
        
        if ( RB7 == 0)
        {
            PORTAbits.RA3 = ~ (PORTAbits.RA3);
        }
        
        
        INTCONbits.RBIF = 0;        // Clear PortB flag to be able to use it again
        INTCONbits.RBIE = 1;        // Enable PortB interrupts
        __delay_ms(1000);
        
    }
    
    RBIF = 0;
    PORTA = 0;
}

void setupInterrupt(void)
{ 
    INTCONbits.GIE = 1;     // Enable global interrupts
    INTCONbits.RBIF = 0;    // Clear the flag for first use (not necessarily)
    INTCONbits.RBIE = 1;    // Enable PortB interrupts
}