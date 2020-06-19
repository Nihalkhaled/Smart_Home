#include <xc.h>
#include"mSPI.h"
#define LED0    2
#define LED1    7



void SPI_init()
{
    DDRB |=(1<< MISO);
    SPCR |= (1<<SPE)|(1<<SPIE)|(1<< SPR0)|(1<<SPR1);//Enable SPI comm protocol, Enable SPI Interrupt 
                                                    //SPI Clock Rate selectors  
}

void SPI_read(){
    unsigned char data = SPDR;
    if     (data == '1'){ //LED0 0N
        PORTC |= (1 << LED1);
     }
    else if(data == '2'){ //LED0 OFF
        PORTC &= ~(1 << LED1);
        }
    else if(data == '3'){ //LED1 0N
        PORTC |= (1 << LED0);
    }
    else if(data == '4'){ //LED1  0FF
        PORTC &= ~(1 << LED0);
    }
    else{
    }
}

