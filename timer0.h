/*
 * timer0.h
 *
 *  Created on: 19 Jan 2018
 *      Author: Rozan
 */

#ifndef TIMER0_H_
#define TIMER0_H_

/*type definetion */

typedef unsigned char u8;
typedef unsigned short int u16;

/*privet section */
#define DDRB   *((volatile u8*)(0x37))
#define PINB   *((volatile u8*)(0x36))

#define OCR0    *((volatile u8*)(0x5C))
#define TCCR0   *((volatile u8*)(0x53))
#define TCNT0   *((volatile u8*)(0x52))
#define TIFR    *((volatile u8*)(0x58))
#define TIMSK   *((volatile u8*)(0x59))
#define SFIOR   *((volatile u8*)(0x50))

#define OCIE0     1
#define TOIE0     0

#define OCF0      1
#define TOV0      0

#define FOC0      7
#define WGM00     6
#define COM01     5
#define COM00     4
#define WGM01     3
#define CS02      2
#define CS01      1
#define CS00      0

#define PSR10     0
/*configration section */

/*#define configdone 0
#if(configdone==0)
#error "you didn't doneconfigration"
#endif*/


/* prototype section */
enum {normal0=0,CTC0=1,PCPWM0=8,FPWM0=9};/*modestypes*/
enum {noclk0,clk0,clk80,clk640,clk2650,clk10240,T0f0,T0R0};/*clock types*/
enum {noop0=0,toggel0,clear0,set0};/*non PWM mode wave*/
enum {clearup0=2,setup0=3};/*phase correct PWM wave*/
enum {clear0=2,set0=3};/*fast PWM wave*/
void timer0_int(void);
void timer0_stop(void);
void timer0_normalmode(u8,u8,u8);
void timer0_ctcmode(u8,u8,u8);
void timer0_phasecorrect(u8,u8,u8);
void timer0_fastPWM(u8,u8,u8);
void timer0_forceoutcomper(void);
void timer0_OCintruptenabel(void);
void timer0_OVintruptenabel(void);
void  timer0_reset(void);
static void timer0_setclocksourse(u8);
static void timer0_setmode(u8);
static void timer0_setcompermatch(u8);
static void timer0_setwavegenerator(u8);

#endif /* TIMER0_H_ */
