#include "stm32f10x.h"
#include "comm_GPIO.h"
#include "stdlib.h"

void comm_MyGPIO_Init ( MyGPIO_Struct_TypeDef * MyGPIO, GPIO_TypeDef * Port, char pin, char conf){
	MyGPIO->GPIO = Port;
	MyGPIO->GPIO_Conf = conf;
	MyGPIO->GPIO_Pin = pin;
	MyGPIO_Init(MyGPIO);
}