/*
 * ADC.h
 *
 *  Created on: 16 Sep 2017
 *      Author: Rozan
 */

#ifndef ADC_H_
#define ADC_H_

#include "Std_Types.h"

/*privet section */

#define DDRA    *((volatile u8*)(0x3A))
#define ADMUX   *((volatile u8*)(0x27))
#define ADCSRA  *((volatile u8*)(0x26))
#define ADCH    *((volatile u8*)(0x25))
#define ADCL    *((volatile u8*)(0x24))

#define REFS1     7
#define REFS0     6
#define ADLAR     5
#define MUX4      4
#define MUX3      3
#define MUX2      2
#define MUX1      1
#define MUX0      0

#define ADEN      7
#define ADSC      6
#define ADATE     5
#define ADIF      4
#define ADIE      3
#define ADPS2     2
#define ADPS1     1
#define ADPS0     0


/* configration section */


/* prototype section */

void ADCinit(void);
void ADC_setvoltagerefrancese(u8 state);
void ADC_setdataadjest(u8 state);
void ADC_setchannel(u8 state);
u16 ADC_valuerightadjest(void);
u8 ADC_valueleftadjest(void);




#endif /* ADC_H_ */
