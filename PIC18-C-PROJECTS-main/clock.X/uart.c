
#include "config.h"
#include "uart.h"
#include <stdint.h>


/***************************** UART TRANSMITTER *******************************/

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


void UART_Send_String(char *text)
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

void UART_TX_IntEnable(const uint8_t priority)
{
    IPR1bits.TXIP = priority;       //  1 = High priority
    PIE1bits.TXIE = 1;              //  1 = Enables the EUSART transmit interrupt
    
}


/************************ URAT RECEIVER ***************************************/

char UART_Data_Ready()
{
   return RCIF;
}


char UART_Read()
{
  while(!RCIF);
  return RCREG;
}

void UART_Read_Text(char *Output, unsigned int length)
{
	int i;
	for(int i=0;i<length;i++)
		Output[i] = UART_Read();
}

