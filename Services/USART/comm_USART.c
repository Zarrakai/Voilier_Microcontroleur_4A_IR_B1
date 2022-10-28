#include "stm32f10x.h"
#include "MyUSART.h"



void comm_USART_config(USART_TypeDef * myUsart){
	USART_config(myUsart);
}


int8_t comm_USART_wait_data(USART_TypeDef * myUsart){

	while(1){
		if(is_USART_DR_not_empty(myUsart)){
			return (int8_t)USART_get_data(myUsart);
		}
	}
}


/**/
void USART_send_data (char * word){}
























