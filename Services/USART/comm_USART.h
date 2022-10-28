#ifndef USART_H
#define USART_H
#include "stm32f10x.h"

//
void comm_USART_config(USART_TypeDef * myUsart);
//
int8_t comm_USART_wait_data (USART_TypeDef * USARTx);

/**/
void USART_send_data (char * word);

#endif
