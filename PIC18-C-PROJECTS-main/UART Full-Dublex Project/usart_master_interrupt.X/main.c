/*
 * File:   main.c
 * Author: enes
 *
 * Created on 06 October 2021, 19:43
 */


/*********************************** MASTER ***********************************/


#include <xc.h>
#include "config.h"
#include <stdint.h>
#include <stdbool.h>

#define _XTAL_FREQ 10000000

void __interrupt() high_isr(void);                      //  High level Interrupt Service Routine
void __interrupt(low_priority) low_isr(void);           //  Low level Interrupt Service Routine
void enableGlobalInts(const uint8_t enablePriority);    //  Enable global interrupts
void UART_TX_IntEnable(const uint8_t priority);         //  Enable interrupts for TX
void UART_RC_IntEnable(const uint8_t priority);         //  Enable interrupts for RX
void INTx_Init();                                       //  Initialize INT1 and INT2 modules
void TMR0_Run(void);                                    //  Start timing

void UART_Init(const uint32_t baudrate);    //  Initialization USART module
void UART_Send_Text(char *text);            //  Send a convey of string
void UART_Send(char data);                  //  Transmit the data command


void UART_Read_Text(char *, unsigned int);          //  Read and store in a string 
char UART_Read();               //  Read incoming data
char UART_Data_Ready();         //  Check any package was received

uint8_t readyTMR0 = 1;

char counter = 0;


/************************** REVEIVER ******************************************/


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

void UART_RC_IntEnable(const uint8_t priority)    //  Low priority yap burayý
{
    IPR1bits.RCIP = priority;       //  1 = High priority
    PIE1bits.RCIE = 1;              //  1 = Enables the EUSART transmit interrupt
    
}


/*********************** TRANSMITTER ******************************************/


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
  
  if (readyTMR0)
  {
    LATBbits.LATB6 = 1;
    TMR0_Run();
    readyTMR0 = 0;

  }
  
}

void UART_TX_IntEnable(const uint8_t priority)
{
    IPR1bits.TXIP = priority;       //  1 = High priority, 0 = Low priority
    PIE1bits.TXIE = 1;              //  1 = Enables the EUSART transmit interrupt
    
}


/*************************** GENERAL ******************************************/

void TMR0_Stop(void)
{
    
    T0CONbits.TMR0ON = 0;       //  TMR0 disabled
}

void TMR0_Run(void)
{
    T0CONbits.TMR0ON = 1;       //  TMR0 enabled
}

void TMR0_Init(uint16_t delay_ms)
{
    
    T0CONbits.TMR0ON = 0;       //  Stops Timer0
    
    uint16_t n = (_XTAL_FREQ / 102.0 ) * delay_ms / 10000.0;
    
    TMR0 = (n & 0x00FF);
    
    if (n > 0x00FF)
    {
        T0CONbits.T08BIT = 0;       //  0 = Timer0 is configured as a 16-bit counter
        TMR0H = (n & 0xFF00) >> 8;
    }
    else {
        T0CONbits.T08BIT = 1;       //  1 = Timer0 is configured as a 16-bit counter
    }
    
    
    
    INTCON2bits.TMR0IP = 0;     //  0 = Low priority
    T0CONbits.T0CS = 0;         //  Clock source is Instruction Cycle
    T0CONbits.PSA = 0;          //  Prescaler is assigned
    T0CONbits.T0PS = 0x07;      //  111 = 1:256 prescale value
    
    INTCONbits.T0IE = 1;        //  TMR0 interrupt is enabled
    
    
}

void INTx_Init()
{
    
    // Initialize INT2 feature
    INTCON3bits.INT2F = 0;      //  Initialise INT2 interrupt flag
    INTCON2bits.INTEDG2 = 1;    //  Rising edge
    INTCON3bits.INT2P = 0;      //  Low level priority
    INTCON3bits.INT2E = 1;      //  Enable INT2 feature
    
    // Initialize INT1 feature
    INTCON3bits.INT1F = 0;      //  Initialise INT1 interrupt flag
    INTCON2bits.INTEDG1 = 1;    //  Rising edge
    INTCON3bits.INT1P = 0;      //  Low level priority
    INTCON3bits.INT1E = 1;      //  Enable INT1 feature
    
}

void UART_Init(const uint32_t baudrate)
{ 
    
	uint16_t baudrate_calculated = (_XTAL_FREQ - baudrate * 4) / (baudrate * 4);
    
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

void enableGlobalInts(const uint8_t enablePriority)
{
    RCONbits.IPEN = enablePriority;      //  1 = Priority levels ON, 0 = Priority levels OFF
    INTCONbits.GIEH = 1;                 //  1 = Enables all high priority interrupts
    INTCONbits.GIEL = 1;                 //  1 = Enables all low priority peripheral interrupts
}

/***************************   ISR   ******************************************/

void __interrupt() high_isr(void)
{
    
    
    if (UART_Data_Ready())
    {
        
        
        if (readyTMR0)
        {
            LATBbits.LATB7 = 1;
            readyTMR0 = 0;
            TMR0_Run();
            
        }
        
        LATD = UART_Read();
        
    }
    
}

void __interrupt(low_priority) low_isr(void)
{
    
    if ( INTCONbits.T0IF == 1)
    {
        TMR0_Stop();
        readyTMR0 = 1;
        
        if ( PORTBbits.RB6 )
            LATBbits.LATB6 = 0;
        else if ( PORTBbits.RB7 )
            LATBbits.LATB7 = 0;
        
        INTCONbits.T0IF = 0;
        
    }
    
    // INT2 interrupt service routine
    if ( INTCON3bits.INT2F == 1 )
    {
        counter -= 1;
        LATBbits.LATB5 = ~LATBbits.LATB5;
        UART_Send(counter);
        
        INTCON3bits.INT2F = 0;
    }
    
    // INT1 interrupt service routine
    if ( INTCON3bits.INT1F == 1 )
    {
        counter += 1;
        LATBbits.LATB5 = ~LATBbits.LATB5;
        UART_Send(counter);
        
        INTCON3bits.INT1F = 0;
    }
             
    
}

/************************* MAIN LOOP ******************************************/

void main(void)
{
    LATD = 0;                   //  Clear the port
    LATB = 0;                   //  Clear the port
    TRISBbits.RB4 = 0;          //  LED attached (as Time indicator)
    TRISBbits.RB5 = 0;          //  LED attached (as Button indicator)
    TRISBbits.RB7 = 0;          //  LED attached (as Reception indicator)
    TRISBbits.RB6 = 0;          //  LED attached (as Transmission indicator)
    TRISD = 0x00;               //  LED array on D-terminals
    
    TRISBbits.RB1 = 1;          //  Increment button attached
    TRISBbits.RB2 = 1;          //  Decrement button attached
    
    TMR0_Init(100);             //  Configure TMR0 for 400ms delay
    INTx_Init();                 //  Initialize INT1 and INT2 modules
    UART_Init((uint32_t)9600);  //  Config USART as 9600 baud rate
    //UART_TX_IntEnable(0);       //  Enable TX interrupts
    enableGlobalInts(1);        //  Enable global interrupts
    UART_RC_IntEnable(1);       //  Enable RC interrupts
    
    while(true)
    {
        LATBbits.LATB4 = ~LATBbits.LATB4;
        __delay_ms(1000);
    }
    
    return;
}

