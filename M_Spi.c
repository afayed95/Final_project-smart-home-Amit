#include <xc.h>
#include "M_Spi.h"
#include "M_uart.h"

void SPI_init(int SPI_Mode, char Prescaler)
{
    DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS); // Declaring those pins as outputs.
    DDRB &= ~(1<<6); // MISO INPUT
    SPCR |= ( 1 << MSTR)|(1<<SPE)|(1<< SPR0)|(1<<SPR1);//Enable master mode, SPI comm protocol,
                                                       //SPI Clock Rate selectors   
}

void SPI_write(unsigned char data )
{   
    SPDR = data;// Send data ,SPIF flag =1 when serial transmisssion is complete
    while (!(SPSR & (1<<SPIF)));// It waits until SPIF flag IS SET  
    
}
