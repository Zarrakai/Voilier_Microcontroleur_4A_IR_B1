#include "comm_GPIO.h"
#include "comm_TIMER.h"
#include "comm_GIROUETTE.h"

/*** FONCTIONS PRIVEES ***/
void comm_girouette_calibrer_timer (void);
float comm_girouette_Calcul_Angle(void);
void comm_girouette_envoie_periode_Servo_moteur(float periode);
float comm_girouette_calcul_angle_Servo_moteur(float angle_girouette);

/*** VARIABLES GLOBALES ***/
MyTimer_Struct_TypeDef Timer, TimerPWM;
int ratio;
float angleServoMoteur = 0.0;
float angleGirouette = 0.0;

void comm_girouette_init (void)
{
	MyGPIO_Struct_TypeDef GPIO_Girouette_PA0, GPIO_Girouette_PA1, GPIO_Girouette_PB2, GPIO_PWM_PB1;
	
	
	// PA0 et PA1 => Pin 0 et 1 de la girouette
	comm_MyGPIO_Init(&GPIO_Girouette_PA0,GPIOA,0,In_Floating);
	comm_MyGPIO_Init(&GPIO_Girouette_PA1,GPIOA,1,In_Floating);
	
	// PB2 => Index girouette
	comm_MyGPIO_Init(&GPIO_Girouette_PB2,GPIOB,2,In_Floating);
	
	Timer.Timer = TIM2;
	comm_conf_timer(&Timer, 360*4-1, 0);
	comm_Girouette_conf_timer(&Timer);
	
	
	MyGPIO_Activate_AFIO();
	MyGPIO_Config_exti2PB();
	MyGPIO_ActiveIT_EXTI2_PB2(1,&comm_girouette_calibrer_timer);
	
	// PWM
	comm_MyGPIO_Init(&GPIO_PWM_PB1,GPIOB,1,Out_Ppull);
	
	TimerPWM.Timer = TIM3;
	comm_conf_timer(&TimerPWM,143, 9999);
	MyTimer_PWM_conf(TimerPWM.Timer , 4);	//PB1 pour TIM3 CH4
	
}

void comm_servo_moteur_update(void){
	angleGirouette = comm_girouette_Calcul_Angle();
	angleServoMoteur = comm_girouette_calcul_angle_Servo_moteur(angleGirouette);
	comm_girouette_envoie_periode_Servo_moteur(angleServoMoteur);
}

float comm_girouette_Calcul_Angle(void){
	 int value = My_Timer_Get_CNT(Timer.Timer);
	 return (float)value /4.;
}

void comm_girouette_calibrer_timer(void)
{
	My_Timer_Set_CNT(Timer.Timer, 0);
}

float comm_girouette_calcul_angle_Servo_moteur(float angle_girouette)
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

void comm_girouette_envoie_periode_Servo_moteur(float periode)
{
	ratio = (int)((5.0/9.0)*periode+50);
	MyTimer_PWM_set_CCR(TimerPWM.Timer, 4, MyTimer_PWM_calculer_CCR(TimerPWM.Timer, ratio));
}
