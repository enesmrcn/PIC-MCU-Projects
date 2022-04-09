;   program :	
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	
;   purpose :	
;
;----------------------------------------------------------------------
; Note :
;   
;
;----------------------------------------------------------------------  
; indicate what pic we're using to the complier    
    
    

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
	
    ORG	H'0000'

;----------------------------------------------------------------------
; This is basically SETUP block of our program
	
    
    
	
;----------------------------------------------------------------------
; The program execution block (main program flow block)
	
START
    
 
    
    
;----------------------------------------------------------------------
; functions
	

    
    

;----------------------------------------------------------------------
; interrupt handler

    
    
	
;----------------------------------------------------------------------
; Ending the program
	
ENDING
    
    GOTO ENDING
    END
	
;----------------------------------------------------------------------
 