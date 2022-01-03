;   RA0 butonuna her basildiginda bilgisayara veri yollamak

    
    LIST P =16F628A
    #include "p16f628a.inc"

; CONFIG
; __config 0x3F38
 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF


    ORG	    H'0000'
    SAYAC   EQU H'20'
    SAYAC1  EQU	H'21'
    SAYAC2  EQU	H'22'
   
   MOVLW    H'07'
   MOVWF    CMCON
   CLRF	    PORTB
   CLRF	    PORTA
   BANKSEL  TRISA
   MOVLW    H'FF'
   MOVWF    TRISA
   MOVLW    B'11111011'	;   RB1/RX = INPUT  , RB2/TX = OUTPUT
   MOVWF    TRISB
   MOVLW    D'25'	;   9600 BAUND RATE
   MOVWF    SPBRG
   MOVLW    B'00100100'	;   BRGHT=1, TXEN=1
   MOVWF    TXSTA
   BSF	    RCSTA,7	;   SPEN=1 serial port enabled

   
;   wait little bit
LOOP
   DECFSZ   SAYAC,F
   GOTO	    LOOP
   
TEST_RA0
   BTFSS    PORTA,0
   CALL	    MESSAGE
   CALL	    DELAY	 ;  delay for button arc
   GOTO	    TEST_RA0	 ;  test again
   
   
   
MESSAGE
   BSF	    PORTB,2	 ;  pull tx pin high
   MOVLW    'E'
   MOVWF    SEND	 ; send the character
   MOVLW    'N'
   MOVWF    SEND	 ; send the character
   MOVLW    'E'
   MOVWF    SEND	 ; send the character
   MOVLW    'S'
   MOVWF    SEND	 ; send the character
   MOVLW    ' '
   MOVWF    SEND	 ; send the character
   MOVLW    'M'
   MOVWF    SEND	 ; send the character
   MOVLW    'E'
   MOVWF    SEND	 ; send the character
   MOVLW    'R'
   MOVWF    SEND	 ; send the character
   MOVLW    'C'
   MOVWF    SEND	 ; send the character
   MOVLW    'A'
   MOVWF    SEND	 ; send the character
   MOVLW    'N'
   MOVWF    SEND	 ; send the character
RETURN
   
   
   
SEND	;   manages sending data from TXREG to TSR (transmitter shift reg.)
   MOVWF    TXREG
   BANKSEL  TXSTA   ; go to bank1
   
   TEST_COM    ; test data complately done
   BTFSS    TXSTA,TRMT
   GOTO     TEST_COM
   BANKSEL  PORTB
RETURN
   

DELAY
    MOVLW   H'FF'
    MOVWF   SAYAC1
    LOOP1
    MOVLW   H'FF'
    MOVWF   SAYAC2
    LOOP2
    DECFSZ  SAYAC2,F
    GOTO    LOOP2
    DECFSZ  SAYAC1,F
    GOTO    LOOP1
RETURN
    
END