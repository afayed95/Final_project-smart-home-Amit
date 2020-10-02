#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include "M_uart.h"
#include "M_spi.h"
# define LED_2 3
char dataI;
ISR(USART_RXC_vect){
    
    dataI = UDR;                     //RECIEVE INTERRUPT
    //while((UCSRA & (1<<RXC)));      //wait to recieve data
    SPI_write(dataI);//send data by SPI   
    
    if (dataI == 'Q') {              ///Just a test/Just a test 
        PORTD |= (1 << LED_2);      
    }                               
    else if (dataI == 'P') {         ///Just a test/Just a test 
        PORTD &= ~(1 << LED_2);     
    }                               
    
    
}
int main(void) {
    DDRD |= (1<<LED_2);
    PORTD |=(1<<LED_2);
    UART_init();//Uart initialization
    SPI_init(Master, F_PS128);//SPI initialization
    
    sei(); //  Global interrupt
    while (1) {
    
    }
    return 0;
}

