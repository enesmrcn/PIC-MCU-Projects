;   program :	
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	
;   purpose :	learning
;
;----------------------------------------------------------------------
; Note :
;   
;
;----------------------------------------------------------------------  
; indicate what pic we're using to the complier    
    
    

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
    BANKSEL PORTA
    
    COUNT1  EQU	H'20'	;   for time loop1
    COUNT2  EQU	H'21'	;   for time loop2
    COUNT3  EQU	H'22'	;   counts betw 0~6
    
	
;----------------------------------------------------------------------
; The program execution block (main program flow block)
	
START
    
    
  
	
;----------------------------------------------------------------------
; Ending the program
	
ENDING
    
    GOTO ENDING
    END
	
;----------------------------------------------------------------------
 