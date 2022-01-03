 /*********************************************************************
 *
 *      Timer-1 Exercise
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    "configuration.h"  <stdint.h>    <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC18LF46J53
 *
 * Complier:        MPLAB XC8
 *                  MPLAB X IDE v5.40
 * Author:          Enes MERCAN
 * 
 * Created on:      Sept, 2021
 * 
 * Platform:        PIC18LF46J53
 *
 *********************************************************************
 *
 * Software License Agreement
 *  
 *   "THE KEBAB-WARE LICENSE" (Revision 42):
 * <enesmercan1453@gmail.com> wrote this file.  As long as you retain this 
 * notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff worth it, you can buy me a Turkish Kebab in return.
 *						- Enes Mercan
 *
 *********************************************************************
 * 
 * In this program: 
 *             There are 8 LEDs are connected through RD0~RD7
 *            1 LED is at RC0
 *             Using Timer-1 module as counter (16-bit), we will count
 *             from 0x00 to 0xFF with the help of Timer-1 module using
 *             that 8 of LED array. The counting period is 1Hz. (Once in second)
  *             Also every second, the LED at RC0 will turn on/off
 *              
 * 
 * Purpose :	Learning to use Timer-1 module
 *              
 *
 **********************************************************************/

#ifndef __XC_H_
#include <xc.h>
#endif /* __XC_H_ */

#define _XTAL_FREQ  16000000

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

void runTimer(void);
void stopTimer(void);
void timerConfig(void);
void __interrupt() myInterruptHandler();

uint16_t counter = 0;
uint8_t led = 0;

void main(void) {
   
    LATD = 0x00;
    PORTD = 0x00;
    
    LATC = 0x00;
    PORTC = 0x00;
    
    TRISD = 0x00;
    TRISC &= ~(0x01);
    
    timerConfig();
    runTimer();
    
   // LATD = 0xFF;
    
    while (true)
    {
        LATC ^= 0x01;
        __delay_ms(1000);
        
    }
    
    
    return;
}


void __interrupt() myInterruptHandler()
{
    
    if (PIR1bits.TMR1IF == 1)
    {
        counter++;
        PIR1bits.TMR1IF = 0;
        
        if (counter == 61)
        {
            counter = 0;
            led++;
            
            if (led == 0xFF)
                led = 0x00;
            
            LATD = led;
        }
    }
            
}


void runTimer(void)
{
    T1CONbits.TMR1ON = 1;   //  1 = Enables Timer1
    
}

void stopTimer(void)
{
    T1CONbits.TMR1ON = 0;   //  0 = Disables Timer1
}

void timerConfig(void)
{
    // Note : The prescaler is only cleared on writes to TMR1L
    stopTimer();            //  Stop timer1 for initial setup
    PIR1bits.TMR1IF = 0;     //  Clear the Timer1 flag
    T1CONbits.TMR1CS1 = 0;  //  00 = Timer1 clock source is the instruction clock (FOSC/4)
    T1CONbits.TMR1CS0 = 0;  //  00 = Timer1 clock source is the instruction clock (FOSC/4)
    
    //TMR1H = 0;
    //TMR1L = 0;
    
    T1CONbits.T1CKPS1 = 0;  //  Timer1 Input Clock Prescale Select bits
    T1CONbits.T1CKPS0 = 0;  //  Timer1 Input Clock Prescale Select bits
    T1CONbits.T1OSCEN = 0;  //  0 = Timer1 crystal driver is off
    T1CONbits.RD16 = 1;     //  1 = Enables register read/write of Timer1 in one 16-bit operation
    
    // Enable interrupts for Timer-1
    INTCONbits.GIE = 1;         //  1 = Enables all unmasked interrupts
    INTCONbits.PEIE_GIEL = 1;   //  1 = Enables all unmasked peripheral interrupts
    PIE1bits.TMR1IE = 1;        //  1 = Enables the TMR1 overflow interrupt
    
    
}