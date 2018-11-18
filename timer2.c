/*
 * timer2.c
 *
 *  Created on: 20 Jan 2018
 *      Author: Rozan
 */
#include"timer2.h"

void timer2_int(void){
	TCCR2=0x01;
	DDRD=DDRD|(0x04);
}
void timer2_stop (void){
	TCCR2=0x00;
}

void timer2_normalmode(u8 clk ,u8 wave,u8 comper){
	timer2_setclocksourse(clk);
	timer2_setmode(normal0);
	timer2_setcompermatch(comper);
	timer2_setwavegenerator(wave);
}
void timer2_ctcmode(u8 clk ,u8 wave,u8 comper){
	timer2_setclocksourse(clk);
	timer2_setmode(CTC0);
	timer2_setcompermatch(comper);
	timer2_setwavegenerator(wave);
}
void timer2_phasecorrect(u8 clk ,u8 wave,u8 comper){
	timer2_setclocksourse(clk);
	timer2_setmode(PCPWM0);
	timer2_setcompermatch(comper);
	timer2_setwavegenerator(wave);
}
void timer2_fatsPWM(u8 clk ,u8 wave,u8 comper){
	timer2_setclocksourse(clk);
	timer2_setmode(FPWM0);
	timer2_setcompermatch(comper);
	timer2_setwavegenerator(wave);
}

void timer2_OCintruptenabel(void){
	TIMSK=TIMSK&(0xFD);
	TIMSK=TIMSK|(1<<OCIE2);
}
void timer2_OVintruptenabel(void){
	TIMSK=TIMSK&(0xFE);
	TIMSK=TIMSK|(1<<TOIE2);
}
void timer2_forceoutcomper(void){
		TCCR2=TCCR2&(0x7F);
		TCCR2=TCCR2|(1<<FOC2);
}
void  timer2_reset(void){
	SFIOR=SFIOR|(0x01);
}
static timer2_setclocksourse(u8 state){
	/* 000no clk sourse
	 * 001 no prescaler
	 * 010 clk/8
	 * 011clk/64
	 * 100clk/265
	 * 101 clk/1024
	 * 110 T0 falling age
	 * 111 T0 raising age*/
	if(state==0x06 ||state==0x07){
		DDRD=DDRD&(0xFE);
	}
	TCCR2=TCCR2&(0xF8);
	TCCR2=TCCR2|(state);
}
static void timer2_setmode(u8 state){
	/* 0000 normal mode
	 * 0001 CTC
	 * 1000 phase correct PWM
	 * 1001 fast PWM */
	TCCR2=TCCR2&(0xB7);
	TCCR2=TCCR2|(state<<WGM21);
}
static void timer2_setwavegenerator(u8 state){
		TCCR2=TCCR2&(0xCF);
		TCCR2=TCCR2|(state<<COM20);
}
static void timer2_setcompermatch(u8 compermatch){
		OCR2=compermatch;
}
