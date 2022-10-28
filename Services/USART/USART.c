#include "stm32f10x.h"
#include "MyUSART.h"
#include <stdlib.h>


int8_t USART_receive_data (USART_TypeDef * USARTx){
	USART_TypeDef * myUsart = USARTx; 
	
	USART_config(myUsart);
	
	while(1){
		if(is_USART_DR_not_empty(myUsart)){
			int8_t data = USART_get_data(myUsart);
			data  = abs(data);
			return data;
		}
	}
}























