#include "stm32f10x.h"
#include "MyUSART.h"
#include "comm_USART.h"
#include "stdlib.h"


void comm_USART_config(USART_TypeDef * myUsart){
	USART_config(myUsart);
}


int8_t comm_USART_get_data(USART_TypeDef * myUsart){
			return (int8_t)USART_get_data(myUsart);
}


void comm_USART_send_data(USART_TypeDef * USARTx, char * word, int length){
	int i=0;
	for(i=0; i<length; i++){
		USART_send_data(USARTx, word[i]);
	}
}


 





















