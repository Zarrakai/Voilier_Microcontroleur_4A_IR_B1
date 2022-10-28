#include "MyUSART.h"

void USART_config(USART_TypeDef* USARTx){
	
	if(USARTx == USART1){
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
		USARTx->BRR = 0x1D4C;												 // Baud rate : USARTDIV = 72000000/(16*9600), APB2 with 72MHz
	}
	else
		if(USARTx == USART3){
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
			USARTx->BRR = (uint16_t)0xEA177;						// Baud rate : USARTDIV = 36000000/(16*9600), APB1 with 36MHz
		}
		else{
			//uart 2 : interrupt !!
		}
  
	USARTx->CR1 = 0x00;														// Clear ALL
	USARTx->CR1 |= USART_CR1_UE;									// Enable UART -> UA=1
	
	USARTx->CR1 |= USART_CR1_M ;									// 8 bits for word length, M=0
	
	USARTx->CR1 |= USART_CR1_TE; 									// Enable Transmitter, TE=1
  USARTx->CR1 |= USART_CR1_RE;									// Enable the Receiver, RE=1
}


int is_USART_DR_not_empty(USART_TypeDef* USARTx){
	if (USARTx->SR & USART_SR_RXNE){
		return 1;
	}
	return 0;
}


int is_USART_data_shifted(USART_TypeDef* USARTx){
	if (USARTx->SR & USART_SR_TXE){
		return 1;
	}
	return 0;
}


int is_USART_data_transmitted(USART_TypeDef* USARTx){
	if (USARTx->SR & USART_SR_TC){
		return 1;
	}
	return 0;
}

int8_t USART_get_data (USART_TypeDef* USARTx) {
	int8_t data = USARTx->DR;
	return data;
}


// à terminer pour F4
void USART_put_string (char * word){
}
