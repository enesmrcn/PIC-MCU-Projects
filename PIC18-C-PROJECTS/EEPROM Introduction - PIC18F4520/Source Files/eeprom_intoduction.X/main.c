/*
 * File:   maib.c
 * Author: enes
 *
 * Created on 13 October 2021, 14:59
 */


#define _XTAL_FREQ  10000000

#ifndef __XC_H
#include <xc.h>
#endif 

#include "config.h"
#include <stdbool.h>
#include <stdint.h>

uint8_t led = 0;
uint32_t numb = 0xFDFC;

int8_t EEPROMwrite(uint8_t * ptr, uint8_t address)     //  ptr: address of the data (array, strnig) to be written, note: can write 1 or 2 bytes at once ,returns 1 as success state
{
    
        EEDATA = *ptr;
        EEADR = address;
        
        EECON1bits.CFGS = 0;
        EECON1bits.WREN = 1;        //  Enable writes
        
        if (RCONbits.IPEN)
        {
            INTCONbits.GIEH = 0;
            INTCONbits.GIEL = 0;
        }
        else
            INTCONbits.GIE = 0;
        
        
        EECON2 = 0x55;
        EECON2 = 0xAA;
        EECON1bits.WR = 1;          //  Initiates a data EEPROM erase/write cycle
        
        if (RCONbits.IPEN)
        {
            INTCONbits.GIEH = 1;
            INTCONbits.GIEL = 1;
        }
        else
            INTCONbits.GIE = 1;
        
        EECON1bits.WR = 0;          //  Initiates a data EEPROM erase/write cycle
    
    
    if (EECON1bits.WRERR == 0)
        return 0;   //  error in writing. the EEPGD and CFGS bits are not cleared
    else
        return 1;
}


uint8_t EEPROMread(uint8_t address)
{
    EEADR = address;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WR = 1;
    
    return EEDATA;
}



void main(void) {
    
    LATD = 0;
    TRISD = 0;
    
    while (true)
    {
        EEPROMwrite(&led, 0x00);
        LATD = EEPROMread(0x00);
        
        __delay_ms(500);
        
        if (led == 255)
            led = 0;
        
        led++;
        
    }

    return;
}
