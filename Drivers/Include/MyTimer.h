#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"
#include "Driver_GPIO.h"

typedef struct
{
	TIM_TypeDef * Timer ; // TIM1 à TIM4
	unsigned short ARR ;
	unsigned short PSC ;
} MyTimer_Struct_TypeDef ;



/*
**************************************************************************************************
* @param : - MyTimer_Struct_TypeDef * Timer : Timer concerne
* Permet de configurer Clock, ARR et PSC
***************************************************************************************************/
void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) ;


/*
**************************************************************************************************
* @param : - TIM_TypeDef * Timer : Timer concerne
* 				 - int Channel : un channel sur lequel on configure PWM 
* Permet de selectionner le GPIO convenable au Timer et au Channel passeés en paramètres et le configurer
* pour envoyer un signal PWM
***************************************************************************************************/
void MyTimer_PWM_conf( TIM_TypeDef * Timer, int Channel) ;


/*
**************************************************************************************************
* @param : - TIM_TypeDef * Timer : Timer concerné
* 				 - int Channel : un channel sur lequel on a configuré PWM
*					 - int8_t CCR : la valeur à affecter au CCR
* Permet de donner au CCR un valeur
***************************************************************************************************/
void MyTimer_PWM_set_CCR( TIM_TypeDef * Timer, int Channel, int8_t CCR);


/*
**************************************************************************************************
* @param : - TIM_TypeDef * Timer : Timer concerné
* 				 - int8_t ratio :
***************************************************************************************************/
int8_t MyTimer_PWM_calculer_CCR(TIM_TypeDef * Timer, int ratio);


/**/
void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio , void (*IT_function ) ( void )) ;


/**/
int My_Timer_Get_CRR(TIM_TypeDef * Timer);


/**/
void My_Timer_Set_ARR(TIM_TypeDef * Timer,int value);


/**/
void My_Timer_Set_PSC(TIM_TypeDef * Timer,int value);
	

/**/
void MyTimer_Mode_Compteur_Incremental(TIM_TypeDef * Timer);


/**/
void MyGPIO_ActiveIT_EXTI2_PB2 ( char Prio, void (*IT_function ) ( void )) ;



#define MyTimer_Base_Start(Timer)( Timer->CR1 |= 0x1)
#define MyTimer_Base_Stop(Timer)( Timer->CR1 &= ~0x1)

#endif 
