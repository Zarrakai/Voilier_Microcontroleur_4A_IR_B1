#ifndef USART_H
#define USART_H
#include "stm32f10x.h"
#include "MyTimer.h"

//
void comm_USART_config(USART_TypeDef * myUsart);

//
int8_t comm_USART_get_data (USART_TypeDef * USARTx);

/**/
void comm_USART_send_data (char * word);

//
void comm_PWM_conf_timer(MyTimer_Struct_TypeDef * Timer);
//
void comm_PWM_conf(MyTimer_Struct_TypeDef * Timer, int Channel);

//
int8_t comm_PWM_calculer_CCR(TIM_TypeDef * Timer, int8_t ratio);
//
void comm_PWM_set_CCR(MyTimer_Struct_TypeDef * Timer, int Channel, int8_t CCR);
//
int comm_USART_data_sign(int8_t value, MyGPIO_Struct_TypeDef* myGPIO, MyTimer_Struct_TypeDef * Timer);

#endif
