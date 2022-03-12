  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <stdint.h>

extern void I2C_Initialize(const unsigned long feq_K);   // Begin IIC as master
extern void I2C_Idle();
extern void I2C_Begin();
extern void I2C_End();
extern void I2C_Write(unsigned data);
extern uint8_t I2C_Read(uint8_t ack);


#endif	/* XC_HEADER_TEMPLATE_H */

