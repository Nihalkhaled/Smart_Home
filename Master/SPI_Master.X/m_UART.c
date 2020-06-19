/*
 * File:   m_UART.c
 * Author: NIHAL KHALED
 *
 * Created on May 7, 2020, 6:06 PM
 */
#include <avr/io.h>
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/interrupt.h>



void UART_init() {
    UCSRB |= (1 << TXEN); // Enable Transmitter
    UCSRB |= (1 << RXEN); // Enable Receiver
    UCSRB |= (1 << RXCIE); // Enable RXC Interrupt
    UBRRL = 103; //BaudRate 9600 bps
}


void transmitChar(char data) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}

void transmitString(char *data) {
    for (int i = 0; data[i] != '\0'; i++) {
        transmitChar(data[i]);
    }}
