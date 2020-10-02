#include <xc.h>
#include <util/delay.h>
#include"M_spii.h"
#define LED0    2
#define LED1    7



void SPI_init()
{
    DDRB |=(1<< MISO); //and others 're i/p =0 
    SPCR |= (1<<SPE)|(1<<SPIE)|(1<< SPR0)|(1<<SPR1);//SPI ENABLE,prescaler 128/Enable SPI Interrupt 
    SPCR &= ~(1<<MSTR); //slave                                                 
}
char SPI_SLAVE_RECIEVE()
{  
    
    while(!(SPSR &(1<<SPIF))); // wait to receive
    return SPDR ;
}

void SPI_scan(){
    unsigned char data =SPI_SLAVE_RECIEVE();
    //unsigned char data =SPDR;
    if     (data == 'A'){ //LED0 0N
        PORTC |= (1 << LED1);
     }
    else if(data == 'B'){ //LED0 OFF
        PORTC &= ~(1 << LED1);
        }
    else if(data == 'X'){ //LED1 0N
        PORTC |= (1 << LED0);
    }
    else if(data == 'Y'){ //LED1  0FF
        PORTC &= ~(1 << LED0);
    }
    else{
        PORTD ^=(1<<3); 
}
}
