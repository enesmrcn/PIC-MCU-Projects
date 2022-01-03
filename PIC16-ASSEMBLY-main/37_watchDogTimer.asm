; ra0 butonuna 2.3 sn'yi gecmeyen araliklarla basildiginda rb0'daki
;   led'in devamli yanmasini saglar. Bu sureden saha uzun basildiginda WDT 
;   devreye girerek sistemi reset eder. Sistem reset olunca rb3'teki buzzer
;   uyari sesi verir. sonra program sonsuz donguye girer. MCLR basarak 
;   harici reset atilir
; 
LIST P = 16F628A
#include "p16f628a.inc"

; CONFIG
; __config 0x3F34
 __CONFIG _FOSC_INTOSCIO & _WDTE_ON & _PWRTE_ON & _MCLRE_ON
	& _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF

;-----------------------------------------------------------------------

	
ORG	H'0000'

SAYAC	EQU  H'20'

	
    CLRF	PORTB
    BANKSEL	TRISB
    CLRF	TRISB
    MOVLW	H'FF'
    MOVWF	TRISA
    BANKSEL	PORTB
    MOVLW	H'07'
    MOVWF	CMCON

    ;check WDT
    BTFSS	STATUS,4    ; T0 is zero?
    GOTO	BUZZER_SES  ; yes, wdt overflow occured
	
    
BASLA

    BANKSEL OPTION_REG
    CLRWDT
    MOVLW   B'00001111'	    ; WDT=ON, RESCALER=1/128
    MOVWF   OPTION_REG
    BANKSEL PORTB
    
    BTFSC   PORTA,0
    GOTO    RA0_TEST
    CLRWDT
    BANKSEL TRISB
    MOVLW   B'00001111'
    MOVWF   OPTION_REG
    BANKSEL PORTB
    BSF	    PORTB,0
    GOTO    RA0_TEST
    
BUZZER_SES
    CLRWDT
    BSF	    PORTB,3
    CALL    GECIKME
    BCF	    PORTB,3
    CALL    GECIKME
    GOTO    BUZZER_SES
    
GECIKME
    MOVLW   H'FF'
    MOVWF   SAYAC
    
LOOP
    DECFSZ  SAYAC,F
    GOTO    DONGU
    RETURN
    END