;   program :	
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	just practicing loop structures
;		counts from 0 to n      0-->n
;   purpose :	to learn delay loops
;		using	SUBWF
;		using	CARRY	Flag
;		using	ZERO	FLAG
;
;----------------------------------------------------------------------
; Note 1 :
;   A > B ... Z = 0 ,  C = 1		      A
;   A = B ... Z = 1 ,  C = 1		 _    B
;   A < B ... Z = 0 ,  C = 0		 ____________
;
;----------------------------------------------------------------------
; Note 2 :
;   This command means -->   SUBWF   NUMBER, W 
;   That :	W = NUMBER - W
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
	
    COUNTER EQU	H'20'
    
	
;----------------------------------------------------------------------
; The program execution block (main program flow block)
	
START
    
    CLRF    COUNTER
 
LOOP
    
    INCF    COUNTER, F	;	COUNTER = COUNTER + 1
    MOVLW   d'20'	;	W = 20
    SUBWF   COUNTER, W	;	W = COUNTER - W
    BTFSS   STATUS, 0	;	(counter = w) ????	<<carry flag>>
    GOTO    LOOP	;	NO! so, repeat until it is
    GOTO    START	;	YES! start over again
	
    END
    
;----------------------------------------------------------------------
; You can also use that rather :
;  
; BTFSS   STATUS, 2	;	(counter = w) ????	<<zero flag>>
;