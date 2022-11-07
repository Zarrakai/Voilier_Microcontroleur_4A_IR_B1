#include "stm32f10x.h"
#include "comm_USART.h"
#include "Driver_GPIO.h"

int8_t data;  // POUR TESTER 
	
int main(void){

	USART_TypeDef * myUsart = USART1;
	MyGPIO_Struct_TypeDef  GPIOStruct;
	
	GPIOStruct.GPIO = GPIOA;
	GPIOStruct.GPIO_Conf = In_Floating;
	GPIOStruct.GPIO_Pin = 10;
	GPIOStruct.odr = 0;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	MyGPIO_Init(&GPIOStruct);
	
	comm_USART_config(myUsart);
	
	while(1){
		data = comm_USART_get_data(myUsart);
	}
}


