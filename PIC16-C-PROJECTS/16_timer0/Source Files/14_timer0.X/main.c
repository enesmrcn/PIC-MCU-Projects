 /*********************************************************************
 *
 *      Timer0 Module Introduction
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <config.h>  <stdint.h>    <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC32MX
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Author:          Enes MERCAN (Embedded Software Developer)
 * 
 * Created on:      Sept, 2020
 * 
 * Platform:        PIC16FXXX
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
 *              2 leds on rb0 and rb3... 
 *              while rb0 blink once every 1 second (using delay)...
 *              rb3 will blink once every 0.5 second using timer0
 *              
 * 
 * Purpose :	learn how to use timer0 module
 * 
 **********************************************************************
 * 
 * Note :
 *  When you load into TMR0 something, prescaler rate will be reseted
 *
 *  When timer0 module counts from 0 to 255, it takes 65.4ms for 4MHz
 *  speed CPU. So, we hall repeat counting about 15 times to gather 500ms 
 *  total. We will hold that in a variable
 **********************************************************************/

#define _XTAL_FREQ 4000000 // 4MHZ clock speed we have

#include "config.h"
#include <stdint.h>
#include <stdbool.h>


void __interrupt() myInterruptHnadler(void);    // function signature/prototype

int8_t counter = 1;

void main(void) {
    
    PORTB = 0;
    TRISB = 0;       // RB0 and RB1 are output
    TMR0 = 0x00;     // start counting with 0 . . .
    OPTION_REG = 0b00000111;    // 1:256 prescaler rate, internal clock source...
    INTCONbits.GIE = 1;
    INTCONbits.T0IE = 1;
    
    while (true)
    {
         PORTB ^= 0x01;         // Toggle RB0
        __delay_ms(2000);
       
    }
    
    return;
}


void __interrupt() myInterruptHnadler(void)
{
    if (T0IF)
    {
        
        counter++;
        
        INTCONbits.T0IF = 0;    // Reset timer0 interrupt flag
        
        if (counter == 16)      // 500ms overed?
        {
            PORTB ^= 0b00001000;
            counter = 0;        // reset counter
        }
        
    }
    
}