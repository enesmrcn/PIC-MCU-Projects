 /*********************************************************************
 *
 *      timer2 Introduction
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
 * Created on:      DEC, 2020
 * 
 * Platform:        PIC16F84A
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
 *              
 *              
 * 
 * Purpose :	
 * 
 *********************************************************************/


#define _XTAL_FREQ 4000000

#include "configuration.h"
#include <stdint.h>

void __interrupt() myInterruptHandler();
void setTimer(void);

int_fast8_t counter = 1;

void main(void) {
    
    TRISB = 0;
    PORTB = 0;
    
    setTimer();
    
    while (1)
    {
        // nothing to do here . . .
    }
    
    return;
}



void __interrupt() myInterruptHandler()
{
    if (TMR2IF)
    {
        counter++;
        if (counter == 10)
        {
            counter = 0;
            PORTB ^= 0x01;
        }
        
        TMR2IF = 0;
        TMR2 = 0;
        PR2 = 255;
    }
}

void setTimer(void)
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.TMR2IE = 1;    //  Enable TMR2 module
    
    // prescle : 1/16
    T2CKPS0 = 1;
    T2CKPS1 = 1;
    
    // postscale : 1/16
    TOUTPS0 = 1;
    TOUTPS1 = 1;
    TOUTPS2 = 1;
    TOUTPS3 = 1;
    
    TMR2 = 0;
    PR2 = 255;
    
    TMR2ON = 1;     //  Start timing
}