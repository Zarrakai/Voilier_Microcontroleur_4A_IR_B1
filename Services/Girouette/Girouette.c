#include "Girouette.h"
#include "Driver_GPIO.h"


void init_girouette ( MyTimer_Struct_TypeDef *Timer )
{
	
	MyTimer_Mode_Compteur_Incremental(Timer->Timer);
	Timer->ARR = 360*4-1;
	Timer->Timer =TIM2;
	MyTimer_Base_Init(Timer);
	MyTimer_Base_Start(Timer->Timer);
	
}
float Calcul_Angle_Girouette(MyTimer_Struct_TypeDef Timer){
	 int value = Timer.Timer->CNT;
	 return (float)value /4.;
}

