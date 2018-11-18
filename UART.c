


typedef unsigned char uint8_t;

#define F_CPU 8000000UL

#define UDR		*(volatile uint8_t *) 0x2C // UART DATA REGISTER
#define UBRRH 	*(volatile uint8_t *) 0x40 // UART BAUD RATE REGISTER HIGH
#define UBRRL 	*(volatile uint8_t *) 0x29 // UART BAUD RATE REGISTER LOW

#define UCSRA 	*(volatile uint8_t *) 0x2B //UART CONTROL AND STATUS REGISTER A
#define UDRE  5	//UART Data Register Empty
#define RXC  7  //UART Receive Complete

#define UCSRB 	*(volatile uint8_t *) 0x2A //UART CONTROL AND STATUS REGISTER B
#define TXEN  3	//Transmitter Enable
#define RXEN  4 //Receiver Enable

#define UCSRC 	*(volatile uint8_t *) 0x40 //UART CONTROL AND STATUS REGISTER C
#define URSEL  7 //UART REGISTER SELECT
#define UCSZ0  1 //UART CHARCHTER SIZE 0
#define UCSZ1  2 //UART CHARCHTER SIZE 0



#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUD 9600                                   // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // set baud rate value for UBRR
uint8_t i = 65;


void uart_init ()
{
    UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
    UBRRL = BAUDRATE;                           // set baud rate
    UCSRB|= (1<<TXEN)|(1<<RXEN);                // enable receiver and transmitter
    UCSRC|= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);   // 8bit data format
}


void uart_transmit (uint8_t data)
{
    while (!( UCSRA & (1<<UDRE)));                // wait while register is free
    UDR = data;                                   // load data in the register
}

uint8_t uart_recieve ()
{
    while(!(UCSRA) & (1<<RXC));                   // wait while data is being received
    return UDR;                                   // return 8-bit data
}
ISR(INT0_vect)
{

}
void interrupts_init(){
	GICR = 1<<INT0;					// Enable INT0
	MCUCR = 1<<ISC01 | 1<<ISC00;	// Trigger INT0 on rising edge
	sei();				//Enable Global Interrupt
}

int main() {


	uart_init ();
  while(1){


  }
  return 0;
}


// $0A ($2A) UCSRB
// $09 ($29) UBRRL
// $0B ($2B) UCSRA
// $0C ($2C) UDR
// 20(2) ($40)(2) UBRRH UCSRC
