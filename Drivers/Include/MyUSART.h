#ifndef MYUSART_H
#define MYUSART_H
#include "stm32f10x.h"


 /*
**************************************************************************************************
* @param : - USART_TypeDef* USARTx : USART concerné
* Permet de : 
			 - Enable the UART clock 
			 - Fix Baud rate
			 - Enable UART 
			 - Fix the length of the transmitted word  
			 - Enable Receiver/Transmitter
***************************************************************************************************/
void USART_config(USART_TypeDef* USARTx);


 /*
**************************************************************************************************
* @param : - USART_TypeDef* USARTx : USART concerné
* Permet de : 
			 Verify if the Data Register is not empty : data is received
***************************************************************************************************/
int is_USART_DR_not_empty(USART_TypeDef* USARTx);


 /*
**************************************************************************************************
* @param : - USART_TypeDef* USARTx : USART concerné
* Permet de : 
			 Verify if the Data Register contain the data and it's ready to be read
***************************************************************************************************/
int is_USART_data_shifted(USART_TypeDef* USARTx);


 /*
**************************************************************************************************
* @param : - USART_TypeDef* USARTx : USART concerné
* Permet de : 
			  Verify if the data is transmitted to the destination
***************************************************************************************************/
int is_USART_data_transmitted(USART_TypeDef* USARTx);


 /*
**************************************************************************************************
* @param : - USART_TypeDef* USARTx : USART concerné
* Permet de : 
			  Return Data stored in Dr register
***************************************************************************************************/
int8_t USART_get_data (USART_TypeDef* USARTx);


/* à terminer pour F4 */ 
void USART_put_char (char * word);

#endif

