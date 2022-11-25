#ifndef GPIO_H
#define GPIO_H
#include "stm32f10x.h"
#include "Driver_GPIO.h"

/*************************** Partie Service *******************************************************/

/* Choisir un pin, un port et une configuration pour un GPIO*/
void comm_MyGPIO_Init ( MyGPIO_Struct_TypeDef * MyGPIO, GPIO_TypeDef * Port, char pin, char conf);

#endif