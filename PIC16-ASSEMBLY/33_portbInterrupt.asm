;   program :	
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	led connected to ra3 blinking countuniously
;		buttons on rb4~rb7, leds on rb0~rb3
;		push the buttons, show them with leds (portb leds)
;   purpose :	using portB external interrupt
;
;----------------------------------------------------------------------
; Note :
;   
;
;----------------------------------------------------------------------  
; indicate what pic we're using to the complier    
    
    LIST P = 16F628A
    INCLUDE "P16F628A.INC"

;----------------------------------------------------------------------
;configuration bits
	
    __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_ON & 
    _MCLRE_OFF & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF

 
    ;_FOSC_INTOSCIO	--> internal oscillator
    ;_WDT_OFF	--> watchdog timer off
    ;_PWRTE_ON	--> power up timer is on (will wait 72ms when powered)
    ;_MCLRE_OFF	--> external reset disabled
    ;_BODEN_OFF --> low voltage protection is off (diff to handle for beginners)
    ;_LVP_OFF	--> low power programming is disabled
    ; _DATA_CP_OFF  --> no eeprom data protection (it's readable)
    ;_CP_OFF	--> no rom code protection (anyone can read)
    
    
;----------------------------------------------------------------------
; starts the program from this address
	
    ORG	    H'0000'
    GOTO    SETUP
    ORG	    H'0004'
    GOTO    INT_HANDLER

;----------------------------------------------------------------------
; This is basically SETUP block of our program

SETUP
    
    CLRF    PORTB
    CLRF    PORTA
    BANKSEL TRISB
    MOVLW   H'F0'	; rb0~rb3 output, rest.. input
    MOVWF   TRISB
    CLRF    TRISA
    BCF	    INTCON,3	; clear portB interrupt flag
    
    BSF	    INTCON,7	; enable global interrupts
    BSF	    INTCON,3	; enable portB interrupts
    
    BANKSEL PORTA
    
    EQU	COUNT1	H'20'
    EQU	COUNT2	H'21'
	
;----------------------------------------------------------------------
; The program execution block (main program flow block)
	
START
    
    BSF	    PORTA,3
    CALL    DELAY
    BCF	    PORTA,3
    CALL    DELAY
    
    GOTO    START
    
    
;----------------------------------------------------------------------
; functions

    
DELAY
    
    MOVLW   H'FF'
    MOVWF   COUNT1
    
    LOOP1
    MOVLW   H'FF'
    MOVWF   COUNT2
    
    LOOP2
    BTFSC   COUNT2
    GOTO    LOOP2
    BTFSC   COUNT1
    GOTO    LOOP1
    
RETURN
    

;----------------------------------------------------------------------
; interrupt handler

    
INT_HANDLER    
    
    BCF	    INTCON,0	; disable portb interrupts
    
    SWAPF   PORTB, F
    
RETFIE
	
;----------------------------------------------------------------------
; Ending the program
	
INFINITE
    
    GOTO INFINITE
    END
	
;----------------------------------------------------------------------
 