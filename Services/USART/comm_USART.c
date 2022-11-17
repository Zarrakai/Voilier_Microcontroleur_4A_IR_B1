#include "stm32f10x.h"
#include "MyUSART.h"
#include "MyTimer.h"
#include "stdlib.h"


void comm_USART_config(USART_TypeDef * myUsart){
	USART_config(myUsart);
}


int8_t comm_USART_get_data(USART_TypeDef * myUsart){
			return (int8_t)USART_get_data(myUsart);
}



void comm_PWM_conf_timer(MyTimer_Struct_TypeDef * Timer) {
	// Timer freq = clock freq. / ((ARR+1)*(PSC+1)) <=> Timer freq = 36Mhz /((17+1)*(0+1)) = 20Mhz
	Timer->ARR = 17;
	Timer->PSC = 0;
	MyTimer_Base_Init(Timer);
}

void comm_PWM_conf(MyTimer_Struct_TypeDef * Timer, int Channel){
	MyTimer_PWM_conf(Timer->Timer, Channel);
}

void comm_PWM_set_CCR(MyTimer_Struct_TypeDef * Timer, int Channel, int8_t CCR){
	MyTimer_PWM_set_CCR(Timer->Timer, Channel, CCR);
}

void comm_USART_data_sign(int8_t value, MyGPIO_Struct_TypeDef* myGPIO){
	if(value<0)
		myGPIO->GPIO->ODR = 0;
	if (value>0)
		myGPIO->GPIO->ODR = 1;
}

int comm_USART_data_abs(int8_t value){
	if(value >= 0 && value <= 100)
		return abs(value);
	return 0; //the value from the tel. is equal to 0 <=> 255
}







/**/
void USART_send_data (char * word){}
























