 /*********************************************************************
 *
 *      Timer-2 as Counter Exercise
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
 * Created on:      Oct, 2021
 * 
 * Platform:        Windows 10
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
 *             There are 8 LEDs are connected through RD0~RD7 1 LED is at RC0
 *
 *             Using Timer-2 module as counter (8-bit), will count
 *             from 0x00 to 0xFF with the help of Timer-1 module using
 *             that 8 of LED array. The timer module saves its counting number
 *             into TMR2 register. And it constantly checks if there is any match
 *             with the PR2 that is also writable by us. When the match occurs,
 *             the module rise the flag. We will use that feature.
 * 
 *             The value of TMR2 is compared to that
 *             of the Period register, PR2, on each clock cycle. When
 *             the two values match, the comparator generates a
 *             match signal as the timer output. This signal also resets
 *             the value of TMR2 to 00h on the next cycle and drives
 *             the output counter/postscaler 
 *              
 *             With this knowledge, we will operate the LEDs for binary counting
 *             with the period of 2Hz (500ms delay)
 *              
 *             I will configure the module using 1:16 prescaler and 1:16 
 *             postscaler. Also, it will start counting from 30 to 158 
 *             This is my preference to make it different a little bit
 * 
 *             All right then! Keep your timers sharp
 * 
 * Purpose :	Learning to use Timer-1 module
 *              
 *
 **********************************************************************/

#ifndef __XC_H_
#include <xc.h>
#endif /* __XC_H_ */

#define     _XTAL_FREQ           16000000
#define     TMR2_FLAG            PIR1bits.TMR2IF

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

void runTimer(void);
void stopTimer(void);
void timerConfig(void);
void __interrupt() myInterruptHandler();

uint8_t counter = 0;
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
        __delay_ms(500);   
    }
    
    
    return;
}


void __interrupt() myInterruptHandler()
{
    
    if (TMR2_FLAG == 1)
    {
        counter++;
        TMR2_FLAG = 0;
        
        TMR2 = 0x1E;            //  Configure to start from 30 (decimal)
        //PR2 = 0x9E;             //  Configure to start at 158 (decimal)
        
        if (counter == 58)
        {
            counter = 0;
            
            if (led == 0xFF)
                led = 0x00;
            
            led++;
            
            LATD = led;
        }
    }
            
}


void runTimer(void)
{
    T2CONbits.TMR2ON = 1;   //  0 = Timer2 is on
}

void stopTimer(void)
{
    T2CONbits.TMR2ON = 0;   //  0 = Timer2 is off
}

void timerConfig(void)
{
    
    stopTimer();            //  Stop timer1 for initial setup,
    
    // Writing on TMR2 and/or T2CON clears the prescaler/postscaler registers
    TMR2 = 0x1E;            //  Configure to start from 30 (decimal)
    PR2 = 0x9E;             //  Configure to start at 158 (decimal)
    
    T2CON |= 0x78;          //  1111 = 1:16 Postscale
    T2CON |= 0x02;          //  10 = Prescaler is 16
    
    // Enable interrupts for Timer-2
    TMR2_FLAG = 0;        //  1 = TMR2 to PR2 match occurred (must be cleared in software)
    INTCONbits.GIE = 1;         //  1 = Enables all unmasked interrupts
    INTCONbits.PEIE_GIEL = 1;   //  1 = Enables all unmasked peripheral interrupts
    PIE1bits.TMR2IE = 1;        //  1 = Enables the TMR2 to PR2 match interrupt
    
}