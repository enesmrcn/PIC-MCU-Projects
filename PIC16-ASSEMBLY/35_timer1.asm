; rb0 ve rb1 ledleri tmr1 ile 1sn de yanip sonsun.
; rb3 deki led her saniye delay ile yanip sonsun
    
LIST P = 16F628A
INCLUDE "P16F628A.INC"
    
; CONFIG
; __config 0x3F30
 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_ON & _MCLRE_ON &
    _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF
    
    

COUNT_20MS  EQU H'20'
ORG	H'0000'
GOTO	START
ORG	H'0004'
GOTO	INT_HANDLER
    
    
    
START
    
    
    CLRF    PORTB
    BANKSEL TRISB
    CLRF    TRISB
    
    BSF	    PIE1,0	    ; TMR1IE
    BANKSEL PORTB
    BCF	    PIR1,0	    ; TMR1IF
    BSF	    INTCON,7	    ; GIE
    BSF	    INTCON,6	    ; PEIE
    BSF	    T1CON,0	    ; TMR1ON
    BCF	    T1CON,1	    ; TMR1CS
    
    BSF	    PORTB,0
    BCF	    PORTB,1
    
LOOP
    MOVLW   B'00000100'
    XORWF   PORTB,F
    
GOTO    LOOP
    
    
 
    
INT_HANDLER
    
    BCF	    PIR1,0	    ; TMR1IF
    
    MOVLW   H'9E'
    MOVWF   TMR1H
    MOVLW   H'58'
    MOVWF   TMR1L
    
    INCF    COUNT_20MS
    MOVLW   D'100'
    
    SUBWF   COUNT_20MS,W
    BTFSS   STATUS,2
    GOTO    EXIT
    
    MOVLW   B'00000011'
    XORWF   PORTB,F
    CLRF    COUNT_20MS
    
    EXIT
    
RETFIE
    

    END