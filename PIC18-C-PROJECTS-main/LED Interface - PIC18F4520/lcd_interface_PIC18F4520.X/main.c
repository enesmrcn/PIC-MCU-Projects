/*
 * File:   main.c
 * Author: enes
 *
 * Created on 17 October 2021, 16:41
 */


#include <xc.h>
#include "config.h"
#include "lcd.h"


void main(void) {
    
    TRISD = 0x00;
    Lcd_Start();
    while(1)
    {
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Print_String("Enes Mercan");
        Lcd_Set_Cursor(2,1);
        Lcd_Print_String("17.10.2021");
        __delay_ms(2000);
    }
    
    return;
}
