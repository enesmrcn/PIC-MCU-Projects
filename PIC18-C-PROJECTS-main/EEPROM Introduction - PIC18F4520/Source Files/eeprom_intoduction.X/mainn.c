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


uint8_t EEPROMwrite(uint32_t * ptr, uint8_t byte, uint8_t address)     //  ptr: address of the data to be written, byte: how many bytes ,returns 1 as success state
{
    EEADR = *address;
    
    uint8_t i = 0;
    
    do
    {
        EEDATA = (*ptr & (0x000000FF << i)) >> i;
        
        i++;
    }while (i < byte);
    
    
}

void main(void) {
    
    
    
    
    while (true)
    {
        
        
    }
    
    return;
}
