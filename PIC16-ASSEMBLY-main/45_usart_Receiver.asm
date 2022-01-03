;   bilgisayardan rx pinine ascii kodlu karakterler gonderiliyor
;   bu 8 bit karakterler rb4-5-6-7 ve ra0-1-2-3 teki ledlerde gosteriliyor

    
    LIST P =16F628A
    #include "p16f628a.inc"

; CONFIG
; __config 0x3F38
 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF


    ORG	    H'0000'
    MOVLW   H'07'
    MOVWF   CMCON
    CLRF    PORTA
    CLRF    PORTB
    BANKSEL TRISA
    MOVLW   H'F0'	; RA0~RA3 AS OUTPUT
    MOVWF   TRISA
    MOVWF   B'00000010'	; RX INPUT
    
    MOVLW   D'25'	; 9600 BAUND RATE
    MOVWF   SPBRG
    
    MOVLW   B'00000100' ; SYNC=0, BRGH=1
    MOVWF   TXSTA
    
    BANKSEL PORTB
    MOVLW   B'10010000'	; SPEN=1, CREN=1
    MOVWF   RCSTA
    
LED_GONDER
    CALL    VERI_AL
    MOVWF   PORTA
    MOVWF   PORTB
    GOTO    LED_GONDER
    
    
VERI_AL
    BTFSS   PIR1,RCIF	; RCIF is 1 ?
    GOTO    VERI_AL
    MOVWF   RCREG,W
    RETURN
    
    
END
    