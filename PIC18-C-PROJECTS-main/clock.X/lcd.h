
#ifndef LCD_H
#define	LCD_H
    
    #ifndef _XC_H
    #include <xc.h> // include processor files - each processor file is guarded.  
    #endif /* _XC_H */

    
    /*** LCD CONNECTIONS ***/
    //        ..LCD.. ..PIC..
    #define     RS      RD0
    #define     EN      RD2
    #define     D4      RD4
    #define     D5      RD5
    #define     D6      RD6
    #define     D7      RD7
    //.....     RW      GND
    //.....     D0      GND
    //.....     D1      GND
    //.....     D2      GND
    //.....     D3      GND


    extern void Lcd_Start(void);                    //                  
    extern void Lcd_Clear();                        //              
    extern void Lcd_Set_Cursor(char a, char b);     //  
    extern void Lcd_Print_Char(char data);          //  Send 8-bits through 4-bit mode
    extern void Lcd_Print_String(char *a);          //            
    extern void Lcd_Cmd(char a);                    //  
    extern void Lcd_SetBit(char data_bit);          //  Based on the Hex value Set the Bits of the Data Lines
    
#endif	/* LCD_H */

    
    
    
/*
 *
 * credits to
 * circuitdigest.com
 * https://circuitdigest.com/microcontroller-projects/16x2-lcd-interfacing-with-pic-microcontroller
 * 
 * 
 */