 /*********************************************************************
 *
 *      PWM Exercise
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
 * Created on:      Oct, 2021
 * 
 * Platform:        Windows 10
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
 *             
 *              
 *
 *
 * 
 *
 *
 * Purpose :	Learning pwm
 *              
 *
 **********************************************************************/

#ifndef __XC_H_
#include <xc.h>
#endif /* __XC_H_ */

#define     _XTAL_FREQ           16000000

#include "configuration.h"
#include <stdbool.h>
#include <stdint.h>

void __interrupt() myInterruptHandler();
void setPWM(void);

uint16_t pwmDutyCycle = 0x0000;

void main(void) {
   
    LATB = 0;
    setPWM();
    
    
    while (true)
    {
        
        CCPR4L = (uint8_t) pwmDutyCycle;  //  Set PWM duty cycle to 

        pwmDutyCycle++;
        
        if ( (pwmDutyCycle & 0x0200) == 1)
            CCP4CONbits.DC4B1 = 1;
        else
            CCP4CONbits.DC4B1 = 0;
        
        if ( (pwmDutyCycle & 0x0100) == 1)
            CCP4CONbits.DC4B0 = 1;
        else
            CCP4CONbits.DC4B0 = 0;
        
        if ( (pwmDutyCycle & 0x0400) == 1)
            pwmDutyCycle = 1;
        
        __delay_ms(50);
        
    }
    
    
    return;
}


void setPWM(void)
{
    PR2 = 255;              //  Set the PWM period time to 2ms
    CCPR4L = (uint8_t) pwmDutyCycle;  //  Set PWM duty cycle to 
    T2CONbits.T2CKPS0 = 0;  //  10 = Prescaler is 16
    T2CONbits.T2CKPS1 = 1;  //  10 = Prescaler is 16
    TRISB &= ~(0x10);       //  RB4 is set as output
    T2CONbits.TMR2ON = 1;   //  Enable Timer-1 module
    CCP4CON |= 0x0F;        //  11xx = PWM mode
    
}


void __interrupt() myInterruptHandler()
{
    
            
}
