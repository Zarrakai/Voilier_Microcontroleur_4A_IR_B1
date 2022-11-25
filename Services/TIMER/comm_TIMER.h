#ifndef TIMER_H
#define TIMER_H
#include "stm32f10x.h"
#include "MyTimer.h"

/*************************** Partie Service *******************************************************/

 /*
**************************************************************************************************
* @param : - MyTimer_Struct_TypeDef * Timer : TIMER concerné
Permet de configurer le Timer choisi pour PWM, son ARR et son PSC
***************************************************************************************************/
void comm_PWM_conf_timer(MyTimer_Struct_TypeDef * Timer);


 /*
**************************************************************************************************
* @param : - MyTimer_Struct_TypeDef * Timer : TIMER concerné
					 - int Channel : un channel sur lequel on configure PWM 
Permet d'appeler la fonction MyTimer_PWM_conf( TIM_TypeDef * Timer, int Channel) depuis le Driver
***************************************************************************************************/
void comm_PWM_conf(MyTimer_Struct_TypeDef * Timer, int Channel);


 /*
**************************************************************************************************
* @param : - TIMER8TypeDef * Timer : TIMER concerné
					 - int8_t ratio : période cyclique de PWM
Permet d'appeler la fonction MyTimer_PWM_calculer_CCR(TIM_TypeDef * Timer, int8_t ratio) depuis le Driver
***************************************************************************************************/
int8_t comm_PWM_calculer_CCR(TIM_TypeDef * Timer, int8_t ratio);


 /*
**************************************************************************************************
* @param : - MyTimer_Struct_TypeDef * Timer : TIMER concerné
					 - int Channel : un channel sur lequel on configure PWM 
					 - int8_t CCR : la valeur à affecter au CCR
Permet d'appeler la fonction MyTimer_PWM_set_CCR( TIM_TypeDef * Timer, int Channel, int8_t CCR) depuis le Driver
***************************************************************************************************/
void comm_PWM_set_CCR(MyTimer_Struct_TypeDef * Timer, int Channel, int8_t CCR);


 /*
**************************************************************************************************
* @param : - MyTimer_Struct_TypeDef * Timer : TIMER concerné
						- MyGPIO_Struct_TypeDef* myGPIO : GPIO concerné
					 - int8_t value : la valeur reçue de la telecommande
Permet determiner le sens de rotation du bateau
***************************************************************************************************/
int comm_USART_data_sign(int8_t value, MyGPIO_Struct_TypeDef* myGPIO, MyTimer_Struct_TypeDef * Timer);


#endif
