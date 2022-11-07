#include "stm32f10x.h"
#include "MyUSART.h"



void comm_USART_config(USART_TypeDef * myUsart){
	USART_config(myUsart);
}


int8_t comm_USART_get_data(USART_TypeDef * myUsart){
			return (int8_t)USART_get_data(myUsart);
}


/**/
void USART_send_data (char * word){}
























