#include "ds1307.h"
#include "config.h"
#include <stdbool.h>
#include <stdint.h>
#include "i2c.h"

/************************** RTC FUNCTIONS ***************************/


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
   I2C_Write(DEC_2_BCD(set_time.sec)); //update sec
   I2C_Write(DEC_2_BCD(set_time.min)); //update min
   I2C_Write(DEC_2_BCD(set_time.hour)); //update hour
   I2C_Write(1); //ignore updating day
   I2C_Write(DEC_2_BCD(set_time.date)); //update date
   I2C_Write(DEC_2_BCD(set_time.month)); //update month
   I2C_Write(DEC_2_BCD(set_time.year)); //update year
   I2C_End();
}

void Update_Current_Date_Time()
{
   //START to Read
   I2C_Begin();       
   I2C_Write(RTC_WRITE_ADDR); 
   I2C_Write(0);    
   I2C_End(); 
   
  //READ
   I2C_Begin();
   I2C_Write(RTC_READ_ADDR);                              // Initialize data read
   current_time.sec = BCD_2_DEC(I2C_Read(1));    
   current_time.min = BCD_2_DEC(I2C_Read(1));   // Read sec from register 
   current_time.hour = BCD_2_DEC(I2C_Read(1));  
   I2C_Read(1);
   current_time.date = BCD_2_DEC(I2C_Read(1));  
   current_time.month = BCD_2_DEC(I2C_Read(1));  
   current_time.year = BCD_2_DEC(I2C_Read(1));  
   I2C_End(); 
    
  //END Reading  
    I2C_Begin();
    I2C_Write(RTC_READ_ADDR);                              // Initialize data read
    I2C_Read(1);    
    I2C_End(); 

}
