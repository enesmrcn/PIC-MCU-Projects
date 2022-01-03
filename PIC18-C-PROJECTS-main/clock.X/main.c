
#include    <xc.h>
#include    <stdio.h>
#include    <stdbool.h>

#include    "config.h"
#include    "i2c.h"
#include    "lcd.h"
#include    "uart.h"
#include    "ds1307.h"

#define     RTC_WRITE_ADDR      (0xD0)
#define     RTC_READ_ADDR       (0xD1)

char counter = 0;
uint8_t uart_data = 0;
uint8_t print_buffer [256]= {0};


void main(void) {
    
    TRISD = 0x00;
    Lcd_Start();
    
    
    UART_Init((uint32_t)9600);
    I2C_Initialize(100); //Initialize I2C Master with 100KHz clock
    
    
    
    LATB = 0;                   //  Clear the port
    TRISBbits.RB7 = 0;          //  LED attached
    TRISBbits.RB6 = 0;          //  LED attached
    
    TRISBbits.RB0 = 1;          //  Increment button attached
    TRISBbits.RB1 = 1;          //  Decrement button attached
    
    
    
    sprintf(print_buffer, "Enes Mercan\n\r17.10.2021");
    UART_Send_String(print_buffer);
    
    
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Print_String("Enes Mercan");
    Lcd_Set_Cursor(2,1);
    Lcd_Print_String("17.10.2021");
    __delay_ms(1000);
    
    Set_Time_Date();
    
    
    while(true)
    {
        
        
        Update_Current_Date_Time(); //Read the current date and time from RTC module
        
        //Display the Current Time on the LCD screen
        //Split the into char to display on lcd
        Lcd_Clear();
        Lcd_Set_Cursor(1, 1);
        Lcd_Print_String("TIME: ");
        Lcd_Print_Char((current_time.hour / 10) + '0');
        Lcd_Print_Char((current_time.hour % 10) + '0');
        Lcd_Print_Char(':');
        Lcd_Print_Char((current_time.min / 10) + '0');
        Lcd_Print_Char((current_time.min % 10) + '0');
        Lcd_Print_Char(':');
        Lcd_Print_Char((current_time.sec / 10) + '0');
        Lcd_Print_Char((current_time.sec % 10) + '0');
        __delay_ms(10);
        
        
        //Display the Date on the LCD screen
        Lcd_Set_Cursor(2, 1);
        Lcd_Print_String("DATE: ");
        Lcd_Print_Char((current_time.date / 10) + '0');
        Lcd_Print_Char((current_time.date % 10) + '0');
        Lcd_Print_Char(':');
        Lcd_Print_Char((current_time.month / 10) + '0');
        Lcd_Print_Char((current_time.month % 10) + '0');
        Lcd_Print_Char(':');
        Lcd_Print_Char(2 + '0');
        Lcd_Print_Char(0 + '0');
        Lcd_Print_Char((current_time.year / 10) + '0');
        Lcd_Print_Char(((current_time.month % 10)+1) + '0');
        __delay_ms(10);
        
        /*** UART ****/
        
        sprintf(print_buffer, "\r%d%d : %d%d : %d%d", 
                (current_time.hour / 10), (current_time.hour % 10),
                (current_time.min / 10), (current_time.min % 10),
                (current_time.sec / 10), (current_time.sec % 10));
        UART_Send_String(print_buffer);
       
        __delay_ms(350);
    }
    
    
    return;
}
