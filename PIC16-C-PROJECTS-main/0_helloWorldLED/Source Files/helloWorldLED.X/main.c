 /*********************************************************************
 *
 *      helloWorldLED
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <configuration.h>  <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC32MX
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Author:          Enes MERCAN (Embedded Software Developer)
 * 
 * Created on:      DEC, 2020
 * 
 * Platform:        PIC16F84A
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
 *              Button connected to RA0
 *              8 Leds on RB0~RB7
 *              
 * 
 * Purpose :	introduction to embedded world
 * 
 **********************************************************************
 * 
 * Note :
 *  When you push onto the button on RA0, the LEDs on RB0~RB3 will turn on.
 *  Otherwise, LEDs on RB4~RB7 will bright
 *
 *  
 **********************************************************************/


#ifndef __CONFIGURATION_H__
#include <xc.h>
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)
#endif /* __CONFIGURATION_H__ */



#define _XTAL_FREQ 40000000 //4MHz crystal used

// included files
#include <stdbool.h>
#include "configuration.h"



void main(void) {
    
    TRISA = 0x01;   // 0b00000001 RA0 
    TRISB = 0;
    
    while(true)
    {
        if (RA0 == 1)   // if you do not push the button...
        {
            PORTB = 0x0F;
        }
        else
        {
            PORTB = 0xF0;
        }
    }
    
    return;
}
