#include "stm32f10x.h"
#include "comm_USART.h"
#include "Driver_GPIO.h"

int8_t data;  // POUR TESTER 
	
int main(void){
	//tester USART
	USART_TypeDef * myUsart = USART1;
	MyGPIO_Struct_TypeDef GPIOStruct_usart, GPIOStruct_PWM;
	MyTimer_Struct_TypeDef TIM_PWM;
	
	GPIOStruct_usart.GPIO = GPIOA;
	GPIOStruct_usart.GPIO_Conf = In_Floating;
	GPIOStruct_usart.GPIO_Pin = 10;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	
	//bit du sens : orientation du bateau
	GPIOStruct_PWM.GPIO = GPIOA;
	GPIOStruct_PWM.GPIO_Conf = Out_Ppull;
	GPIOStruct_PWM.GPIO_Pin = 14;
	
	
	MyGPIO_Init(&GPIOStruct_usart);
	MyGPIO_Init(&GPIOStruct_PWM);
	
	comm_USART_config(myUsart);
	//tester PWM
	TIM_PWM.Timer = TIM4;
	comm_PWM_conf_timer(&TIM_PWM);
	comm_PWM_conf(&TIM_PWM, 4);
	
	while(1){
		data = comm_USART_get_data(myUsart);
		comm_USART_data_sign(data, &GPIOStruct_PWM);
		data = comm_USART_data_abs(data);
		if (data != 0)
			comm_PWM_set_CCR(&TIM_PWM, 4, data);
	}
}


