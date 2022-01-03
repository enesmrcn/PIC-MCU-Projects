 /*********************************************************************
 *
 *      External Interrupt Tutorial (RB0/INT)
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <config.h>    <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC32MX
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Author:          Enes MERCAN (Embedded Software Developer)
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
 *              Using a button on RB0, controlling led on RA0 
 *              while the LEDs on RB1 and RB1 blinking continuously
 * 
 * Purpose :	learning external interrutps (rb0/int)
 * 
 **********************************************************************
 * 
 * Note :
 *  To use external/rb0 interrupt feature :
 *  - setup  rb0 pin as input
 *  - setup INTEDG bit in the OPTION register to define falling/rising edge
 *  - clear INTF bit in INTCON
 *  - setup GIE bit on INTCON to enable all interrupts in pic
 *  - setup INTE bit in INTCON to enable rb0 interrupts
 *  
 *  Do not forget to :
 *  - store the interrupt sub-program's address in 0004h address
 *  - disable INTE bit when external interrupt occurs
 *  - clear the INTF bit when you get done with int to let the rb0 occur again
 *  - enable INTE bit just after interrupt process done
 * 
 ********************************************************************/


#define _XTAL_FREQ 10000000    // define clock frequency


#include "config.h"     // include my header file
#include <stdbool.h>


// When interrupts occur, the program flow jumps here immediately
void __interrupt() myIntHandler(void);  // the prototype of the function


void main(void) {
    
    PORTB = 0x00;               //  Clear initial values
    TRISB = 0b00000001;         //  RB0 as input, others output
    TRISA = 0x00;               //  RB0 is output
    
    //OPTION_REG |= (1 << INTEDG); // other way of configuration
    OPTION_REGbits.INTEDG = 0;    // 0 = Interrupt on falling edge of RB0/INT pin
    // INTEDG = 0; // You can simply do the same in that way
    
   
    // Changes on INTCON register below

    INTCONbits.RBIF = 0;        // Clear the flag to get ready the module
    
    INTCONbits.INTE = 1;          // 1 = Enables the RB0/INT external interrupt
    //INTCON |= (1 << INTE);
    
    INTCONbits.GIE = 1;          // 1 = Enables all un-masked interrupts
    //INTCON |= (1 << GIE);   
    
    
    
    // the program will repeat (loop)
    while (true)
    {
        
        RB1 = 1;
        RB2 = 0;
        __delay_ms(1000);
        
        RB1 = 0;
        RB2 = 1;
        __delay_ms(1000);
    }
    
    return;
}


// Interrupt sub-program below
void __interrupt() myIntHandler(void)   
{
    
    if (INTCONbits.INTF == 1)   // If the external interrupt flag is set
    {
        INTCONbits.INTE = 0;    // disable RB0 interrupts first
        
        PORTAbits.RA0 = ~(PORTAbits.RA0);   // Toggle the LED on RB1 
        
        INTCONbits.INTF = 0;    // Clear interrupt flag
        INTCONbits.INTE = 1;    // Enable RB0 interrupts first
    }
    
    // We don't put here "return"
}