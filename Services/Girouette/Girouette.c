#include "Girouette.h"
#include "Driver_GPIO.h"


void girouette_init ( MyTimer_Struct_TypeDef *Timer )
{
	/*
	A FAIRE : 
	Activer le GPIO A ici avec MyGPIO_Init car on l'utilise pour PA0 et PA1
	
	*/
	Timer->ARR = 360*4-1;
	Timer->PSC=0;
	Timer->Timer =TIM2;
	MyTimer_Base_Init(Timer);
	MyTimer_Base_Start(Timer->Timer);
	MyTimer_Mode_Compteur_Incremental(Timer->Timer);
	
}
float girouette_Calcul_Angle(MyTimer_Struct_TypeDef Timer){
	 int value = Timer.Timer->CNT;
	 return (float)value /4.;
}

