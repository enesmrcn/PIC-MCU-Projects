/*
 * File:   main.c
 * Author: enes
 *
 * Created on 06 October 2021, 19:43
 */


#include <xc.h>
#include "config.h"
#include <stdint.h>

#define _XTAL_FREQ 8000000

void __interrupt() high_isr(void);
void __interrupt(low_priority) low_isr(void);

uint8_t counter = 0;

void main(void){
    
    // Set Internal Oscillator Block to 8MHz
    OSCCONbits.IRCF = 0x07;     //  8MHz clock freq
    OSCCONbits.SCS = 0x03;      //  Internal oscillator
    
    // If the oscillator is not stable, wait until it become
    while (OSCCONbits.IOFS == 1); 
    
    // Initializing PORTS
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    
    LATDbits.LATD5 = 0;
    LATDbits.LATD6 = 0;
    LATDbits.LATD7 = 0;
    
    // Initialize global interrupts
    RCONbits.IPEN = 1;          //  Interrupt priority enabled
    INTCONbits.GIEL = 1;        //  Low level interrupts are enabled
    INTCONbits.GIEH = 1;        //  High level interrupts are enabled
    
    // Initialize INT0 feature
    INTCONbits.INT0IF = 0;      //  Initialise INT0 interrupt flag
    INTCON2bits.INTEDG0 = 1;    //  Rising edge
    INTCONbits.INT0IE = 1;      //  INT0 module enabled
    
    // Initialize IN1 feature
    INTCON3bits.INT1F = 0;      //  Initialise INT0 interrupt flag
    INTCON2bits.INTEDG1 = 1;    //  Rising edge
    INTCON3bits.INT1P = 0;      //  Low level priority
    INTCON3bits.INT1E = 1;      //  Enable INT1 feature
    
    //  Initialize TMR0 module
    T0CONbits.TMR0ON = 0;       //  Stops Timer0
    //INTCON2bits.TMR0IP = 1;   //  TMR0 is set for high priority level
    TMR0 = 6;                   //  Load decimal 6 to gather 1ms count
    T0CONbits.T08BIT = 1;       //  8-bit counter
    T0CONbits.T0CS = 0;         //  Clock source is Instruction Cycle
    T0CONbits.PSA = 0;          //  Prescaler is assigned
    T0CONbits.T0PS = 2;         //  1:8
    INTCONbits.T0IE = 1;        //  TMR0 interrupt is enabled
    T0CONbits.TMR0ON = 1;       //  Enable the TMR0 first for configurating it
    
    while (1)
    {
        
    }
    
    return;
}
void __interrupt() high_isr(void)
{
    
    INTCONbits.GIEH = 0;
    
    if (INTCONbits.INT0IF == 1)
    {
        LATBbits.LATB7 = ~LATBbits.LATB7;
        INTCONbits.INT0IF = 0;
    }
    
    if (INTCONbits.T0IF == 1)
    {
        counter++;
        
        if (counter == 250)
        {
            counter = 0;
            
            LATBbits.LATB5 = ~LATBbits.LATB5;
            
            TMR0 = 6;
        }
        
        INTCONbits.T0IF = 0;
    }
    
    INTCONbits.GIEH = 1;
    
    return;
}

void __interrupt(low_priority) low_isr(void)
{
    
    INTCONbits.GIEL = 0;
    
    if (INTCON3bits.INT1IF == 1)
    {
        LATBbits.LATB6 = ~LATBbits.LATB6;
        INTCON3bits.INT1IF = 0;
    }
    
    INTCONbits.GIEL = 1;
    
    
    return;
}