#ifndef UART_H
#define	UART_H

#include <stdint.h>


void UART_Send_String(char *text);            //  Send a convey of string
void UART_Send(char data);                  //  Transmit the data command
void UART_TX_IntEnable(const uint8_t priority);   //  Enable interrupts for TX
void UART_Init(const uint32_t baudrate);    //  Initialization USART module for Serial comm.

void UART_Read_Text(char *, unsigned int);
char UART_Read();
char UART_Data_Ready();

#endif	/****** UART_H ******/

