/*
 * ADC.c
 *
 *  Created on: 19 Sep 2017
 *      Author: Rozan
 */
#include"ADC.h"
void ADCinit(void){
	DDRA=0x00;
	ADCSRA=0x87;
}
void ADC_setvoltagerefrancese(u8 state){
		ADMUX=ADMUX&(0x3F);
		ADMUX=ADMUX|(state<<REFS0);

}
void ADC_setdataadjest(u8 state){
		ADMUX=ADMUX&(0xDF);
		ADMUX=ADMUX|(state<<ADLAR);
}
void ADC_setchannel(u8 state){
		ADMUX=ADMUX&(0xE0);
		ADMUX=ADMUX|(state);
}
u16 ADC_valuerightadjest(void){
	u16 temp_value=0x0000;
	ADCSRA=ADCSRA|(1<<ADSC);
	while((ADCSRA&(1<<ADIF))==0);
	ADCSRA=ADCSRA|(1<<ADIF);
	temp_value=ADCL;
	temp_value=temp_value|(ADCH<<8);
	return temp_value;
}
u8 ADC_valueleftadjest(void){
	u8  temp_value=0x00;
	ADCSRA=ADCSRA|(1<<ADSC);
	while((ADCSRA&(1<<ADIF))==0);
	temp_value=ADCH;
	return temp_value;
}
