


#include <xc.h>
#include "i2c.h"
#include "config.h"
#include <stdint.h>


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
