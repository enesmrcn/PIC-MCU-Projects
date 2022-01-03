 /*********************************************************************
 *
 *      Cascaded 7-Segment Displays Exercise
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
 *              The cascaded 7Seg display is connected to the pins
 *             through RD0:RD7
 *              The challenge of this project is that you cannot display
 *             or use 2 7seg at the same time. So, there is also display
 *             selection pin which display to use.
 *              Display-1 selection pin is connected to RE0 and
 *             Display-2 selection pin is connected to RE1
 *
 *              When you drive HIGH the RE0, display-1 will be activated.
 * 
 * Purpose :	driving standard i/o ports
 *              
 *
 **********************************************************************/

#ifndef __XC_H_
#include <xc.h>
#endif /* __XC_H_ */

#define _XTAL_FREQ  16000000
#define DELAY       5

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

const uint8_t matris[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
volatile uint8_t i = 0;
volatile uint8_t counter = 0;
        

void main(void) {
    
    LATD = 0;    //  Clear from latched information
    PORTD = 0;   //  Clear from latched information
    LATE = 0;    //  Clear from latched information
    PORTE = 0;   //  Clear from latched information
    LATA = 0;    //  Clear from latched information
    PORTA = 0;   //  Clear from latched information
    
    TRISE = 0x00;   //  All PortE pins are output
    TRISD = 0x00;   //  All PortD pins are output
    
    while (true)
    {
        
        for (counter = 0; counter < 100; counter++)
        {
            for (i = 0; i < 20; i++)
            {
                LATE = 0x01;
                LATD = matris[counter % 10];
                
                __delay_ms(DELAY);
                
                LATE = 0x02;
                LATD = matris[counter / 10];
                
                __delay_ms(DELAY);
                
            }
            
        }
    }
    
    return;
}
