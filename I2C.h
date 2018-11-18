#ifndef I2C_H_
#define I2C_H_
 

#include "Micro_config.h"
#include "Std_Types.h"

/* privet section*/

#define TWDR    *((volatile uint8_t*)(0x23))  
#define TWAR    *((volatile uint8_t*)(0x22))  
#define TWSR    *((volatile uint8_t*)(0x21))  
#define TWBR    *((volatile uint8_t*)(0x20)) 
#define TWCR 	*((volatile uint8_t*)(0x56)) 
 
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2
#define TWIE  0

#define	TWPS1 1
#define	TWPS0 0

#define TWGCE 0
/*configration section*/


/*prototype section*/

void I2C_Init();
void I2C_Start();
void I2C_Stop();
void I2C_Write(uint8 data);
uint8 I2C_Read_ACK();
uint8 I2C_Read_NO_ACK();
uint8 I2C_Status();


#endif /* I2C_H_ */