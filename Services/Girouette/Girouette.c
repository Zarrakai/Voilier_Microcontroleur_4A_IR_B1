#include "Girouette.h"



MyTimer_Struct_TypeDef *Timer;
void girouette_ActiveIT_PA2 ( char Prio);


void girouette_init ( MyTimer_Struct_TypeDef *t)
{
	MyGPIO_Struct_TypeDef GPIO_Girouette_PA0, GPIO_Girouette_PA1, GPIO_Girouette_PA2;
	
	Timer = t;
	
	GPIO_Girouette_PA0.GPIO = GPIOA;
	GPIO_Girouette_PA0.GPIO_Pin = 0;
	GPIO_Girouette_PA0.GPIO_Conf = In_Floating;
	MyGPIO_Init(& GPIO_Girouette_PA0);
	
	GPIO_Girouette_PA1.GPIO = GPIOA;
	GPIO_Girouette_PA1.GPIO_Pin = 1;
	GPIO_Girouette_PA1.GPIO_Conf = In_Floating;
	MyGPIO_Init(& GPIO_Girouette_PA1);
	
	// PA2 => Index
	GPIO_Girouette_PA2.GPIO = GPIOA;
	GPIO_Girouette_PA2.GPIO_Pin = 2;
	GPIO_Girouette_PA2.GPIO_Conf = In_Floating;
	MyGPIO_Init(& GPIO_Girouette_PA2);
	
	Timer->ARR = 360*4-1;
	Timer->PSC = 0;
	Timer->Timer = TIM2;
	
	MyTimer_Base_Init(Timer);
	MyTimer_Base_Start(Timer->Timer);
	MyTimer_Mode_Compteur_Incremental(Timer->Timer);
	
	EXTI->IMR |= EXTI_IMR_MR2;
	EXTI->RTSR |= EXTI_RTSR_TR2;
	girouette_ActiveIT_PA2(1);
}


float girouette_Calcul_Angle(void){
	 int value = Timer->Timer->CNT;
	 return (float)value /4.;
}

void girouette_ActiveIT_PA2 ( char Prio) 
{
	int interruptNumber ;
	interruptNumber = EXTI2_IRQn;
	
	NVIC_EnableIRQ(interruptNumber);
	NVIC_SetPriority(interruptNumber, Prio);
	
}

void EXTI2_IRQHandler(void)
{
	 Timer->Timer->CNT = 0;
}
