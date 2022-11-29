#include "stm32f10x.h"
#include "MyUSART.h"
#include "comm_USART.h"
#include "MyADC.h"
#include "comm_ADC.h"
#include "stdlib.h"
#include "Driver_GPIO.h"
#include "comm_GPIO.h"



int main(){
	
	int Vbat;
	char *msg = " Bat faible !\n";
	MyGPIO_Struct_TypeDef GPIOStructPtr, GPIOStructPtrTX;
	USART_TypeDef * MyUSART = USART1;	
	
	comm_MyGPIO_Init(&GPIOStructPtr,GPIOB, 0, In_Analog);
	comm_MyGPIO_Init(&GPIOStructPtrTX,GPIOA, 9, AltOut_Ppull);
	comm_ADC_config(ADC1);
	comm_USART_config(MyUSART);
	
	while(1){
		Vbat = 3*((comm_get_value_ADC_DR(ADC1)*3300)/4095);
		if(Vbat == 11)
			comm_USART_send_data(USART1,msg,15);
	}
}
/*
uint16_t get_value_ADC(){
	return ADC1->DR & (0x0FFF);
}

int main(){
	
	int Vbat;
	MyGPIO_Struct_TypeDef GPIOStructPtr;
	
	comm_MyGPIO_Init(&GPIOStructPtr,GPIOB, 0, In_Analog);
	
	RCC->APB1ENR |= RCC_APB2ENR_ADC1EN;
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
	
	ADC1->SQR1 |= (0<<20);
	ADC1->SQR3 |= (1<<0);
	ADC1->SMPR1 |= (8<<3);
	//allumer l'ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	//mettre l'ADC pret à la converstion
	ADC1->CR2 |= ADC_CR2_ADON;
	ADC1->CR2 |= ADC_CR2_CAL;
	//while(!(ADC1->CR2 & ADC_CR2_CAL));
	
	while(1){
		Vbat = 3*(get_value_ADC()*3300)/4095;
		if(Vbat == 11){
			comm_USART_send_data(USART1,"c",1);
		}
	}
}*/


