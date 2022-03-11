/*
 * File:   main.c
 * Author: enes
 *
 * Created on 06 October 2021, 19:43
 */



#include <xc.h>
#include "config.h"
#include <stdint.h>
#include <stdbool.h>

#define _XTAL_FREQ 10000000

void __interrupt() high_isr(void);
void __interrupt(low_priority) low_isr(void);

void UART_Write_Text(char *text);   //  Send a convey of string
void UART_Write(char data);         //  Transmit the data command

char data[] = "ENES MERCAN     ";   //  String to be transmitted

/************************************************************************/

void main(void)
{
    
    TRISBbits.RB7 = 0;
    TRISBbits.RB6 = 0;
    
    UART_Init((uint32_t)9600);
    
    // Since we are not necessarily using interrupts for UART, may leave them commented
    //RCONbits.IPEN = 1;            //  Priority levels activated
    //INTCONbits.GIEH = 1;        //  1 = Enables all high priority interrupts
    //INTCONbits.GIEL = 1;        //  1 = Enables all low priority peripheral interrupts
    
    
    while(true)
    {
        __delay_ms(200);
        UART_Write_Text(data);
        LATBbits.LATB7 = ~LATBbits.LATB7;
        
    }
    
    
    return;
}

/************  F U N C T I O N S  ****************/

void UART_Write_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
	  UART_Write(text[i]);
}


void UART_Write(char data)
{
  while(!TRMT);
  TXREG = data;
}



void UART_Init(const uint32_t baudrate)
{
    
	uint16_t baudrate_calculated = (_XTAL_FREQ - baudrate * 4) /(baudrate * 4);
    
    TXSTAbits.BRGH = 1;         //  1 = High speed, 0 = Low speed
    BAUDCONbits.BRG16 = 1;      //  1 = 16-bit Baud Rate Generator - SPBRGH and SPBRG

    SPBRG = (baudrate_calculated & 0x00FF);
    SPBRGH = (baudrate_calculated & 0xFF00) >> 8;
    
    TXSTAbits.SYNC = 0;         //  0 = Asynchronous mode
    TXSTAbits.TX9 = 0;          //  0 = Selects 8-bit transmission
    RCSTAbits.SPEN = 1;         //  1 = Serial port enabled (configures RX/DT and TX/CK pins as serial port pins)
    TRISCbits.RC6 = 1;          //  configure RC6/TX/CK
    TRISCbits.RC7 = 1;          //  configure RC7/RX/DT
    RCSTAbits.CREN = 1;         //  1 = Enables receiver
    TXSTAbits.TXEN = 1;         //  1 = Transmit enabled
}
