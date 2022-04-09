 /*********************************************************************
 *
 *      External Interrupt Tutorial (RB0/INT)
 *
 *********************************************************************
 * FileName:        main.c
 * Dependencies:    <config.h>  <stdint.h>    <stdbool.h>   <xc.h>
 *                  
 *                  
 * Processor:       PIC32MX
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Author:          Enes MERCAN (Embedded Software Developer)
 * 
 * Created on:      Sept, 2020
 * 
 * Platform:        PIC16FXXX
 *
 *********************************************************************
 *
 * Software License Agreement
 *  
 *   "THE KEBAB-WARE LICENSE" (Revision 42):
 * <enesmercan1453@gmail.com> wrote this file.  As long as you retain this 
 * notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff is worth it, you can buy me a Turkish Kebab in return.
 *						- Enes Mercan
 *
 *********************************************************************
 * 
 * In this program: 
 *              Using a button on RB0, controlling led on RA0 
 *              while the LEDs on RB1 and RB1 blinking continuously
 * 
 * Purpose :	learning external interrutps (rb0/int)
 * 
 **********************************************************************
 * 
 * Note :
 *  To use external/rb0 interrupt feature :
 *  - setup  rb0 pin as input
 *  - setup INTEDG bit in the OPTION register to define falling/rising edge
 *  - clear INTF bit in INTCON
 *  - setup GIE bit on INTCON to enable all interrupts in pic
 *  - setup INTE bit in INTCON to enable rb0 interrupts
 *  
 *  Do not forget to :
 *  - store the interrupt sub-program's address in 0004h address
 *  - disable INTE bit when external interrupt occurs
 *  - clear the INTF bit when you get done with int to let the rb0 occur again
 *  - enable INTE bit just after interrupt process done
 * 
 ********************************************************************/