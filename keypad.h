#ifndef keypad_H_
#define keypad_H_

//keypad pins
#define ROW0		0
#define ROW1		1
#define ROW2		2
#define ROW3		3
#define LINE0		4
#define LINE1		5
#define LINE2		6
#define LINE3		7
//KEYPAD Direction
#define ROW0_DDR		DDRC
#define ROW1_DDR		DDRC
#define ROW2_DDR		DDRC
#define ROW3_DDR		DDRC
#define LINE0_DDR		DDRC
#define LINE1_DDR		DDRC
#define LINE2_DDR		DDRC
#define LINE3_DDR		DDRC
//ROWs' PORTs
#define ROW0_PORT		portC
#define ROW1_PORT		portC
#define ROW2_PORT		portC
#define ROW3_PORT		portC
//LINEs' PINs
#define LINE0_PIN		PINC
#define LINE1_PIN		PINC
#define LINE2_PIN		PINC
#define LINE3_PIN		PINC
//LINES' PULLUP
#define LINE0_PULLUP	portC
#define LINE1_PULLUP	portC
#define LINE2_PULLUP	portC
#define LINE3_PULLUP	portC
#define ALL_LINES (((LINE0_PIN&(1<<LINE0))>>LINE0)&((LINE1_PIN&(1<<LINE1))>>LINE1)&((LINE2_PIN&(1<<LINE2))>>LINE2)&((LINE3_PIN&(1<<LINE3))>>LINE3))

#endif //KEYPADCONFIG_H_
