#include "Girouette.h"


void girouette_init ( MyTimer_Struct_TypeDef *Timer)
{
	MyGPIO_Struct_TypeDef GPIO_Girouette_0, GPIO_Girouette_1 ;
		
	GPIO_Girouette_0.GPIO = GPIOA;
	GPIO_Girouette_0.GPIO_Pin = 0;
	GPIO_Girouette_0.GPIO_Conf = In_Floating;
	MyGPIO_Init(& GPIO_Girouette_0);
	
	GPIO_Girouette_1.GPIO = GPIOA;
	GPIO_Girouette_1.GPIO_Pin = 1;
	GPIO_Girouette_1.GPIO_Conf = In_Floating;
	MyGPIO_Init(& GPIO_Girouette_1);
	
	Timer->ARR = 360*4-1;
	Timer->PSC = 0;
	Timer->Timer = TIM2;
	
	MyTimer_Base_Init(Timer);
	MyTimer_Base_Start(Timer->Timer);
	MyTimer_Mode_Compteur_Incremental(Timer->Timer);
	
}
float girouette_Calcul_Angle(MyTimer_Struct_TypeDef Timer){
	 int value = Timer.Timer->CNT;
	 return (float)value /4.;
}

