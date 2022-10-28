#include "stm32f10x.h"
#include "comm_USART.h"

	int8_t data;
int main(void){

	USART_TypeDef * myUsart = USART1;
	comm_USART_config(myUsart);
	data = comm_USART_wait_data(myUsart);
	
	
	
	while(1);
}


