#include "Girouette.h"



MyTimer_Struct_TypeDef *Timer;
void girouette_calibrer_timer (void);


void girouette_init ( MyTimer_Struct_TypeDef *t)
{
	MyGPIO_Struct_TypeDef GPIO_Girouette_PA0, GPIO_Girouette_PA1, GPIO_Girouette_PB2;
	
	Timer = t;
	
	// PA0 et PA1 => Pin 1 et 2 de la girouette
	GPIO_Girouette_PA0.GPIO = GPIOA;
	GPIO_Girouette_PA0.GPIO_Pin = 0;
	GPIO_Girouette_PA0.GPIO_Conf = In_Floating;
	MyGPIO_Init(& GPIO_Girouette_PA0);
	
	GPIO_Girouette_PA1.GPIO = GPIOA;
	GPIO_Girouette_PA1.GPIO_Pin = 1;
	GPIO_Girouette_PA1.GPIO_Conf = In_Floating;
	MyGPIO_Init(& GPIO_Girouette_PA1);
	
	// PB2 => Index girouette
	GPIO_Girouette_PB2.GPIO = GPIOB;
	GPIO_Girouette_PB2.GPIO_Pin = 2;
	GPIO_Girouette_PB2.GPIO_Conf = In_Floating;
	MyGPIO_Init(& GPIO_Girouette_PB2);
	
	Timer->ARR = 360*4-1;
	Timer->PSC = 0;
	Timer->Timer = TIM2;
	
	MyTimer_Base_Init(Timer);
	MyTimer_Base_Start(Timer->Timer);
	MyTimer_Mode_Compteur_Incremental(Timer->Timer);
	
	MyGPIO_Activate_AFIO();
	MyGPIO_Config_exti2PB();
	MyGPIO_ActiveIT_EXTI2_PB2(1,&girouette_calibrer_timer);
}
	

float girouette_Calcul_Angle(void){
	 int value = Timer->Timer->CNT;
	 return (float)value /4.;
}


void girouette_calibrer_timer(void)
{
	Timer->Timer->CNT = 0;
}
