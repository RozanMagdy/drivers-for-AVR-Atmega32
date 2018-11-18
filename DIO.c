/*
 * DIO.c
 *
 *  Created on: Jan 17, 2018
 *      Author: aeit el rahman
 */
#include"Types.h"
#include"DIO.h"


void DIO_vidInit(void)
{
	DDRA=PORTA_INIT;
	DDRB=PORTB_INIT;
	DDRC=PORTC_INIT;
	DDRD=PORTD_INIT;

	portA=PORTA_VALUE;
	portB=PORTB_VALUE;
	portC=PORTC_VALUE;
	portD=PORTD_VALUE;
}

void DIO_vidsetPortdirecton(uint8_t uint8_port,uint8_t uint8_direction)
{
	switch(uint8_port){
	case pA:
			DDRA=uint8_direction;
			break;
	case pB:
			DDRB=uint8_direction;
			break;
	case pC:
			DDRC=uint8_direction;
			break;
	case pD:
			DDRD=uint8_direction;
			break;
	}
}
void DIO_vidsetBitdirecton(uint8_t uint8_port,uint8_t uint8_bit,uint8_t uint8_direction){
	switch(uint8_port){
		case pA:
			DIO_vidsetbitdirectionA(uint8_bit, uint8_direction);
			break;
		case pB:
			DIO_vidsetbitdirectionB(uint8_bit, uint8_direction);
			break;
		case pC:
			DIO_vidsetbitdirectionC(uint8_bit, uint8_direction);
			break;
		case pD:
			DIO_vidsetbitdirectionD(uint8_bit, uint8_direction);
			break;

	}
}

void DIO_vidsetPORTvalue(uint8_t uint8_port,uint8_t uint8_value)
{
	switch(uint8_port){
		case pA:
			portA=uint8_value;
			break;
		case pB:
			portB=uint8_value;
			break;
		case pC:
			portC=uint8_value;
			break;
		case pD:
			portD=uint8_value;
			break;
		}
}
void DIO_vidsetBitvalue (uint8_t uint8_port,uint8_t uint8_bit,uint8_t uint8_value)
{
	switch(uint8_port){
		case pA:
			DIO_vidsetportvalueA( uint8_bit, uint8_value);
			break;
		case pB:
			DIO_vidsetportvalueB( uint8_bit, uint8_value);
			break;
		case pC:
			DIO_vidsetportvalueC( uint8_bit, uint8_value);
			break;
		case pD:
			DIO_vidsetportvalueD( uint8_bit, uint8_value);
			break;
	}
}
boolean DIO_bolreadpinvalue(uint8_t uint8_port, uint8_t uint8_bit)
{
	uint8_t PINtemp=0;
	switch(uint8_port){
		case pA:
			PINtemp=PINA;
			break;
		case pB:
			PINtemp=PINB;
			break;
		case pC:
			PINtemp=PINC;
			break;
		case pD:
			PINtemp=PIND;
			break;
	}
	return (0X01)&(PINtemp>>uint8_bit);
}
void DIO_vidsetPORTmask (uint8_t uint8_port ,uint8_t uint8_data,uint8_t uint8_mask){
	switch(uint8_port){
		case pA:
			DDRA=DDRA&(uint8_mask);
			DDRA=DDRA|(uint8_data);
			break;
		case pB:
			DDRB=DDRB&(uint8_mask);
			DDRB=DDRB|(uint8_data);
			break;
		case pC:
			DDRC=DDRC&(uint8_mask);
			DDRC=DDRC|(uint8_data);
			break;
		case pD:
			DDRD=DDRD&(uint8_mask);
			DDRD=DDRD|(uint8_data);
			break;
		}
}
static void DIO_vidsetportvalueA(uint8_t uint8_bit,uint8_t uint8_value)
{
	switch(uint8_value){
	case 0:
		portA=portA&(~(1<<uint8_bit));
		break;
	case 1:
		portA=portA|(1<<uint8_bit);
		break;
	}
}
static void DIO_vidsetportvalueB(uint8_t uint8_bit,uint8_t uint8_value)
{
	switch(uint8_value){
	case 0:
		portB=portB&(~(1<<uint8_bit));
		break;
	case 1:
		portB=portB|(1<<uint8_bit);
		break;
	}
}
static void  DIO_vidsetportvalueC(uint8_t uint8_bit,uint8_t uint8_value)
{
	switch(uint8_value){
	case 0:
		portC=portC&(~(1<<uint8_bit));
		break;
	case 1:
		portC=portC|(1<<uint8_bit);
		break;
	}
}
static void DIO_vidsetportvalueD(uint8_t uint8_bit,uint8_t uint8_value)
{
	switch(uint8_value){
	case 0:
		portD=portD&(~(1<<uint8_bit));
		break;
	case 1:
		portD=portD|(1<<uint8_bit);
		break;
	}
}

static void DIO_vidsetbitdirectionA(uint8_t uint8_bit,uint8_t uint8_direction)
{
	switch(uint8_direction){
	case 0:
		DDRA=DDRA&(~(1<<uint8_bit));
		break;
	case 1:
		DDRA=DDRA|(1<<uint8_bit);
		break;
	}
}
static void DIO_vidsetbitdirectionB(uint8_t uint8_bit,uint8_t uint8_direction)
{
	switch(uint8_direction){
	case 0:
		DDRB=DDRB&(~(1<<uint8_bit));
		break;
	case 1:
		DDRB=DDRB|(1<<uint8_bit);
		break;
	}
}
static void DIO_vidsetbitdirectionC(uint8_t uint8_bit,uint8_t uint8_direction)
{
	switch(uint8_direction){
	case 0:
		DDRC=DDRC&(~(1<<uint8_bit));
		break;
	case 1:
		DDRC=DDRC|(1<<uint8_bit);
		break;
	}
}
static void DIO_vidsetbitdirectionD(uint8_t uint8_bit,uint8_t uint8_direction)
{
	switch(uint8_direction){
	case 0:
		DDRD=DDRD&(~(1<<uint8_bit));
		break;
	case 1:
		DDRD=DDRD|(1<<uint8_bit);
		break;
	}
}
void SET_Register_Bit_value(uint8_t u8_reg,uint8_t u8_bit,uint8_t u8_value)
{
	switch (u8_value)
	{
	case 0:
		u8_reg &=~(1<<u8_bit);
		break;
	case 1:
		u8_reg |=(1<<u8_bit);
		break;
	}
}

void LedOn(uint8 ID){
  uint8_t LEDport = 0;
  uint8_t LEDbit = 0;
  LED(ID)   //Sets value of LEDport and LEDbit from the lookup table
  DIO_vidsetBitvalue(LEDport,LEDbit,1);
}
void LedOff(uint8 ID){
  uint8_t LEDport = 0;
  uint8_t LEDbit = 0;
  LED(ID)
  DIO_vidsetBitvalue(LEDport,LEDbit,0);
}
