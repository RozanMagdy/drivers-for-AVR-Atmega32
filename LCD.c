#include <LCD.h>


void LCD_Init(void){
	DDRA = 0xff;
	DDRB = 0XFF;
	PORTB=0;
	RS(0);
	RW(0);

	delayms(20);
	///////////// Reset process from datasheet /////////
	LCD_Cmd(0x03);
	_delay_ms(5);
	LCD_Cmd(0x03);
	_delay_ms(11);
	LCD_Cmd(0x03);
	/////////////////////////////////////////////////////
	LCD_Cmd(0x02);
	LCD_Cmd(0x02);
	LCD_Cmd(0x08);
	LCD_Cmd(0x00);
	LCD_Cmd(0x0e);
	LCD_Cmd(0x00);
	LCD_Cmd(0x01);
	_delay_us(2000);
	LCD_Cmd(0x00);
	LCD_Cmd(0x06);

}
unsigned int tenpow(char pow){
	if (pow == 0)
			return 1;
	else if (pow == 1)
			return 10;
	else if (pow == 2)
			return 100;
	else if (pow == 3)
			return 1000;
	else if (pow == 4)
			return 10000;
	else if (pow == 5)
			return 100000;
	else if (pow == 6)
			return 1000000;
	else if (pow == 7)
			return 10000000;
}
void LCD_PrintInt(int number){
	unsigned temp,i=0;

	temp = number;
	while(temp){
		i++;
		temp /=10;
	}
	LCD_Write_Char(i+'0');
	LCD_Write_Char(' ');

	while(i>0){
		LCD_Write_Char((number%tenpow(i))/tenpow(i-1) +'0');
		//LCD_Write_Char( ( ( number%tenpow(i) ) / tenpow(i-1) ) +'0');
		i--;
	}

	/*
		LCD_Write_Char((number%(tenpow(i))/tenpow(i-1) )+'0');
	*/

}
static void LCD_Cmd(char a){

	PORTA &= 0x0f;  // getting port A ready = 0000XXXX
	PORTA |=a<<4;// port A= D3 D2 D1 D0 XXXX
	//LCD_DPRT= cmnd<<4;
	EN1;
    _delay_us(1);
    EN0;
	_delay_us(100);
}
void LCD_PrintChar(char a)
{
	/*
	char temp,y;
	temp = a&0x0F;

	y = a&0xF0;
	PORTA= 0;
	RS(1);             // => RS = 1

	PORTA = y;             //Data transfer
	EN1;
	_delay_us(1);
	EN0;
	_delay_us(1);
	PORTA = nibble(temp);
	EN1;
	_delay_us(1);
	EN0;
	_delay_us(1);
	*/


	PORTA&= 0x0f; // getting port A ready = 0000XXXX
	PORTA|=a& 0xf0;// port A= D7 D6 D5 D4 XXXX
	//LCD_DPRT=data& 0xf0;
	RS(1);
	EN1;
    _delay_us(1);
    EN0;
	_delay_us(100);



	PORTA&= 0x0f;  // getting port A ready = 0000XXXX
	PORTA|=a<<4;// port A= D3 D2 D1 D0 XXXX
	//LCD_DPRT= data<<4;
	EN1;
	_delay_us(1);
	EN0;
	_delay_us(100);
}

void LCD_PrintString(char* String){
	while(*String){
		LCD_Write_Char(*String);
		String++;
	}
}
void LCD_SetCursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
		temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		LCD_Cmd(z);
		LCD_Cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		LCD_Cmd(z);
		LCD_Cmd(y);
	}
}

void main(){
	LCD_Write_Char('a');

	LCD_Write_Char('a');

	LCD_Write_Char('a');
	//LCD_Write_Integer(65531);

	LCD_Set_Cursor(2,0);
	LCD_Write_String("Senior Embedded Engineer");

}
