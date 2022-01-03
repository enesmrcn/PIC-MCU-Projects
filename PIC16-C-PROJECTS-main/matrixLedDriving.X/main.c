 /*********************************************************************
 *
 *      matrixLedDriving
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
 * Created on:      DEC, 2020
 * 
 * Platform:        PIC18F877A
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
 *              Matrix anode pins are connected to RB0~RB7
 *              cathode pins are connected to RC0~RC4
 *              The idea is that to show letters or any characters
 *              colmn by colmn
 *  
 * Purpose :	learning driving 5x7 matrix led
 * 
 **********************************************************************
 * 
 * Note :
 *  nothing...
 * 
 **********************************************************************/


#ifndef __CONFIGURATION_H__
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h>
#endif  /* __CONFIGURATION_H__ */



#define _XTAL_FREQ 4000000  // 4MHz external oscillator used here
#define letterNumber  3     // 3 type of letters (for E, N, S) to be used
#define messageLenght 4     // I will show 'ENES' word, lenght of 4

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>


uint8_t letter [letterNumber][5] = {{0x0, 0x36, 0x36, 0x36, 0x3E},     // letter E
                            {0x41, 0x7B, 0x77, 0x6F, 0x41},    // letter N
                               {0x30, 0x36, 0x36, 0x36, 0x06}};  // letter S
uint8_t message [messageLenght] = {0, 1, 0, 2}; // E N E S



void main(void) {
    
    TRISB = 0;
    TRISC = 0;
    
    while (true)
    {
        for (int8_t letterIndex = 0; letterIndex<messageLenght; letterIndex++)
        {        
            for (int8_t repeat = 0; repeat<55; repeat++)
            {
                PORTC = 1;

                for (int8_t i = 0; i<5; i++)
                {
                    PORTB = letter[message[letterIndex]][i];
                    __delay_ms(5);

                    PORTC = (PORTC << 1);
                }

            }
            
            PORTC = 0;
            PORTB = 1;
            __delay_ms(300);
        }
    }
    
    return;
}
