
#include <avr/io.h>
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>



void UART_init() {
    UCSRB |=(1 << RXEN); // Enable Receiver
    UCSRB |=(1 << RXCIE) ;   // Enable RXC Interrupt
    UCSRB |=(1<<TXEN);     // Enable Transmitter
    UCSRB &=~(1<<TXCIE);     // Disable  TRANSMITER INTERRUPT  
    UBRRL = 103; // 16 MHZ --BaudRate 9600 BPS 
}


void transmitChar(char data) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}
char uart_recieve()
{
    while(!(UCSRA & (1<<RXC))); //wait until be received
    return UDR ;
} 


void transmitString(char *data) {
    for (int i = 0; data[i] != '\0'; 
            i++) {
        transmitChar(data[i]);
    }}
