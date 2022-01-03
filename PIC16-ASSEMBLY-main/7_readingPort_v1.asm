;   program :	PICTEST1.ASM
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	Reading the PORTA pins and writing on PORTB pins
;   purpose :	learning to use pins as digital input
;		using CMCON to set pins as digital...
;		using W register to hold and transfer data
;		learning the hardware characteristics of PORTA and PORTB pins
;----------------------------------------------------------------------    
; Note 1 :
;   You can normally set the PORTA pins as input by just playing on TRISA
;   register. However, the RA0, RA1, RA2, RA3 pins are directly connected to
;   comparators. So that, we also have to play with the first 3 bits of the
;   CMCON register to set those pins as digital input. You may also use those
;   pins for different purposes by configurating the assoicated bits in 
;   different modes. But for now, enough to know that to set the CMCON to h'07'
;   means that we actually configurate the whole ra0~ra3 pins as digital inputs.
;
;----------------------------------------------------------------------  
; Note 2 :
;   The PORTA pins are all actually schmitt triggers. That means that
;   their electrical characteristics are little bit from the PORTB pins 
;   which are those actually ttl transistors. It's good to know that
;   for schimitt trigger, 0-1V input means logic 0 and 4-5V input signal means 
;   logic 1. For ttl hardware however, 0-2V input signal is sense as logic 0
;   and 2-5.5V input signal is sense as logic 1. As a result, unless you send a
;   signal above 2V to portA pins, the LEDs connected to portB won't blink :)
;   Yeah. It's interesting!
;
;---------------------------------------------------------------------- 
; Note 3 :
;   The pic is gonna only bright the LEDs once as they are in the beginning.
;   Because there is no continuous reading process in this code.
;   You may not understand me. So, simply after you understand this code,
;   check the next program that it has been fixed to show the difference ;)
;    
;----------------------------------------------------------------------
    
; indicate what pic we're using to the complier    
    
    LIST    P = 16F628A
    INCLUDE "P16F628A.INC"

;----------------------------------------------------------------------
;configuration bits
	
    __CONFIG	_XT_OSC	& _WDT_OFF & _PWRTE_ON & _MCLRE_ON & _BODEN_OFF & 
    _LVP_OFF & _DATA_CP_OFF & _CP_OFF
 
    ;_XT_OSC	--> external crystal oscillator
    ;_WDT_OFF	--> watchdog timer off
    ;_PWRTE_ON	--> power up timer is on (will wait 72ms when powered)
    ;_MCLRE_ON	--> external reset is active
    ;_BODEN_OFF --> low voltage protection is off (diff to handle for beginners)
    ;_LVP_OFF	--> low power programming is disabled
    ; _DATA_CP_OFF  --> no eeprom data protection (it's readable)
    ;_CP_OFF	--> no rom code protection (anyone can read)
    
    
;----------------------------------------------------------------------
; starts the program from this address
	
    ORG	H'0000'

;----------------------------------------------------------------------
; This is basically SETUP block of our program
	
    CLRF    PORTB
    BANKSEL TRISB
    CLRF    TRISB
    MOVLW   h'FF'
    MOVWF   TRISA
    BANKSEL PORTA
    MOVLW   h'07'
    MOVWF   CMCON
    
;----------------------------------------------------------------------
; The program execution block (main program flow block)
	
START
    
    MOVF    PORTA, w
    MOVWF   PORTB
    
;----------------------------------------------------------------------
; Ending the program
	
LOOP
    
    GOTO LOOP
    END
	
;----------------------------------------------------------------------
