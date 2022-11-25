#include "stm32f10x.h"
#include "comm_USART.h"
#include "comm_TIMER.h"
#include "comm_GPIO.h"
#include "Driver_GPIO.h"

/* Variables globales pour les tests*/
int8_t data, CCR_value;
USART_TypeDef * myUsart = USART1;
MyGPIO_Struct_TypeDef GPIOStruct_PWM;
MyTimer_Struct_TypeDef TIM_PWM;
	
	
void SysTick_Handler(void){
		data = comm_USART_get_data(myUsart);
		if (comm_USART_data_sign(data, &GPIOStruct_PWM, &TIM_PWM) == 0)
			comm_PWM_set_CCR(&TIM_PWM, 4, (-1)*data);
		else
			comm_PWM_set_CCR(&TIM_PWM, 4, data);
}
	

int main(void){
	//Tester USART
	MyGPIO_Struct_TypeDef GPIOStruct_usart;	
	comm_MyGPIO_Init (&GPIOStruct_usart,GPIOA, 10, In_Floating);
	comm_USART_config(myUsart);
	
	
	//Choisir un pin pour le bit du sens : orientation du bateau
	comm_MyGPIO_Init (&GPIOStruct_PWM,GPIOC, 7, Out_Ppull);
	
	
	//tester PWM
	TIM_PWM.Timer = TIM4;
	comm_PWM_conf_timer(&TIM_PWM);
	comm_PWM_conf(&TIM_PWM, 4);
	
	SysTick_Config(7200000);
	
	while(1);
}




