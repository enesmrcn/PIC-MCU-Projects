/*
 * File:   main.c
 * Author: enes
 *
 * Created on 13 October 2021, 18:54
 */


#define     RTC_WRITE_ADDR      (0xD0)
#define     RTC_READ_ADDR       (0xD1)

#include <xc.h>
#include "config.h"
#include "i2c.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>



void __interrupt() high_isr(void);
void __interrupt(low_priority) low_isr(void);



void main(void)
{
    
    I2C_Initialize(100); //Initialize I2C Master with 100KHz clock
    
    __delay_ms(100);
    
    while(true)
    {
        
       I2C_Begin();       
       I2C_Write(0xD0); 
       I2C_Write(0x01);  
       I2C_End();
       
       
       I2C_Begin();       
       I2C_Write(0xD1); 
       uint8_t sec = I2C_Read(1);  
       I2C_End();

       __delay_ms(1000);

    }
    
    
    return;
}



void __interrupt() high_isr(void)
{
    INTCONbits.GIEH = 0;
    
    if (PIR1bits.TXIF == 1)
    {
        
       LATBbits.LATB7 = ~LATBbits.LATB7;
    }
    
    INTCONbits.GIEH = 1;  
    
}


void __interrupt(low_priority) low_isr(void)
{
    INTCONbits.GIEL = 0;
    
    if (PIR1bits.RCIF == 1)
    {
        LATBbits.LATB6 = ~LATBbits.LATB6;
        
        PIR1bits.RCIF = 0;
    }
    
    INTCONbits.GIEL = 1;  
    
}


void UART_TX_IntEnable(const uint8_t priority)
{
    IPR1bits.TXIP = priority;       //  1 = High priority
    PIE1bits.TXIE = 1;              //  1 = Enables the EUSART transmit interrupt
    
}