 /*********************************************************************
 *
 *      Basic I/O Driving Exercise
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
 *              The seven segment-1 display pins are connected to RD0:RD7
 *              There are 330ohm resistors on each line betw 7Seg and MCU.
 * 
 *              The seven segment-2 display pins are connected to RB0:RB7
 *              There are 330ohm resistors on each line betw 7Seg and MCU.
 * 
 * Purpose :	driving standard i/o ports
 *              
 *
 **********************************************************************/

#ifndef __XC_H_
#include <xc.h>
#endif /* __XC_H_ */

#define _XTAL_FREQ  16000000
#define DELAY       500

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

const uint8_t matris[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
volatile uint8_t i = 0;
volatile uint8_t j = 0;
        

void main(void) {
    
    TRISD = 0x00;   //  Initialize PORTC by clearing output data latches
    PORTD = 0x00;   //  Initialize PORTC by clearing output data latches
    
    TRISB = 0x00;   //  Initialize PORTC by clearing output data latches
    PORTB = 0x00;   //  Initialize PORTC by clearing output data latches
    
    LATD = matris[0];
    LATB = matris[0];
    
    while (true)
    {
        
        for (i = 0; i<10; i++)
        {
            LATD = matris[i];
            __delay_ms(DELAY);
            
            for (j = 1; j<10; j++)
            {
                LATB = matris[j];
                
                __delay_ms(DELAY);
                
            }
            
            LATB = matris[0];
        }
        
    }
    
    return;
}
