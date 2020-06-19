#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include "m_UART.h"
#include "mSPI.h"

ISR(USART_RXC_vect){
    SPI_write(UDR);//Uart receiver subroutine
}
int main(void) {
    UART_init();//Uart initiation
    SPI_init(Master, F_PS128);//SPI initiation
    
    sei(); // Enable global interrupt
    while (1) {
    
    }
    return 0;
}

