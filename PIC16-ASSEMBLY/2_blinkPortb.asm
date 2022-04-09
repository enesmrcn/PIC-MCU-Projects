;   program :	program_2.asm
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	Turning on the LEDs connected to RB0, RB1, RB2, RB3
;   purpose :	using W register to transfer data
;----------------------------------------------------------------------
    
; indicate what pic we're using to the complier    


;----------------------------------------------------------------------
;setting the addresses for the PIC
	
STATUS	EQU 0x03    ; '0x' notation means that it is hex number
PORTB	EQU 0x06    ; for binary use : '0b' --> PORTB EQU 0b00000110
TRISB	EQU 0x86    ; for decimal use : PORTB EQU 3
 
;----------------------------------------------------------------------
; starts the program from this address
	
ORG 0x00

;----------------------------------------------------------------------
; This is basically SETUP block of our program
	
START
	CLRF	PORTB	; Reset inherited register information
	BSF	STATUS, 5   ; Go to BANK1
	CLRF	TRISB	; Set PORTB as output
	BCF	STATUS, 5   ; Go back to BANK0
	
;----------------------------------------------------------------------
; The program execution block (main program flow block)
	
	MOVLW	0x0F	; Load working register with 00001111
	MOVWF	PORTB	; Transfer from Wroking register to PORTB reg.
	
;----------------------------------------------------------------------
; Ending the program
	
PROGRAM
	GOTO PROGRAM
	END
	
;----------------------------------------------------------------------
 