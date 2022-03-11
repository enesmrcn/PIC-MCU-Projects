/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 24, 2020, 2:44 PM
 */

//  RC2 deki buton basilma suresini portB deki ledlerde gosterir
// Buton topraga baglidir. Capture modulu rising edge bekler. Butona basilinca 
//  rising-edge ile tetiklenen capture modulu timer1'i baslatir. Ardindan mode
//  degistirerek falling-edge icin bekler. Butondan el cekince falling-edge ile 
//  tetiklenen capture modulu timer1 modulunu durdurur ve gecen zamani alip
//  portb ledlerine basar. Ardindan tekrar rising-edge modune alip kendini bekler.

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

uint16_t counter = 0;   //  counter for timing
uint8_t time = 0;       //  the total time passed until the signal captured

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
            PORTB = time;
            PIE1bits.CCP1IE = 0;    //  for secure mode changing
            setCaptureRising();    //  set capture module for falling-edge
            
            
            counter = 0;
            time = 0;
            
        
        }
    }
    
    if (TMR1IF)
    {
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

void setCaptureRising()
{   
    // Capture mode, every rising edge
    CCP1CONbits.CCP1M3 = 0;
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M0 = 1;
    
    PIR1bits.CCP1IF = 0;    // Clear the flag   (necessary)
    
    PIE1bits.CCP1IE = 1;        //  Enable ccp module
    
}

void setCaptureFalling()
{
    // Capture mode, every falling edge
    CCP1CONbits.CCP1M3 = 0;
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M0 = 0;
    
    PIR1bits.CCP1IF = 0;    // Clear the flag   (necessary)
    
    PIE1bits.CCP1IE = 1;        //  Enable ccp module
    
}