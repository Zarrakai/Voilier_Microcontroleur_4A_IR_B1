#include "Girouette.h"
#include "Driver_GPIO.h"
#include "MyTimer.h"


float Calcul_Angle_Girouette(MyTimer_Struct_TypeDef Timer);

MyTimer_Struct_TypeDef Timer ;
void init_girouette ( void )
{
	MyTimer_Mode_Compteur_Incremental(Timer.Timer);
	Timer.ARR = 360*4-1;
	//timer.PSC = 9999;
	Timer.Timer =TIM2;
	
	
	MyTimer_Base_Init(&Timer);
	MyTimer_Base_Start(Timer.Timer);
	/*
	int cnt;
	do
	{
		float angle = Calcul_Angle_Girouette(Timer);
	}while ( 1 );*/
	
	
}
float Calcul_Angle_Girouette(MyTimer_Struct_TypeDef Timer){
	 int value = Timer.Timer->CNT;
	 return (float)value /4.;
}
