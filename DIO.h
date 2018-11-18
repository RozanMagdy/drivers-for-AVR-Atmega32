#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h" 

/*Test Section*/
#define SETPORT(PORT,VALUE)	PORT = VALUE ;
#define CLEARPORT(PORT)		PORT = 0  ;
#define SP(X)	SETPORT(PORT,VALUE)
#define CP(X)	CLEARPORT(PORT)
#define SETBIT(PORT,X) PORT |= (1<<X)   ; // Sets a specific bit in a port with 1
#define CLEARBIT(PORT,X) PORT &=~(1<<x);// Clears a specific bit in a port
#define SB(PORT,X) SETBIT(PORT,X)
#define CB(PORT,X) CLEARBIT(PORT,X)
/*Private Section */
#define portA  *((volatile uint8_t*)(0x3B))
#define DDRA   *((volatile uint8_t*)(0x3A))
#define PINA   *((volatile uint8_t*)(0x39))
#define portB  *((volatile uint8_t*)(0x38))
#define DDRB   *((volatile uint8_t*)(0x37))
#define PINB   *((volatile uint8_t*)(0x36))
#define portC  *((volatile uint8_t*)(0x35))
#define DDRC   *((volatile uint8_t*)(0x34))
#define PINC   *((volatile uint8_t*)(0x33))
#define portD  *((volatile uint8_t*)(0x32))
#define DDRD   *((volatile uint8_t*)(0x31))
#define PIND   *((volatile uint8_t*)(0x30))

/*Configuration Section */

#define PORTA_INIT  0xff;
#define PORTB_INIT  0xff;
#define PORTC_INIT  0xff;
#define PORTD_INIT  0xff;
#define PORTA_VALUE  0xff;
#define PORTB_VALUE  0xff;
#define PORTC_VALUE  0xff;
#define PORTD_VALUE  0xff;

/*prototype section */
void DIO_vidInit(void);
void DIO_vidsetPortdirecton(uint8_t uint8_port,uint8_t uint8_direction);

void DIO_vidsetBitdirecton(uint8_t uint8_port,uint8_t uint8_bit,uint8_t uint8_direction);
void DIO_vidsetPORTvalue(uint8_t uint8_port,uint8_t uint8_value);
void DIO_vidsetBitvalue(uint8_t uint8_port,uint8_t uint8_bit,uint8_t uint8_value);
boolean DIO_bolreadpinvalue(uint8_t uint8_port, uint8_t uint8_bit);
void DIO_vidsetPORTmask (uint8_t uint8_port ,uint8_t uint8_data,uint8_t uint8_mask);
static void DIO_vidsetportvalueA(uint8_t uint8_bit,uint8_t uint8_value);
static void DIO_vidsetportvalueB(uint8_t uint8_bit,uint8_t uint8_value);
static void DIO_vidsetportvalueC(uint8_t uint8_bit,uint8_t uint8_value);
static void DIO_vidsetportvalueD(uint8_t uint8_bit,uint8_t uint8_value);
static void DIO_vidsetbitdirectionA(uint8_t uint8_bit,uint8_t uint8_direction);
static void DIO_vidsetbitdirectionB(uint8_t uint8_bit,uint8_t uint8_direction);
static void DIO_vidsetbitdirectionC(uint8_t uint8_bit,uint8_t uint8_direction);
static void DIO_vidsetbitdirectionD(uint8_t uint8_bit,uint8_t uint8_direction);
void SET_Register_Bit_value(uint8_t u8_reg,uint8_t u8_bit,uint8_t u8_value);
void LedOn(uint8 ID);
void LedOff(uint8 ID);



#endif /* DIO_H_ */
