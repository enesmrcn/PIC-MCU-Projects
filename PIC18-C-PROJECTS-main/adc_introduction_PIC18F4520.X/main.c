/*
 * File:   main.c
 * Author: enes
 *
 * Created on 10 October 2021, 11:37
 */

#define ADC_RES (5.0/1023.0)
#define _XTAL_FREQ  8000000

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "config.h"


void uart_init(uint16_t gen_reg, unsigned sync,unsigned brgh, unsigned brg16){
    
    TRISCbits.RC7=1;
    TRISCbits.RC6=1;
    
    SPBRGH = (gen_reg & 0xFF00) >> 8;
    SPBRG = gen_reg & 0x00FF;
    
    RCSTAbits.CREN = 1;
    RCSTAbits.SPEN = 1;
    BAUDCONbits.BRG16 = brg16;
    
    TXSTAbits.SYNC = sync;
    TXSTAbits.BRGH = brgh;
    TXSTAbits.TXEN = 1;
    
    IPR1bits.RCIP=1;
    PIE1bits.RCIE=1;  
}

void uart_send(uint8_t *c){
    TXREG=*c;
    while(TXSTAbits.TRMT==0){
        Nop();
    }
}

void uart_receiver(uint8_t *c, bool *rx_flag){
    
    if(RCSTAbits.FERR){
        uint8_t er = RCREG;
    }else if(RCSTAbits.OERR){
        RCSTAbits.CREN=0;
        RCSTAbits.CREN=1;
    }else{
        *c = RCREG;
        *rx_flag = true;
    }
    
}

void uart_send_array(uint8_t *c,uint16_t len){
    for(uint8_t i = 0; i < len;i++){
        uart_send(&c[i]);
    }
}

void uart_send_string(uint8_t *c){
    uint8_t i=0;
    while(c[i] != '\0'){
        uart_send(&c[i]);
        i++;
    }
}


uint8_t data = 0;
bool got_data_bool = false;
uint8_t print_buffer[256] = {0};

uint16_t adc_to_led = 0;

float adc_volt = 0.0;

void __interrupt() high_isr(void);
void __interrupt(low_priority) low_isr(void);

void main(void) {

    /*
    OSCCONbits.IRCF = 0x07;
    OSCCONbits.SCS = 0x03;
    while(OSCCONbits.IOFS!=1);
    */
    TRISD=0;
    LATD=0;
    uart_init(51,0,1,0);//baud 9600
    
    TRISAbits.RA0 = 1;
    
    ADCON1bits.VCFG0 = 0;
    ADCON1bits.VCFG1 = 0;
    ADCON1bits.PCFG = 0x0E;
    
    ADCON2bits.ADFM = 1;
    ADCON2bits.ACQT = 0x04;
    ADCON2bits.ADCS = 0x04;
    
    ADCON0bits.CHS = 0;
    ADCON0bits.ADON = 1;
    
    RCONbits.IPEN = 1;
    INTCONbits.GIEH = 1; 
    INTCONbits.GIEL = 1;
    
    while(1){
        ADCON0bits.GODONE = 1;
        while(ADCON0bits.GODONE);
        sprintf(print_buffer,"\rADC Read: 0x%02x%02x\t",ADRESH,ADRESL);
        uart_send_string(print_buffer);
        
        adc_to_led = (ADRESH << 6) | (ADRESL >> 2);
        LATD = adc_to_led;
       
        adc_to_led = (ADRESH << 8) | (ADRESL);
        
        adc_volt = adc_to_led * ADC_RES;
        sprintf(print_buffer,"ADC Volt: %.2f\t",adc_volt);
        uart_send_string(print_buffer);
       
    } 
}

void __interrupt() high_isr(void){
    
    if(PIR1bits.RCIF){
        uart_receiver(&data,&got_data_bool);
       PIR1bits.RCIF=0;
    }
    
}

void __interrupt(low_priority) low_isr(void){
    
}

