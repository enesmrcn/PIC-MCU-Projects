/*
 * File:   main.c
 * Author: enesmercan
 *
 * Created on January 1, 2021, 12:19 PM
 */






#include <stdio.h>
#include <stdlib.h>
#include "lcdDriving.h" //  the project header file
#include "lcd.h"


void init_XLCD(void);
void DelayFor18TCY(void);
void DelayPORXLCD (void);   //  15 ms delay
void DelayXLCD (void);  //  5ms delay

void main(void) {
    
    init_XLCD();                //  Initialize LCD display
    SetDDRamAddr(0x05);         // Start from the 5th block
    putrsXLCD("Enes Mercan");   //  Display "Enes Mercan"
    SetDDRamAddr(0x40);         //  Shift the cursor beginning of the second line
    putrsXLCD("Embedded Developer");
    
    while (1)
    {
        
    }
    
    return;
}

void init_XLCD(void)
{
    OpenXLCD(FOUR_BIT & LINES_5x7); // Configure LCD in 4-bit Data mode
    while (BusyXLCD()); //  Check if the LCD is not busy
    WriteCmdXLCD(0x06); //  Move cursor right, don't shift display
    WriteCmdXLCD(0x0F); //  Turn display ON without cursor
    
    return;
}

void DelayFor18TCY( void )
{
  // 14 clock cycle delay with NOP
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  Nop();
  
  return;   // Additional 2 clock cycle delay with return
}

void DelayPORXLCD (void)
{
  Delay1KTCYx(30); // Delay of 15ms
                   // Cycles = (TimeDelay * Fosc) / 4
                   // Cycles = (15ms * 8MHz) / 4
                   // Cycles = 30,000
  return;
}

void DelayXLCD (void)
{
  Delay1KTCYx(10); // Delay of 5ms
                   // Cycles = (TimeDelay * Fosc) / 4
                   // Cycles = (5ms * 8MHz) / 4
                   // Cycles = 10,000
  return;
}
