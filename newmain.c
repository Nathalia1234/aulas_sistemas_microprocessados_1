/*
 * File:   newmain.c
 * Author: Nathália Ohana
 *
 * Created on 25 de Março de 2020, 22:24
 */

#define _XTAL_FREQ 2000000

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// O OBJETIVO FOI CONFIGURAR AS PORTAS COMO SAÍDA 
// E LOGO APÓS COLOCAR ZERO NAS PORTAS. 
// ESSAS PORTAS ESTÃO ROTEADAS ATÉ OS LEDS CADA UMA DELAS
#include <xc.h>

void main(void) {
    // ACESSA O REGISTRADOR DE FUNÇÃO ESPECIAL
    // FOI CONFIGURADO A "PORTA B" COMO SAÍDA
    // O ZERO É ATRIBUIDO PARA CONFIGURAR A PORTA COMO SAÍDA
    TRISB = 0x00;
    
    // FOI CONFIGURADO A "PORTA D" COMO SAÍDA
    TRISD = 0x00;
    
    // COLOCANDO O ZERO NAS PORTAS 
    PORTB = 0x00;
    PORTD = 0x00;
    
    while (1) {
        // ---------------- PORTA B ------------------------
        // função que faz os leds ficarem meio segundo
        // ligado e meio segundo desligado 
        __delay_ms(500);
        // ACESSAR AS INFORMAÇÕES DE BIT A BIT 
        // LIGA LED DA PORTA B
        PORTBbits.RB1 = 1;
         __delay_ms(500);
        // DESLIGA LED DA PORTA B
        PORTBbits.RB1 = 0;      
        
        
        // ----------PORTA D---------------------------
         __delay_ms(500);
          // LIGA LED DA PORTA D
        PORTDbits.RD1 = 1;
        __delay_ms(500);
         // DESLIGA LED DA PORTA D
        PORTDbits.RD1 = 0;         
    }
    return;
}
