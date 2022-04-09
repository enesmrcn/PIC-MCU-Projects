 /*********************************************************************
 *
 *      timer1 Introduction
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
#include <stdbool.h>

void __interrupt() myInterruptHanlder();
void setupTimer(void);

int_fast8_t counter = 0;

void main(void) {
    
    TRISB = 0;
    PORTB = 0;
    setupTimer();
    TMR1 = 15536;   // counts from 15536 to 65536
    
    while (true)
    {
        // nothing here . . .
    }
    
    return;
}

void __interrupt() myInterruptHanlder() 
{
    if (PIR1bits.TMR1IF)
    {
        counter++;
        if (counter == 20)
        {
            counter = 0;
            PORTB ^= 0x01;  //  Toggle RB0
        }
        
        TMR1 = 15536;
        TMR1IF = 0;
    }
}

void setupTimer()
{
    INTCONbits.GIE = 1;     //  Enable global interrupt requests
    INTCONbits.PEIE = 1;    //  Enable peripheral int. reqs.
    PIE1bits.TMR1IE = 1;    //  Enable TMR1 module
    T1CON &= ~(0x03);       //  Clear first and second bits (prescaler)
    T1CONbits.TMR1CS = 0;   //  Clock source : internal
    T1CONbits.TMR1ON = 1;   //  start module
    
}