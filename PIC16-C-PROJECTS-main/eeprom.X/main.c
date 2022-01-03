 /*********************************************************************
 *
 *      EEPROM Introduction
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <config.h>   <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC32MX
 *
 * Complier:        MPLAB IDE
 *                  
 * Author:          Enes MERCAN (Embedded Software Developer)
 * 
 * Created on:      DEC, 2020
 * 
 * Platform:        PIC16F84A
 *
 * *********************************************************************
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
 *              
 *              
 * 
 * Purpose :	
 * 
 *********************************************************************/


#define _XTAL_FREQ 4000000

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

void __interrupt() myInterruptHandler();
void setEeprom(void);
void unlockProtection(void);

uint8_t counter = 0;

void main(void) {
    
    TRISB = 0;
    TRISA = 1;  //  Button on RA0
    PORTB = 0;  //  Clear portB
    
    setEeprom();
    
    while (true)
    {
        if (RA0 == 0)   // pushed button?
        {
            __delay_ms(5);  // wait for possible button arc
            
            while(RA0 == 0){}   // Infinite loop to wait for releasing button
            
            counter++;
            
            EEADR = 0x1F;   //  The address to be written on
            EEDATA = counter;
            WREN = 1;       // Enable writing on eeprom
            unlockProtection();
            WR = 1;         //  Start writing
            
        }
    }
    
    return;
}


void __interrupt() myInterruptHandler()
{
    if (EEIF)
    {
        EEADR = 0x1F;   //  Address to be read
        RD = 1;         //  Start reading
        
        PORTB = EEDATA; //  Paste the data was read
    }
    
    EEIF = 0;
}

void setEeprom(void)
{ 
    INTCONbits.GIE = 1; // Enable global interrupt
    INTCONbits.EEIE = 1;    //  Enable EEPROM module
}

void unlockProtection(void)
{
    EECON2 = 0x55;
    EECON2 = 0xAA;
}