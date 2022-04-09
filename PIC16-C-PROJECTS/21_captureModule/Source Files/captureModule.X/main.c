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
void setCaptureModule(void);

uint16_t counter = 0;   //  counter for timing
uint8_t time = 0;       //  the total time passed until the signal captured

void main(void) {
    
    TRISB = 0;  //  All output
    PORTB = 0;  //  Clear the initial values
    
    TRISC = 0x04;   //  Button on RC2
    
    setTimer();
    setCaptureModule();
    
    while (true)
    {
        //  nothing to do here . . . 
    }
    
    return;
}

void __interrupt() myInterruptHandler()
{
    if (PIR1bits.CCP1IF)
    {
        time = (65536 * counter + CCPR1) / 1000000; // in seconds
        
        if (time >= 255)
        {
            time = 0;
            counter = 0;
        }
        
        PORTB = time;
        counter = 0;
        time = 0;
        
        CCP1IF = 0; //  Reset the flag
        
    }
    
    if (PIR1bits.TMR1IF)
    {
        counter++;
       
    }
    
    TMR1IF = 0; // Reset the flag
    TMR1 = 0;   // Reset timer1
    
}

void setTimer()
{
    INTCONbits.GIE = 1;     //  Enable global interrutps
    INTCONbits.PEIE = 1;    //  Enable peripheral interrupts
    PIE1bits.TMR1IE = 1;    //  Enable TIMER1 module
    T1CONbits.TMR1CS = 0;   //  Timer mode, not counter
    
    //T1CONbits.T1CKPS = 0;   //  Postscale 1/1
    T1CONbits.T1CKPS0 = 0;
    T1CONbits.T1CKPS1 = 0;
    
    T1CONbits.TMR1ON = 1;   //  Turn on timer1 module
    
    TMR1 = 0;               //  Start counting from 0 to 65536
    
}

void setCaptureModule()
{
    PIR1bits.CCP1IF = 0;    // Clear the flag (not necessarily)
    
    //CCP1CONbits.CCP1M = 0b1010; //  Capture mode...Raising-edge
    CCP1CONbits.CCP1M3 = 0;
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M0 = 1;
    
    PIE1bits.CCP1IE = 1;        //  Enable ccp module
    
}