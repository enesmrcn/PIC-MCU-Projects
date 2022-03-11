/*
 * File:   main.c
 * Author: enes
 *
 * Created on 13 October 2021, 18:54
 */

#define     _XTAL_FREQ          20000000
#define     RTC_WRITE_ADDR      (0xD0)
#define     RTC_READ_ADDR       (0xD1)

#include <xc.h>
#include "config.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>



void __interrupt() high_isr(void);
void __interrupt(low_priority) low_isr(void);

void UART_Send_Text(char *text);            //  Send a convey of string
void UART_Send(char data);                  //  Transmit the data command
void UART_TX_IntEnable(const uint8_t priority);   //  Enable interrupts for TX
void UART_Init(const uint32_t baudrate);          //  Initialization USART module for Serial comm.

char counter = 0;
uint8_t uart_data = 0;
uint8_t print_buffer [256]= {0};

/********************** UART FUNCTIONS ***************************/

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



void UART_TX_IntEnable(const uint8_t priority)
{
    IPR1bits.TXIP = priority;       //  1 = High priority
    PIE1bits.TXIE = 1;              //  1 = Enables the EUSART transmit interrupt
    
}


/************************** I2C FUNCTIONS *************************/


void I2C_Initialize(const unsigned long feq_K) //Begin IIC as master
{
  TRISC3 = 1;  TRISC4 = 1;  //Set SDA and SCL pins as input pins
  
  SSPCON1  = 0b00101000;    //pg84/234 
  SSPCON2 = 0b00000000;    //pg85/234
  
  SSPADD = (_XTAL_FREQ/(4*feq_K*100))-1; //Setting Clock Speed pg99/234
  SSPSTAT = 0b00000000;    //pg83/234
}

void I2C_Idle()
{
    while (   (SSPCON2 & 0b00011111)    ||    (SSPSTAT & 0b00000100)   ) ; //check the bis on registers to make sure the IIC is not in progress
}

void I2C_Begin()
{
  I2C_Idle();  //Hold the program is I2C is busy  
  SEN = 1;     //Begin IIC pg85/234
}

void I2C_End()
{
  I2C_Idle(); //Hold the program is I2C is busy  
  PEN = 1;    //End IIC pg85/234
}

void I2C_Write(unsigned data)
{
  I2C_Idle(); //Hold the program is I2C is busy 
  SSPBUF = data;         //pg82/234
}

uint8_t I2C_Read(uint8_t ack)
{
  uint8_t incoming;
  I2C_Idle();
  RCEN = 1;
  
  I2C_Idle();
  incoming = SSPBUF;      //get the data saved in SSPBUF
  
  I2C_Idle();
  ACKDT = (ack)?0:1;    //check if ack bit received  
  ACKEN = 1;          //pg 85/234
  
  return incoming;
}


/************************** RTC FUNCTIONS ***************************/

// Set the current value of date and time below
int set_sec = 00;
int set_min = 22;
int set_hour = 16;
int set_date = 17;
int set_month = 10;
int set_year = 21;


int  BCD_2_DEC(int to_convert)
{
   return (to_convert >> 4) * 10 + (to_convert & 0x0F); 
}

int DEC_2_BCD (int to_convert)
{
   return ((to_convert / 10) << 4) + (to_convert % 10);
}

void Set_Time_Date()    //  
{
   I2C_Begin();       
   I2C_Write(RTC_WRITE_ADDR); 
   I2C_Write(0);  
   I2C_Write(DEC_2_BCD(00)); //update sec
   I2C_Write(DEC_2_BCD(14)); //update min
   I2C_Write(DEC_2_BCD(15)); //update hour
   I2C_Write(1); //ignore updating day
   I2C_Write(DEC_2_BCD(17)); //update date
   I2C_Write(DEC_2_BCD(10)); //update month
   I2C_Write(DEC_2_BCD(21)); //update year
   I2C_End();
}


/******************************************************************/



void main(void)
{
    UART_Init(9600);
    I2C_Initialize(100); //Initialize I2C Master with 100KHz clock
    
    __delay_ms(100);
    Set_Time_Date();
    
    while(true)
    {
        
       I2C_Begin();       
       I2C_Write(RTC_WRITE_ADDR); 
       I2C_Write(0x01);  
       I2C_End();
       
      
       
       I2C_Begin();       
       I2C_Write(RTC_READ_ADDR); 
       uint8_t sec = I2C_Read(1);  
       I2C_End();
       
       sprintf(print_buffer, "0x%02x\n\r",sec);

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
