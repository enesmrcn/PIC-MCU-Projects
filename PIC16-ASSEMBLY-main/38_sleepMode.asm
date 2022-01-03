;   PIC'e enerji verince rb0,rb2,rb3,rb1 ledlerinde 00h dan FFh a binary
;   artan sayilar gorulur. FFh a gelince tekrardan sayar. RA0 butonuna basica
;   ledler soner ve uyku moduna girer.Uyku modundan cikmak icin RB kesmesi
;   kullanilir. Sleep'ten uyaninca kaldigi yerden devam eder.
    
    
LIST P = 16F628A
; CONFIG
; __config 0x3F34
 __CONFIG _FOSC_INTOSCIO & _WDTE_ON & _PWRTE_ON & _MCLRE_ON
	& _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF

;-----------------------------------------------------------------------

SAYAC1	EQU  H'20'
SAYAC2	EQU  H'21'	
	
ORG	H'0000'
GOTO	START
ORG	H'0004'
GOTO	KESME
	
	
START
	CLRF	PORTB
	BANKSEL	TRISB
	MOVLW	H'F0'
	MOVWF	TRISA
	BANKSEL	PORTA
	MOVLW	H'07'
	MOVWF	CMCON
	BSF	INTCON,7    ;	GIE enabled
	BSF	INTCON,3    ;	PB enabled
	
SAY
	BTFSS	PORTA,0
	CALL	UYU
	INCF	PORTB,F
	CALL	GECIKME
	GOTO	SAY

UYU
	MOVWF	PORTB,W
	CLRF	PORTB
	SLEEP
	NOP
	MOVWF	PORTB
    RETURN
	
KESME
	BCF	INTCON,7    ; kesme calisirken diger kesmeleri engelle
	
	; buraya interrupt sub-program komutlari yazilabilir
	; biz simdilik kullanmiyoruz
	
	BCF	INTCON,0    ;	RBIF
	BCF	INTCON,7    ;	GIE enabled back
	
    RETFIE
	
	
GECIKME
	MOVLW	H'FF'
	MOVWF	SAYAC1
    LOOP1
	MOVLW	H'FF'
	MOVWF	SAYAC2
    LOOP2
	DECFSZ	SAYAC2,F
	GOTO	LOOP2
	DECFSZ	SAYAC1,F
	GOTO	LOOP1
    RETURN
	
	
END
	