 /*********************************************************************
 *
 *      PORTB Interrupt Tutorial (RB4/RB5/RB6/RB7)
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <config.h>   <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC32MX
 *
 * Complier:        MPLAB IDE
 *                  
 * Author:          Enes MERCAN (Embedded Software Developer)
 * 
 * Created on:      Sept, 2020
 * 
 * Platform:        PIC16FXXX
 *
 * *********************************************************************
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
 *              While LED on RB1 si continuously blinking
 *              buttons on RB4~RB7 will drive LEDs on RA0~RA7...
 *              ...using portb interrupt feature! 
 * 
 * Purpose :	using portB external interrupt
 * 
 *********************************************************************/

#define _XTAL_FREQ 10000000    // define clock frequency


#include "config.h" // include my header file


// When interrupts occur, the program flow jumps here immediately
void __interrupt() myInterruptHandler(void);  // the prototype of the function

void main(void) {
    
    PORTB = 0x00;           //  Clear initial values
    PORTA = 0x00;           //  Clear initial values
    TRISB = 0xF0;           //  RB7~RB4 are inputs  1111 0000 = F 0
    TRISA = 0x00;           //  RA0~RA3 are inputs
    
    // to be able to use RA0~RA3 as input pins...
    CMCON |= (1 << CM0) | (1 << CM1) | (1 << CM2);      
    
    // Configurations below for PortB interrupt
    INTCONbits.GIE = 1;
    INTCONbits.RBIF = 0;
    INTCONbits.RBIE = 1;
    
    
    // repeats forever...
    while (1)
    {
        // Toggle RB1 in every 500ms
        PORTBbits.RB1 = ~(PORTBbits.RB1);
        __delay_ms(500);
    }
    
    return;
}


// Interrupt sub-program below
void __interrupt() myInterruptHandler(void)   
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

    
    // We don't put here "return"
}