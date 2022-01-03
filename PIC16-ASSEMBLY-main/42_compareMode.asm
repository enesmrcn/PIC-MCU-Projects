;   CCPR1H ve CPPR1L lara h'F0F0' (D'61680') sayisi yuklendikten sonra
;   TMR1 calistirilir. TMR1 bu sayiya her ulastiginda olusan kesme ile 
;   PORTB deki 8 led belirli araliklarla yakip sondurulur.
    

    LIST P = 16F628A
    #include "p16f628a.inc"

    ; CONFIG
    ; __config 0x3F38
     __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_OFF & 
	_MCLRE_ON & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF

 
    LED_STATUS  EQU H'20'
	
	ORG     H'0000'
	GOTO	START
	ORG     H'0004'
	GOTO	INT_HANDLER
	
    START
	CLRF	PORTB
	BANKSEL	TRISB
	CLRF	TRISB
	BSF	PIE1,2	; Enable CCP interrupts
	BANKSEL	PORTB
	
	MOVLW	H'C0'	;   GIE=1, PEIE=1
	MOVWF	INTCON
	
	MOVLW	H'F0'
	MOVWF	CCPR1H
	
	MOVLW	B'00001011' ;	esitlik durumundaki kesmede
	MOVWF	CCP1CON	    ;	RB3 degismez, TMR1 resetlenir
	
	MOVLW	B'01100001' ;	TMR1 calismaya baslar
	MOVWF	T1CON	    ;	Prescaler 1/8 , internal clock source
	
	BSF	LED_STATUS, 0
	
    INFINITE
	GOTO	INFINITE
	
	
	
    INT_HANDLER
	BCF	INTCON,GIE
	
	BCF	PIR1, 2
	
	BTFSS	LED_STATUS,0
	GOTO	SONDUR
	
	YAK
	MOVLW	H'FF'
	MOVWF	PORTB
	BSF	LED_STATUS, 0
	BSF	INTCON,GIE
    RETFIE
    
    
    SONDUR
	MOVLW	H'00'
	MOVWF	PORTB
	BCF	LED_STATUS, 0
	BSF	INTCON,GIE
    RETFIE
    
    
    END