#ifndef USART_H
#define USART_H
#include "stm32f10x.h"
#include "MyTimer.h"

/*************************** Partie Service *******************************************************/

 /*
**************************************************************************************************
* @param : - USART_TypeDef* USARTx : USART concerné
* Permet d'appeler la fonction USART_config(USART_TypeDef* USARTx) depuis le Driver
***************************************************************************************************/
void comm_USART_config(USART_TypeDef * myUsart);


 /*
**************************************************************************************************
* @param : - USART_TypeDef* USARTx : USART concerné
* Permet d'appeler la fonction USART_get_data (USART_TypeDef* USARTx) depuis le Driver
***************************************************************************************************/
int8_t comm_USART_get_data (USART_TypeDef * USARTx);



 /*
**************************************************************************************************
* @param : - USART_TypeDef* USARTx : USART concerné
					 - char * word :  données à envoyer à la telecommande
* Permet d'appeler la fonction USART_send_data(USART_TypeDef USARTx, char data) depuis le Driver
***************************************************************************************************/
void comm_USART_send_data(USART_TypeDef * USARTx, char * word, int length);

#endif
