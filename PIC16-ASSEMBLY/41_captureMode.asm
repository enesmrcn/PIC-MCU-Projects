; rb3 pinine bagli osilatorun frekans degerini rb4, rb5, rb6, rb7 de gosterir
    
LIST P = 16F628A
#include "p16f628a.inc"

; CONFIG
; __config 0x3F30
 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_ON & _MCLRE_ON & 
    _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF

    LEDS    EQU	H'20'
    ORG	    H'0000'
    GOTO    START
    ORG	    H'0004'
    GOTO    INT_HANDLER
    
    
START
    CLRF    PORTB
    BANKSEL TRISB
    MOVLW   B'00000100'	; rb3 is input for ccp1 module
    MOVWF   TRISB
    BSF	    PIE1,2	; CCP ints enabled
    BANKSEL PORTB
    
    MOVLW   B'00000101'	;   every falling-edge
    MOVWF   CCP1CON	;   capture mode
    
    MOVLW   B'00000001'	;   tmr1 starts working
    MOVLW   T1CON	;   Fosc/4, presacler 1/1
    
    MOVLW   H'C0'	;   GIE=1, PEIE=1
    MOVWF   INTCON
    
    CLRF    LEDS	; reset LEDS
    
    
INFINITE
    GOTO    INFINITE
    

    
INT_HANDLER
    CLRF    TMR1L	; start TMR1 from 0
    CLRF    TMR1H
    BCF	    INTCON,GIE	; kesme alt prog bitmeden, yeni int kabul edilmesin
    
    MOVLW   H'00'       ; rb3 freq is lower than 39,06 KHz
    MOVWF   LEDS
    
    MOVLW   D'100'      ; W=48,82 KHz
    SUBWF   CCPR1H,W	; W=CCP1H-W
    BTFSC   STATUS,C	; CPP1H<80? (DOGRUYSA C=0 DIR)
    GOTO    ANA_PROG_DON
    
    MOVLW   B'00110000'	; 48<Frb3<65
    MOVWF   LEDS
    MOVLW   D'60'
    SUBWF   CCPR1H,W
    BTFSC   STATUS,C
    GOTO    ANA_PROG_DON
    
    MOVLW   B'01110000'	; 65<Frb3<97kHZ
    MOVWF   LEDS
    MOVLW   D'40'
    SUBWF   CCPR1H,W
    BTFSC   STATUS,C
    GOTO    ANA_PROG_DON
    
    MOVLW   B'11110000'	; RB3 FREKANSI > 97Khz
    MOVLW   LEDS
    
    
ANA_PROG_DON
    MOVWF   LEDS,W
    MOVWF   PORTB
    BCF	    PIR1,2  ; clear CPP1IF for new coming ints
    
    BSF	    INTCON,GIE	; enable all ints
    
RETFIE
    
END