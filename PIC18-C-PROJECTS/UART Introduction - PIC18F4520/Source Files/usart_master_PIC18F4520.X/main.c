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

void UART_Send_Text(char *text);            //  Send a convey of string
void UART_Send(char data);                  //  Transmit the data command
void UART_TX_IntEnable(const uint8_t priority);   //  Enable interrupts for TX
void UART_Init(const uint32_t baudrate);    //  Initialization USART module for Serial comm.

char counter = 0;


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


void main(void)
{
    
    LATB = 0;                   //  Clear the port
    TRISBbits.RB7 = 0;          //  LED attached
    TRISBbits.RB6 = 0;          //  LED attached
    
    TRISBbits.RB0 = 1;          //  Increment button attached
    TRISBbits.RB1 = 1;          //  Decrement button attached
    
    UART_Init((uint32_t)9600);
    
    // Since we are not necessarily using interrupts for UART, may leave them commented
    //RCONbits.IPEN = 1;          //  Priority levels activated
    //INTCONbits.GIEH = 1;        //  1 = Enables all high priority interrupts
    //INTCONbits.GIEL = 1;        //  1 = Enables all low priority peripheral interrupts
    
    //UART_TX_IntEnable(1);       //  Enable TX interrupts
    
    while(true)
    {
        // NOT : BUTONLARI INTERRUPT ILE YAP INT0 INT1
        if ( (PORTB & 0x01) == 1)   
        {
            __delay_ms(50);     //  button bouncing delay
            counter += 1;
            LATBbits.LATB6 = ~LATBbits.LATB6;
        }
        
        else if ( ((PORTB & 0x02) >> 1) == 1)
        {
            __delay_ms(50);     //  button bouncing delay
            counter -= 1;
            LATBbits.LATB6 = ~LATBbits.LATB6;
        }
        
        UART_Send(counter);
        __delay_ms(200);
    }
    
    return;
}

void UART_Send_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
	  UART_Send(text[i]);
}

void UART_Send(char data)
{
  while(!TRMT);
  TXREG = data;
  LATBbits.LATB7 = ~LATBbits.LATB7;
  
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


void UART_TX_IntEnable(const uint8_t priority)    //  Low priority yap burayý
{
    IPR1bits.TXIP = priority;       //  1 = High priority
    PIE1bits.TXIE = 1;              //  1 = Enables the EUSART transmit interrupt
    
}