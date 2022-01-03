 /*********************************************************************
 *
 *      CompareModule Introduction
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
 * Platform:        PIC16F877A
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
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h>
#endif  /* __CONFIGURATION_H__ */

#define _XTAL_FREQ  4000000

#include "configuration.h"
#include <stdint.h>
#include <stdbool.h>

void __interrupt() myInterruptHandler();
void setTimer(void);
void setCompareModule(void);


void main(void) {
    
    PORTC = 0;
    TRISC = 1;  //  RC0 is input
    
    setTimer();
    setCompareModule();
    
    while (true)
    {
        // nothing to do here . . .
    }
    
    return;
}


void __interrupt() myInterruptHandler()
{
    if (CCP1IF)
    {
        RC2 = ~RC2;     //  Toggle the LED
        
        CCP1IF = 0;     //  Reset the flag
        
        TMR1 = 1;
    }
    
}

void setTimer(void)
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    //TMR1IE = 1;   //  We do not need actually
    TMR1CS = 1;     //  Internal clock
    T1OSCEN = 1;    //  Oscillator is enabled
    TMR1 = 1;
    TMR1ON = 1;     //  1 = Enables Timer1, 0 = Stops Timer1
    
    
}

void setCompareModule(void)
{
    CCP1M0 = 1;
    CCP1M1 = 1;
    CCP1M2 = 0;
    CCP1M3 = 1;
    
    CCP1IE = 1;
    
    CCPR1 = 5;       //  Start counting from 1 to 5
}