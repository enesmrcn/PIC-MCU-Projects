 /*********************************************************************
 *
 *      Timer0 Module Exercise
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <config.h>  <stdint.h>    <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC16F628A
 *
 * Complier:        MPLAB XC8
 *                  MPLAB IDE
 * Author:          Enes MERCAN
 * 
 * Created on:      Sept, 2020
 * 
 * Platform:        PIC16FXXX
 *
 *********************************************************************
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
 *              8 leds on RB0~RB7..  and 1 led on RA0...
 *              RA0 will blink once in every 800ms using delay...
 *              Timer0 will count for 0-800ms...
 *              When every 100ms passed through, one led will turn on...
 *              When 800ms timing done, in the next turn all leds will turn off
 *              back one by one
 *
 * 
 * Purpose :	learn how to use timer0 module
 * 
 **********************************************************************
 * 
 * Note :
 *  When you load into TMR0 something, prescaler rate will be reseted
 *
 *  When timer0 module counts from 0 to 255, it takes 65.4ms for 4MHz
 *  speed CPU. But wee need to count for 50ms for more accurate timing.
 *  When you calculate, you will find that (Fosc=4MHz, 1:256 prescaler) 
 *  counting from 61 to 255 will do the job
 * 
 **********************************************************************/


#define _XTAL_FREQ  4000000

#include    "config.h"
#include    <stdint.h>
#include    <stdbool.h>

void __interrupt() myInterruptHandler(void);

int8_t counter = 0;
bool flag = false;
uint8_t leds[8]={1, 2, 4, 8, 16, 32, 64, 128};

void main(void) {
    
    PORTB = 0;
    PORTA = 0;
    
    TRISB = 0;
    TRISA = 0;
    CMCON = 7;
    
    OPTION_REG = 0b00000111;
    TMR0 = 61;
    INTCONbits.INTF = 0;
    INTCONbits.GIE = 1;
    INTCONbits.T0IE = 1;
    
    
    while (true)
    {
        PORTA ^= 0x01;  // Toggle RA0
        __delay_ms(801);
        
    }
    
    return;
}

void __interrupt() myInterruptHandler(void)
{
    
    if (INTCONbits.T0IF)
    {
        TMR0 = 61;
        
        
        if (flag)
        {
            PORTB ^= leds[counter];
            counter++;
            
            if (counter == 8)
                counter = 0;
        }
            
        flag = !flag;
        INTCONbits.T0IF = 0;
        
    }
        
}