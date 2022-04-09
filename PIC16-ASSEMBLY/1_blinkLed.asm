;   program :	program_2.asm
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	Turning on the LED attached to RB0
;   purpose :	hello world
;----------------------------------------------------------------------
    
; indicate what pic we're using to the complier    

    LIST P = 16F628A

;----------------------------------------------------------------------
;setting the addresses for the PIC
	
    STATUS  EQU	h'03'
    TRISB   EQU	h'86'
    PORTB   EQU	h'06'
 
;----------------------------------------------------------------------
; starts the program from this address

    ORG 0x00
   
;----------------------------------------------------------------------
; This is basically SETUP block of our program
	
    CLRF    PORTB   ; Reset the initial value of the register 
    BSF	    STATUS, 5	; Move to BANK1
    BCF	    STATUS, 6	; Move to BANK1
    CLRF    TRISB   ; Set the B pins as output
    BCF	    STATUS, 5	; Go back to BANK0
    BCF	    STATUS, 6	; Go back to BANK0
    
	
;----------------------------------------------------------------------
; The program execution block (main program flow block)
	
START
    
    BSF	PORTB, 0    ; Turn on the LED (RB0)
	
;----------------------------------------------------------------------
; Ending the program
	
LOOP
    
    GOTO LOOP
    END
	
;----------------------------------------------------------------------
 