/*
 * timer0.c
 *
 *  Created on: 19 Jan 2018
 *      Author: Rozan
 */
#include"timer0.h"

void timer0_int(void){
	TCCR0=0x01;
	DDRB=DDRB|(0x04);
}
void timer0_stop (void){
	TCCR0=0x00;
}

void timer0_normalmode(u8 clk ,u8 wave,u8 comper){
	timer0_setclocksourse(clk);
	timer0_setmode(normal0);
	timer0_setcompermatch(comper);
	timer0_setwavegenerator(wave);
}
void timer0_ctcmode(u8 clk ,u8 wave,u8 comper){
	timer0_setclocksourse(clk);
	timer0_setmode(CTC0);
	timer0_setcompermatch(comper);
	timer0_setwavegenerator(wave);
}
void timer0_phasecorrect(u8 clk ,u8 wave,u8 comper){
	timer0_setclocksourse(clk);
	timer0_setmode(PCPWM0);
	timer0_setcompermatch(comper);
	timer0_setwavegenerator(wave);
}
void timer0_fatsPWM(u8 clk ,u8 wave,u8 comper){
	timer0_setclocksourse(clk);
	timer0_setmode(FPWM0);
	timer0_setcompermatch(comper);
	timer0_setwavegenerator(wave);
}

void timer0_OCintruptenabel(void){
	TIMSK=TIMSK&(0xFD);
	TIMSK=TIMSK|(1<<OCIE0);
}
void timer0_OVintruptenabel(void){
	TIMSK=TIMSK&(0xFE);
	TIMSK=TIMSK|(1<<TOIE0);
}
void timer0_forceoutcomper(void){
		TCCR0=TCCR0&(0x7F);
		TCCR0=TCCR0|(1<<FOC0);
}
void  timer0_reset(void){
	SFIOR=SFIOR|(0x01);
}
static timer0_setclocksourse(u8 state){
	/* 000no clk sourse
	 * 001 no prescaler
	 * 010 clk/8
	 * 011clk/64
	 * 100clk/265
	 * 101 clk/1024
	 * 110 T0 falling age
	 * 111 T0 raising age*/
	if(state==0x06 ||state==0x07){
		DDRB=DDRB&(0xFE);
	}
	TCCR0=TCCR0&(0xF8);
	TCCR0=TCCR0|(state);
}
static void timer0_setmode(u8 state){
	/* 0000 normal mode
	 * 0001 CTC
	 * 1000 phase correct PWM
	 * 1001 fast PWM */
	TCCR0=TCCR0&(0xB7);
	TCCR0=TCCR0|(state<<WGM01);
}
static void timer0_setwavegenerator(u8 state){
		TCCR0=TCCR0&(0xCF);
		TCCR0=TCCR0|(state<<COM00);
}
static void timer0_setcompermatch(u8 compermatch){
		OCR0=compermatch;
}


