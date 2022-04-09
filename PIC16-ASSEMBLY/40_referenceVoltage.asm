; the same program with previous one. We'll assign our own ref value here
; . . . .
; ra2 pinine bagli pot reference voltage olarak kullaniliyor
; ra0 pinine bagli ldr var
; ra1 pinine bagli pot bulunuyor
; ra0 ve ra1 pinlerinin gerilimleri (ra2 referansi ile) karsilastiriliyor
; rb6 daki led ra0 ve ra2 ayni olunca yanacak
; rb7 ledi ra1 ve ra2 ayni esit olunca yanar
    
    
LIST P=16F628A
LIST P = 16F628A
; CONFIG
; __config 0x3F34
 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_ON & _MCLRE_ON
	& _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF

;-----------------------------------------------------------------------

    ORG H'0000'

    CLRF	PORTB
    MOVLW	B'00010011' ; C2 inverter mod=011
    MOVWF	CMCON
    BANKSEL	TRISB
    CLRF	TRISB
    MOVLW	B'10001011' ; VREF=2.97V, VREN=1, VREO=0, VRR=0
    MOVWF	VRCON
    BANKSEL	PORTB

C2_KONTROL
    BTFSC	CMCON,7
    GOTO	RB7_YAK
    
C1_KONTROL
    BTFSC	CMCON,6
    GOTO	RB6_YAK
    BCF		PORTB,6
    BCF		PORTB,7
    GOTO	C2_KONTROL

RB6_YAK
    BSF		PORTB,6
    GOTO	C2_KONTROL
    
RB7_YAK
    BSF		PORTB,7
    GOTO	C1_KONTROL
    
    
END