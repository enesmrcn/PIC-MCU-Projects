/*
 * File:   main.c
 * Author: enes
 *
 * Created on 06 October 2021, 19:43
 */


#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 1000000

void __interrupt() high_isr(void)
{
    
    INTCONbits.GIEH = 0;
    
    if (INTCONbits.INT0IF == 1)
    {
        LATBbits.LATB7 = ~LATBbits.LATB7;
        INTCONbits.INT0IF = 0;
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

void main(void){
    
    // Initializing PORTS
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    
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
    
    // Initialize INT1 feature
    INTCON3bits.INT1F = 0;      //  Initialise INT0 interrupt flag
    INTCON2bits.INTEDG1 = 1;    //  Rising edge
    INTCON3bits.INT1P = 0;      //  Low level priority
    INTCON3bits.INT1E = 1;      //  Enable INT1 feature
    
    
    
    while (1)
    {
        
    }
    
    
    return;
}