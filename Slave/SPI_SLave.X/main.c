/*
 * File:   main.c
 * Author: NIHAL KHALED
 *
 * Created on May 15, 2020, 5:09 PM
 */

#define F_CPU 16000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include "mSPI.h"


ISR(SPI_STC_vect) {
    SPI_read();
}


int main(void) {
    DDRC |= 0xFF;
    SPI_init();//SPI Slave initiation
    sei(); // Enable global interrupt
    while (1) {
   

    }
}

