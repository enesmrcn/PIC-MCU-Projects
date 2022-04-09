 /*********************************************************************
 *
 *      timer0 Introduction
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


#ifndef __CONFIGURATION_H__
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)
#include <xc.h>
#endif  /* __CONFIGURATION_H__ */

#define _XTAL_FREQ  4000000

#include "configuration.h"
#include <stdint.h>
#include <stdbool.h>

void __interrupt() myInterruptHandler();
void setupTimer(void);

int_fast8_t counter;



void main(void) {
    
    setupTimer();
    TRISB = 0;
    PORTB = 0;
    counter = 0;
    
    while (true)
    {
        //nothing here...
        
    }
    
    return;
}


void __interrupt() myInterruptHandler()
{
    if (INTCONbits.T0IF)
    {
        counter++;
        
        if (counter == 10)
        {
            counter = 0;
            PORTB ^= 0x01;
        }
        
        TMR0 = 60;
        T0IF = 0;
    }
    
}

void setupTimer()
{
    INTCONbits.GIE = 1;         //  Enable global interrupt requests
    INTCONbits.T0IF = 0;        //  Clear timer0 flag (not necessarily)
    INTCONbits.T0IE = 1;        //  Enable Timer0 module
    
    OPTION_REGbits.T0CS = 0;    //  Internal clock source
    OPTION_REGbits.PSA = 0;     //  Prescaler assigned to timer0
    OPTION_REGbits.T0SE = 0;    //  Source edge : low-to-high
    OPTION_REG |= 0b00000111;   //  Prescaler is 1/256
    // OPTION_REG = 0x07;       // Simply you can do all that at once.
    
    TMR0 = 195;
}