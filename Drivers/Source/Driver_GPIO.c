#include "Driver_GPIO.h"
#include "stm32f10x.h"
#include <stdio.h>

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr ) 
{
	char conf, odr = 0;
	if (GPIOStructPtr->GPIO_Conf == In_PullUp)
	{
		conf = 0x8;
		odr = 1;
	}
	else
	{
		conf = GPIOStructPtr->GPIO_Conf;
	}
	
	
	if(GPIOStructPtr->GPIO == GPIOA)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	}
	if(GPIOStructPtr->GPIO == GPIOB)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	}
	if(GPIOStructPtr->GPIO == GPIOC)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	}
	if(GPIOStructPtr->GPIO == GPIOD)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	}
	if(GPIOStructPtr->GPIO == GPIOE)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
	}
	
	
	if(GPIOStructPtr->GPIO_Pin < 8)	// ecriture dans CRL
	{
		GPIOStructPtr->GPIO->CRL &= ~(0xf << (GPIOStructPtr->GPIO_Pin)*4);	//mise à 0 du champs CNF et MODE de PC_x
		GPIOStructPtr->GPIO->CRL |= (conf << (GPIOStructPtr->GPIO_Pin)*4);
		
	}
	else	// ecriture dans CRH
	{
		GPIOStructPtr->GPIO->CRH &= ~(0xf << (GPIOStructPtr->GPIO_Pin-8)*4);	//mise à 0 du champs CNF et MODE de PC_x
		GPIOStructPtr->GPIO->CRH |= (conf << (GPIOStructPtr->GPIO_Pin-8)*4);
	}
	
	if (odr == 1){
		MyGPIO_Set(GPIOStructPtr->GPIO, GPIOStructPtr->GPIO_Pin);
	}
	
	
}




int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ) 
{
	int mask = 0x01<<GPIO_Pin;
	return ((GPIO->IDR & (mask)) >> GPIO_Pin == 1);
}		// revoie 0 ou autre chose que 0

void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ) 
{
	int mask = 0x01<<GPIO_Pin;
	GPIO->ODR |= mask;
}



void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ) 
{
	GPIO->ODR &= ~(0x01 << GPIO_Pin );
}

void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ) 
{
	 if (MyGPIO_Read(GPIO,GPIO_Pin) == 1)
	 {
		 MyGPIO_Reset(GPIO,GPIO_Pin);
	 }
	 else
	 {
		 MyGPIO_Set(GPIO,GPIO_Pin);
	 }
}









