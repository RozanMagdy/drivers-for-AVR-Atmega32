#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



#define nibble(x) (x<<4)
#define delayms(x) _delay_ms(x);
#define delayus(x) _delay_us(x);
#define RS(X)	PORTB |= X<<1
#define RW(X)	PORTB |= X<<2
#define EN1	PORTB |= 1<<3
#define EN0	PORTB &= ~(1<<3)

/*
<Wait at least 15ms>
RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
0 0 0 0 1 1 n/c n/c n/c n/c
<Wait at least 4.1ms>
RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
0 0 0 0 1 1 n/c n/c n/c n/c
<Wait at least 100us>
RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
0 0 0 0 1 1 n/c n/c n/c n/c
<Wait 4.1ms>
RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
0 0 0 0 1 0 n/c n/c n/c n/c
*/
void LCD_Init(void);
unsigned int tenpow(char pow);
void LCD_PrintInt(int number);
static void LCD_Cmd(char a);
void LCD_PrintChar(char a);
void LCD_PrintString(char* String);
void LCD_SetCursor(char a, char b);//not working yet
