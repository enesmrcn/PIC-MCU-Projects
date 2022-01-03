 /*********************************************************************
 *
 *      Timer0 Module Exercise
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    "configuration.h"  <stdint.h>    <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC18F4550A
 *
 * Complier:        MPLAB XC8
 *                  MPLAB X IDE v5.40
 * Author:          Enes MERCAN
 * 
 * Created on:      Sept, 2021
 * 
 * Platform:        PIC18F4550
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
 *              2 LEDs are connected to RA0 and RA1 as OUTPUT
 *              1 Button is connected to RD0 as INPUT
 *
 *              When the button is pushed down, the LED on RA0 will turn on.
 *              When it releases, will turn off back 
 *              Also once every second, the LED on RA1 will turn on/off (1Hz)
 *              We will do that using Timer0 module in timer mode
 *              It will work in 16-bit counter and NO prescaler mode.
 * 
 * Purpose :	learn how to use timer0 module
 *              learning basic needs of interrupts
 *
 **********************************************************************
 * 
 * Note :
 *  When you load into TMR0 something, prescaler rate will be reseted
 *
 *  When timer0 module counts from 0 to 65535, it takes 13.1072ms for 20MHz
 *  speed CPU. To perform 1Hz blinking, we need 1000ms/13.1072ms is 76 turns
 *  to count that period.
 * 
 * 
 **********************************************************************/

#ifndef __XC_H_
#include <xc.h>
#endif /* __XC_H_  */

#define _XTAL_FREQ  20000000
#define DELAY_TIME  100

#include <stdbool.h>
#include <stdint.h>
#include "configuration.h"

void __interrupt() myInterruptHandler(void);       // function signature/prototype
void timer0Setup(void);      // Set timer0 module


uint8_t counter = 0;

void main(void) {
    
     timer0Setup();
    
    /* Initialise I/O Ports */
    LATA = 0;               //  Clear LATA for first start
    TRISA &= ~(0x03);          //  RA0 and RA1 were set as OUTPUT
    CMCON |= 0x07;          //  CM2:CM0 = 111, Comparators Off
    ADCON1 |= 0x0F;         //  Comparator module is disabled
    TRISD |= 0x01;          //  Set RD0 as input
    
    T0CONbits.TMR0ON = 1;   //  1 = Start Timer0
    
    while (true)
    { 
        if (PORTDbits.RD0 == 1)
            LATAbits.LA0 = 1;
        else    
            LATAbits.LA0 = 0;
    }                  
    
    return;
}


void __interrupt() myInterruptHandler(void)
{
    if (INTCONbits.T0IF == 1)
    {
        
        counter++;              //  Increment the counter
        INTCONbits.T0IF = 0;    //  Clear the Timer0 interrupt flag
        
        if (counter  == 76)
        {
            counter = 0;        //  Clear the counter
            LATA ^= 0x02;
        }
        
    }
    
}


void timer0Setup(void)
{
    /* Initialise Timer0 module  */
    T0CONbits.TMR0ON = 0;   //  0 = Stops Timer0
    T0CONbits.T0CS = 0;     //  0 = Internal instruction cycle clock (CLKO)
    T0CONbits.T08BIT = 0;   //  0 = Timer0 is configured as a 16-bit timer/counter
    T0CONbits.PSA = 1;      //  1 = TImer0 prescaler is NOT assigned.
    
    RCONbits.IPEN = 0;      //  0 = Disable priority levels on interrupts
    INTCONbits.GIE = 1;     //  1 = Enables all unmasked interrupts
    INTCONbits.PEIE = 1;    //  1 = Enables all unmasked peripheral interrupts
    INTCONbits.T0IF = 0;    //  0 = The INT0 external interrupt did not occur
    INTCONbits.TMR0IE = 1;  //  1 = Enables the TMR0 overflow interrupt
    
}