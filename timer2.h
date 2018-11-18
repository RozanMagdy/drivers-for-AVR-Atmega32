/*
 * timer2.h
 *
 *  Created on: 20 Jan 2018
 *      Author: Rozan
 */

#ifndef TIMER2_H_
#define TIMER2_H_
/*type definetion */

typedef unsigned char u8;
typedef unsigned short int u16;

/*privet section */

#define DDRD   *((volatile u8*)(0x31))
#define PIND   *((volatile u8*)(0x30))

#define OCR2    *((volatile u8*)(0x43))
#define TCCR2   *((volatile u8*)(0x45))
#define TCNT2   *((volatile u8*)(0x44))
#define TIFR    *((volatile u8*)(0x58))
#define TIMSK   *((volatile u8*)(0x59))
#define SFIOR   *((volatile u8*)(0x50))
#define ASSR    *((volatile u8*)(0x42))

#define OCIE2     7
#define TOIE2     6

#define OCF2      7
#define TOV2      6

#define FOC2      7
#define WGM20     6
#define COM21     5
#define COM20     4
#define WGM21     3
#define CS22      2
#define CS21      1
#define CS20      0

#define PSR2      1

#define AS2       3
#define TCN2UB    2
#define OCR2UB    1
#define TCR2UB    0

/*configration section */

/*#define configdone 0
#if(configdone==0)
#error "you didn't doneconfigration"
#endif*/


/* prototype section */
enum {normal2=0,CTC2=1,PCPWM2=8,FPWM2=9};/*modestypes*/
enum {noclk2,clk2,clk82,clk322,clk642,clk1282,clk2652,clk10242};/*clock types*/
enum {noop2=0,toggel2,clear2,set2};/*non PWM mode wave*/
enum {clearup2=2,setup2=3};/*phase correct PWM wave*/
enum {clear2=2,set2=3};/*fast PWM wave*/
void timer2_int(void);
void timer2_stop(void);
void timer2_normalmode(u8,u8,u8);
void timer2_ctcmode(u8,u8,u8);
void timer2_phasecorrect(u8,u8,u8);
void timer2_fastPWM(u8,u8,u8);
void timer2_forceoutcomper(void);
void timer2_OCintruptenabel(void);
void timer2_OVintruptenabel(void);
void  timer2_reset(void);
static void timer2_setclocksourse(u8);
static void timer2_setmode(u8);
static void timer2_setcompermatch(u8);
static void timer2_setwavegenerator(u8);


#endif /* TIMER2_H_ */
