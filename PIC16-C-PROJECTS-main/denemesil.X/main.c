/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on December 27, 2020, 1:46 PM
 */



#define _XTAL_FREQ  4000000

#include "config.h"
#include <stdint.h>
#include <stdbool.h>

void __interrupt() myIntHandler();
void servoLeft(void);   //  1ms high, 19ms low, periodic signal
void servoRight(void);  //  2ms high, 18ms low, periodic signal
void servoMiddle(void);   //  1.5ms high, 17.5ms low, periodic signal

void main(void) {
    
    PORTC = 1;
    PORTB = 0;  // Button on RB<4:6>
    TRISB = 0b01110000;
    TRISC = 0;
    
    GIE = 1;
    PEIE = 1;
    
    INTCONbits.RBIF = 0;    //  Clear the RB0 flag
    INTCONbits.RBIE = 1;    //  Enable RBO interrupt requests
    
    servoMiddle();  //  Set duty cycle and period of the pwm signal
    
    // TMR2 Postscale 1:7
    TOUTPS3 = 0;
    TOUTPS2 = 1;
    TOUTPS1 = 1;
    TOUTPS0 = 1;
    
    // TMR2 Prescale 1:16
    T2CKPS1 = 1;
    T2CKPS0 = 1;
    
    // PWM Mode
    CCP1M3 = 1;
    CCP1M2 = 1;
           
    TMR2ON = 1;  //  Start TMR2
    
    while (true)
    {
        //  nothing to do . . .
    }
    
    return;
}


void __interrupt() myIntHandler()
{
    
    if (INTCONbits.RBIF)
    {
        if (RB6)
            servoLeft();
        else if (RB5)
            servoMiddle();
        else if (RB4)
            servoRight();
        
        
        RBIF = 0;
        
        PORTC ^= 0x01;
    }
}

void servoLeft(void)   //  1ms high, 19ms low, periodic signal
{
    PR2 = 199;
    CCPR1L = 0;
    CCP1CONbits.CCP1X = 1;
    CCP1CONbits.CCP1Y = 0;
}
void servoRight(void)  //  2ms high, 18ms low, periodic signal
{
    PR2 = 199;
    CCPR1L = 18;
    CCP1CONbits.CCP1X = 0;
    CCP1CONbits.CCP1Y = 0;
}
void servoMiddle(void)   //  1.5ms high, 17.5ms low, periodic signal
{
    PR2 = 199;
    CCPR1L = 3;
    CCP1CONbits.CCP1X = 1;
    CCP1CONbits.CCP1Y = 0;
}