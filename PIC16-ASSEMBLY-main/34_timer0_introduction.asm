;   program :	
;    date :	OCT, 2020
;  written by :	ENES MERCAN
;  scenerio :	2 leds on rb0 and rb1 will blink with 1 second time delay
;   purpose :	using timer0
;
;----------------------------------------------------------------------
; Note :
;   Kritik aciklama :
;   Goruldugu uzere programda 1 saniyede bir ledleri yakmasi beklenmektedir.
;   Ancak program aslinda 73. satirda sonsuz donguye giriyor. Ayrica 88. sat-
;   irda kullanilan degisken hic ilk degerine geri dondurulmuyor. Oyleyse,
;   program nasil surekli 1sn yakip sondurebilir.
;
;   program, kesme olusana kadar sonsuz dongudedir. Kesme olusunca 47. satira
;   gecer ve oradan interrupt alt programina dallanir.
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
    GOTO    INTERRUPT_HANDLER
    
    
;----------------------------------------------------------------------
; This is basically SETUP block of our program
	
    
START    
    
    COUNT_10MS	EQU H'20'
	
    CLRF    PORTB
    BANKSEL TRISB
    CLRF    TRISB
    
    ; setups below for timer0 
    MOVLW   B'00000111'
    MOVWF   OPTION_REG	    ; set prescaler to 1/256 division
    
    BCF	    OPTION_REG,5    ; timer0 will use internal clock source
    BSF	    INTCON,7	    ; enable global interrupts
    BSF	    INTCON,5	    ; enable timer0 interrupts
    
    ; setup leds
    BSF	    PORTB, 0
    BCF	    PORTB, 1
	
LOOP
    GOTO    LOOP
    
    
;----------------------------------------------------------------------
; interrupt handler

    
INT_HANDLER
    
    BCF	    INTCON,2	; clear timer0 flag
    
    MOVLW   H'D9'
    MOVWF   TMR0	; start counting from 217
    
    INCF    COUNT_10MS	; 
    MOVLW   D'100'
    SUBWF   COUNT_10MS,W
    BTFSS   STATUS,Z
    GOTO    END_INT
    
    MOVLW   B'00000011'
    XORWF   PORTB,F
    
    END_INT
    
    CLRF    COUNT_10MS
    
RETFIE
    
	
;----------------------------------------------------------------------
; Ending the program
	
ENDING
    
    GOTO ENDING
    END
	
;----------------------------------------------------------------------
 