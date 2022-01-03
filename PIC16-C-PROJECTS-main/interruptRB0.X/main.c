 /*********************************************************************
 *
 *      interruptRB0
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <config.h>  <stdint.h>    <stdbool.h>   <xc.h>
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
#include <stdint.h>
#include <stdbool.h>


void __interrupt() myInterruptHnadler();  // the interrupt sub-program prototype
void setupInterrupt(void);


void main(void) {
    
    PORTB = 0;
    PORTA = 0;
    TRISB = 0x01;   // RB0 input, RB1~RB2 output
    TRISA = 0x00;   // RA0 output
    
    setupInterrupt();
    
    PORTBbits.RB1 = 1;  // Turn on RB1
    
    while (true)
    {
        PORTB ^= (0b00000110);   // Toggle RB1 and RB2
        __delay_ms(550);         // once every 550ms
        
    }
    
    return;
}


void __interrupt() myInterruptHnadler()
{
    
    if (INTCONbits.INTF)    // if RB0 interrupt raised...
    {
        PORTA |= 0x01;  // Turn on LED on RA0 to show interrupt
        __delay_ms(1000);
    }
    
    PORTA &= ~(0x01);   // Turn off it back
    INTF = 0;   // Clear the flag for the next use
    
}

void setupInterrupt (void)
{
    INTCONbits.RBIF = 0;        // clear the flag
    OPTION_REGbits.INTEDG = 0;  // falling-edge sensitive
    INTCONbits.GIE = 1;         // enable global interrupt requests
    INTCONbits.INTE = 1;
    
}