#include "stm32f10x.h"
#include "comm_USART.h"
#include "comm_TIMER.h"
#include "comm_GPIO.h"
#include "MyADC.h"
#include "comm_ADC.h"
#include "comm_GIROUETTE.h"
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
	comm_servo_moteur_update();
}
	

int main(void){
	
	// variables USART
	char* transmit = " Hello world !\n";
	MyGPIO_Struct_TypeDef GPIOStruct_usart;	
	
	// variables ADC
	int Vbat;
	char *msg = " Bat faible !\n";
	MyGPIO_Struct_TypeDef GPIOStructPtr, GPIOStructPtrTX;
	
	//Tester USART RX
	comm_MyGPIO_Init (&GPIOStruct_usart, GPIOA, 10, In_Floating);
	
	//Tester USART TX
	comm_MyGPIO_Init (&GPIOStruct_usart,GPIOA, 9, AltOut_Ppull);
	
	//Configurer l'USART
	comm_USART_config(myUsart);
	
	//Transmettre une donnée
	comm_USART_send_data(myUsart, transmit, 16);
	
	
	comm_girouette_init();
	
	
	//Choisir un pin pour le bit du sens : orientation du bateau
	comm_MyGPIO_Init (&GPIOStruct_PWM,GPIOC, 7, Out_Ppull);
	
	
	//tester PWM
	TIM_PWM.Timer = TIM4;
	comm_conf_timer(&TIM_PWM, 99, 17);
	comm_PWM_conf(&TIM_PWM, 4);
	
	
	//ADC	
	comm_MyGPIO_Init(&GPIOStructPtr,GPIOB, 0, In_Analog);
	comm_MyGPIO_Init(&GPIOStructPtrTX,GPIOA, 9, AltOut_Ppull);
	comm_ADC_config(ADC1);
	
	SysTick_Config(7200000);
	
	while(1){
		Vbat = ((comm_get_value_ADC_DR(ADC1)*3300)/4095)/3;
		if(Vbat == 11)
			comm_USART_send_data(USART1,msg,15);
	}
}




