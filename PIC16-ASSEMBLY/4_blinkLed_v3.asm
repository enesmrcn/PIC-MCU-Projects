;   program :	PICTEST1.ASM
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	Turning on the LED connected to RB0, using BANKSEL
;   purpose :	learning BANKSEL
;----------------------------------------------------------------------
    
; indicate what pic we're using to the complier    
    
    LIST    P = 16F628A
    INCLUDE "P16F628A.INC"
;----------------------------------------------------------------------
;setting the addresses for the PIC
	
    // you've already defined the register addresses on line 10
 
;----------------------------------------------------------------------
; starts the program from this address
	
    ORG	    0x00
    
;----------------------------------------------------------------------
; This is basically SETUP block of our program
	
    CLRF    PORTB	; Clean the initial values
    ;BSF    STATUS, RP0	; Go to BANK1
    ;BCF    STATUS, RP1	; It's not actually necessary, but just to show you
    BANKSEL TRISB	; Go to BANK1
    CLRF    TRISB	; Set PORTB as output
    ;BCF    STATUS, RP0	; Go back to BANK0
    ;BCF    STATUS, RP1	; It's not actually necessary, but just to show you
    BANKSEL PORTB	; Go back to BANK0
	
;----------------------------------------------------------------------
; The program execution block (main program flow block)
	
START
    
    BSF	    PORTB, 0	; Turn on the LED (RB0)
	
;----------------------------------------------------------------------
; Ending the program
	
LOOP
    
    GOTO LOOP
    END
	
;----------------------------------------------------------------------
 