#include "stm32f10x.h"
#include "MyUSART.h"
#include "MyTimer.h"
#include "comm_USART.h"
#include "stdlib.h"


void comm_conf_timer(MyTimer_Struct_TypeDef * Timer, int ARR, int PSC) {
	// Timer freq = clock freq. / ((ARR+1)*(PSC+1)) <=> Timer freq = 36Mhz /((99+1)*(17+1)) = 20Khz
	Timer->ARR = ARR;
	Timer->PSC = PSC;
	MyTimer_Base_Init(Timer);
	Timer->Timer->CR1 |= TIM_CR1_CEN;
}

void comm_Girouette_conf_timer(MyTimer_Struct_TypeDef * Timer){

	MyTimer_Base_Start(Timer->Timer);
	MyTimer_Mode_Compteur_Incremental(Timer->Timer);
}


void comm_PWM_conf(MyTimer_Struct_TypeDef * Timer, int Channel){
	MyTimer_PWM_conf(Timer->Timer, Channel);
}

int8_t comm_PWM_calculer_CCR(TIM_TypeDef * Timer, int8_t ratio){
	return MyTimer_PWM_calculer_CCR(Timer, ratio);
}

void comm_PWM_set_CCR(MyTimer_Struct_TypeDef * Timer, int Channel, int8_t CCR){
	MyTimer_PWM_set_CCR(Timer->Timer, Channel, CCR);
}

int comm_USART_data_sign(int8_t value, MyGPIO_Struct_TypeDef* myGPIO, MyTimer_Struct_TypeDef * Timer){
	if(value<0){
		MyGPIO_Set(myGPIO->GPIO, myGPIO->GPIO_Pin);
		return 0;
	}
	else
		MyGPIO_Reset(myGPIO->GPIO, myGPIO->GPIO_Pin);
	return 1;
}


























