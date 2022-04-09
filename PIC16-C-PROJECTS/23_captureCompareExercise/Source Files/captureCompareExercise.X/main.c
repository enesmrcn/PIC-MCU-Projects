/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 24, 2020, 2:44 PM
 */


#define _XTAL_FREQ  4000000

#include "config.h"
#include <stdint.h>
#include <stdbool.h>

void __interrupt() myIntHandler();
void setTimer(void);
void runTimer(void);
void stopTimer(void);
void setCaptureRising(void);
void setCaptureFalling(void);
void setCompare(void);

uint16_t counter = 0;   //  counter for timing
uint8_t time = 0;       //  the total time passed until the signal captured
uint8_t flag = 1;       // switch between compare and capture mode

void main(void) {
    
    TRISB = 0;
    PORTB = 0;
    TRISC = 0x04;   // Button on RC2
    
    INTCONbits.GIE = 1;     //  Enable global interrupts
    INTCONbits.PEIE = 1;    //  Enable peripheral interrupts
    
    setTimer();
    setCaptureRising();
    
    
    while (true)
    {
        // nothing to do . . .
    }
    
    return;
}


void __interrupt() myIntHandler()
{
    if (CCP1IF)
    {
        CCP1IF = 0; 
        
        if (flag == 1)
        {
            
            if (RC2)    //  if RC2 is high... (button down)
            {
                runTimer(); // Start timing

                PIE1bits.CCP1IE = 0;    //  for secure mode changing
                setCaptureFalling();    //  set capture module for falling-edge

            }

            else if (RC2 == 0)  // if button is released
            {
                time = (65536 * counter + CCPR1) / 1000000; // in seconds

                if (time >= 255)
                {
                    time = 0;
                    counter = 0;
                }

                stopTimer();
                PORTB |= 0x01;          //  Turn on RB0

                runTimer();             // Start timing over again
                PIE1bits.CCP1IE = 0;    //  for secure mode changing
                flag = 2;
                setCompare();

            }
            
        }
        
        else if (flag == 2)
        {
            if (counter == 0)
            {
                PORTB &= ~(0x01);          //  Turn off RB0
                PORTB |= 0xf0;
                
                PIE1bits.CCP1IE = 0;    //  for secure mode changing
                setCaptureRising();     //  set capture module for falling-edge
                counter = flag = 1;
            }
            
        }
        
    }
    
    if (TMR1IF)
    {
        if (flag == 1)
            counter++;
        
        
        TMR1IF = 0; // Clear the flag for next use
    }
    
}

void setTimer()
{
    
    PIE1bits.TMR1IE = 1;    //  Enable TIMER1 interrupts
    
    //  1 = Do not synchronize external clock input
    T1CONbits.TMR1CS = 0;   //  Timer1 Clock Source Select bit
    
    // 00 = 1:1 Prescale value
    T1CONbits.T1CKPS0 = 0;  //  Timer1 Input Clock Prescale Select bits
    T1CONbits.T1CKPS1 = 0;
    
}

void runTimer(void)
{
    TMR1IF = 0;             //  Make sure it's clear
    T1CONbits.TMR1ON = 1;   //  Start timer1 module
    TMR1 = 0;               //  Start counting from 0
}

void stopTimer(void)
{
    T1CONbits.TMR1ON = 0;   //  Stop timer1 module
    TMR1 = 0;               //  Start counting from 0
}

void setCaptureRising(void)
{   
    // Capture mode, every rising edge
    CCP1CONbits.CCP1M3 = 0;
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M0 = 1;
    
    PIR1bits.CCP1IF = 0;    // Clear the flag   (necessary)
    
    PIE1bits.CCP1IE = 1;        //  Enable ccp module
    
}

void setCaptureFalling(void)
{
    // Capture mode, every falling edge
    CCP1CONbits.CCP1M3 = 0;
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M0 = 0;
    
    PIR1bits.CCP1IF = 0;    // Clear the flag   (necessary)
    
    PIE1bits.CCP1IE = 1;        //  Enable ccp module
    
}

void setCompare(void)
{
    // Compare mode, generate software interrupt on match
    // (CCP1IF bit is set, CCP1 pin is unaffected)
    CCP1CONbits.CCP1M3 = 1;
    CCP1CONbits.CCP1M2 = 0;
    CCP1CONbits.CCP1M1 = 1;
    CCP1CONbits.CCP1M0 = 0;
    
    PIR1bits.CCP1IF = 0;    // Clear the flag   (necessary)
    CCPR1 = 65535;
    PIE1bits.CCP1IE = 1;        //  Enable ccp module
}