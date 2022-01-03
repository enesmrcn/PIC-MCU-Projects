;   2 LEDs on rb0 and rb1 will blink every one second using timer2 module
;   while led on rb3 continuously blinking once every half second
;   timer2 will count from 0 to 39h for about 100 times
    
    
    
LIST P = 16F628A
INCLUDE "P16F628A.INC"
    
; CONFIG
; __config 0x3F30
 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_ON & _MCLRE_ON
    & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF

    
    COUNT10MS	EQU H'20'
    ORG	    H'0000'
    GOTO    SETUP
    ORG	    H'0004'
    GOTO    INT_HANDLER
    
    
START
    
    
    CLRF    PORTB
    BANKSEL TRISB
    CLRF    TRISB
    BSF	    PIE1,1	; TMR2IE
    
    MOVLW   H'39'
    MOVWF   PR2
    
    BANKSEL PORTB
    
    MOVLW   B'01111111'
    MOVWF   T2CON
    BCF	    PIR1,1	; TMR2IF
    BSF	    INTCON,7	; GIE
    BSF	    INTCON,6	; PEIE
    
    BSF	    PORTB,0
    BCF	    PORTB,1
    
REPEAT
    MOVLW   B'00001000'
    XORWF   PORTB,F
    
    GOTO    REPEAT
    
    END
    
    
    
INT_HANDLER
    
    BCF	    PIR1,1
    
    
    MOVLW   D'100'
    INCF    COUNT10MS
    SUBWF   COUNT10MS,F
    BTFSS   STATUS,2
    GOTO    EXIT
    
    MOVLW   B'00000011'
    XORWF   PORTB,F
    CLRF    COUNT10MS
    
    EXIT
    
RETFIE  