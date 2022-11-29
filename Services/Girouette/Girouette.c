#include "Girouette.h"



MyTimer_Struct_TypeDef *Timer, *TimerPWM;
void girouette_calibrer_timer (void);
int ratio;

void girouette_init ( MyTimer_Struct_TypeDef *t, MyTimer_Struct_TypeDef *timerPWM)
{
	MyGPIO_Struct_TypeDef GPIO_Girouette_PA0, GPIO_Girouette_PA1, GPIO_Girouette_PB2, GPIO_PWM_PB1;
	
	Timer = t;
	TimerPWM = timerPWM;
	
	// PA0 et PA1 => Pin 0 et 1 de la girouette
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
	
	// PWM
	
	GPIO_PWM_PB1.GPIO = GPIOB;
	GPIO_PWM_PB1.GPIO_Pin = 1;
	GPIO_PWM_PB1.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(& GPIO_PWM_PB1);
	
	TimerPWM->Timer = TIM3;
	TimerPWM->ARR = 143;
	TimerPWM->PSC = 9999;
	MyTimer_Base_Init(TimerPWM);
	MyTimer_Base_Start(TimerPWM->Timer);
	MyTimer_PWM_conf( TimerPWM->Timer , 4);	//PB1 pour TIM3 CH4
	
}
	

float girouette_Calcul_Angle(void){
	 int value = Timer->Timer->CNT;
	 return (float)value /4.;
}


void girouette_calibrer_timer(void)
{
	Timer->Timer->CNT = 0;
}


float girouette_calcul_angle_Servo_moteur(float angle_girouette)
{
	if ((angle_girouette >= 0.0 && angle_girouette < 45.0)){
		return -90.0;
	}
	if ((angle_girouette > 335.0 && angle_girouette <= 380.0)){
		return 90.0;
	}
	else if (angle_girouette >= 45.0 && angle_girouette <= 335.0){
		return (2.0/3.0) * angle_girouette - 120.0;
	}
	else
		return 0.;
}

void girouette_envoie_periode_Servo_moteur(float periode)
{
	ratio = (int)((5.0/9.0)*periode+50);
	MyTimer_PWM_set_CCR(TimerPWM->Timer, 4, MyTimer_PWM_calculer_CCR(TimerPWM->Timer, ratio));
}