/*
 * File:   MainS.c
 * Author: Toshiba
 *
 * Created on 26 ??????, 2020, 07:56 ?
 */


#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include "M_spii.h"
#define LED0    2
#define LED1    7

ISR(SPI_STC_vect) {;
    SPI_scan();
//unsigned char data =SPDR;
//    if     (data == 'A'){ //LED0 0N
//        PORTC |= (1 << LED1);
//     }
//    else if(data == 'B'){ //LED0 OFF
//        PORTC &= ~(1 << LED1);
//        }
//    else if(data == 'X'){ //LED1 0N
//        PORTC |= (1 << LED0);
//    }
//    else if(data == 'Y'){ //LED1  0FF
//        PORTC &= ~(1 << LED0);
//    }
//    else{
//        PORTD ^=(1<<3); 
}
    



int main(void) {
    DDRC = 0xFF;
    DDRD = 0xFF;
    //PORTA |=(1<<3);

    SPI_init();
    sei(); 
    while (1) {
   

    }
}
