#include "stm32f10x.h"
#include "MyTimer.h"

void (*ptFonction ) ( void );
void (*ptFonction_EXTI2 ) ( void );


void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer )
	{
		if (Timer->Timer == TIM1){
			RCC->APB1ENR |= RCC_APB2ENR_TIM1EN;
		}
		else if (Timer->Timer == TIM2){
			RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
		}
		else if (Timer->Timer == TIM3){
			RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
		}
		else if (Timer->Timer == TIM4){
			RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
		}
		
		Timer->Timer->ARR = Timer->ARR;
	  Timer->Timer->PSC = Timer->PSC; 		
}


void MyTimer_PWM_conf( TIM_TypeDef * Timer, int Channel){
	
	MyGPIO_Struct_TypeDef  GPIOStruct;
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	GPIOStruct.GPIO_Conf = AltOut_Ppull;
	
	if (Timer == TIM1) {
		switch (Channel) {
			case 1:
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 8;
				Timer->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
				Timer->CCMR1 |= TIM_CCMR1_OC1PE;
				Timer->CCER |= TIM_CCER_CC1E;
				break;
		
		case 2 :
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 9;
				Timer->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; 
				Timer->CCMR1 |= TIM_CCMR1_OC2PE;
				Timer->CCER |= TIM_CCER_CC2E;	
				break;
		
		case 3 :
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 10;
				Timer->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2; 
				Timer->CCMR2 |= TIM_CCMR2_OC3PE;
				Timer->CCER |= TIM_CCER_CC3E;
				break;
		
		case 4 :
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 11;
				Timer->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2; 
				Timer->CCMR2 |= TIM_CCMR2_OC4PE;
				Timer->CCER |= TIM_CCER_CC4E;
				break;
		}
	}
	
	
	if (Timer == TIM2) {
		switch (Channel) {
			case 1:
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 0;
				Timer->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
				Timer->CCMR1 |= TIM_CCMR1_OC1PE;
				Timer->CCER |= TIM_CCER_CC1E;
				break;
		
		case 2 :
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 1;
				Timer->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; 
				Timer->CCMR1 |= TIM_CCMR1_OC2PE;
				Timer->CCER |= TIM_CCER_CC2E;	
				break;
		
		case 3 :
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 2;
				Timer->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2; 
				Timer->CCMR2 |= TIM_CCMR2_OC3PE;
				Timer->CCER |= TIM_CCER_CC3E;
				break;
		
		case 4 :
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 3;
				Timer->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2; 
				Timer->CCMR2 |= TIM_CCMR2_OC4PE;
				Timer->CCER |= TIM_CCER_CC4E;
				break;
		}
	}
	
	
	if (Timer == TIM3) {
		switch (Channel) {
			case 1:
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 6;
				Timer->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
				Timer->CCMR1 |= TIM_CCMR1_OC1PE;
				Timer->CCER |= TIM_CCER_CC1E;
				break;
		
		case 2 :
				GPIOStruct.GPIO = GPIOA;
				GPIOStruct.GPIO_Pin = 7;
				Timer->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; 
				Timer->CCMR1 |= TIM_CCMR1_OC2PE;
				Timer->CCER |= TIM_CCER_CC2E;	
				break;
		
		case 3 :
				GPIOStruct.GPIO = GPIOB;
				GPIOStruct.GPIO_Pin = 0;
				Timer->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2; 
				Timer->CCMR2 |= TIM_CCMR2_OC3PE;
				Timer->CCER |= TIM_CCER_CC3E;
				break;
		
		case 4 :
				GPIOStruct.GPIO = GPIOB;
				GPIOStruct.GPIO_Pin = 1;
				Timer->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2; 
				Timer->CCMR2 |= TIM_CCMR2_OC4PE;
				Timer->CCER |= TIM_CCER_CC4E;
				break;
		}
	}
	
	if (Timer == TIM4) {
		switch (Channel) {
			case 1:
				GPIOStruct.GPIO = GPIOB;
				GPIOStruct.GPIO_Pin = 6;
				Timer->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
				Timer->CCMR1 |= TIM_CCMR1_OC1PE;
				Timer->CCER |= TIM_CCER_CC1E;
				break;
		
		case 2 :
				GPIOStruct.GPIO = GPIOB;
				GPIOStruct.GPIO_Pin = 7;
				Timer->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; 
				Timer->CCMR1 |= TIM_CCMR1_OC2PE;
				Timer->CCER |= TIM_CCER_CC2E;	
				break;
		
		case 3 :
				GPIOStruct.GPIO = GPIOB;
				GPIOStruct.GPIO_Pin = 8;
				Timer->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2; 
				Timer->CCMR2 |= TIM_CCMR2_OC3PE;
				Timer->CCER |= TIM_CCER_CC3E;
				break;
		
		case 4 :
				GPIOStruct.GPIO = GPIOB;
				GPIOStruct.GPIO_Pin = 9;
				Timer->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2; 
				Timer->CCMR2 |= TIM_CCMR2_OC4PE;
				Timer->CCER |= TIM_CCER_CC4E;
				break;
		}
	}
	
	MyGPIO_Init(&GPIOStruct);
	Timer->CR1 |= TIM_CR1_ARPE;
}


void MyTimer_PWM_set_CCR( TIM_TypeDef * Timer, int Channel, int8_t CCR){
	
	switch (Channel) {
			case 1:
				Timer->CCR1 = CCR;
				break;
		
		case 2 :
				Timer->CCR2 = CCR;
				break;
		
		case 3 :
				Timer->CCR3 = CCR;
				break;
		
		case 4 :
				Timer->CCR4 = CCR;
				break;
	}
}

int8_t MyTimer_PWM_calculer_CCR(TIM_TypeDef * Timer, int ratio){
	return (int8_t)((ratio/1000.)*Timer->ARR);
}

void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio , void (*IT_function ) ( void )) 
{
	int interruptNumber ;
	Timer->DIER |= TIM_DIER_UIE;	// on active UIE
	Timer->SR &= ~(0x01);
	
	
	if (Timer == TIM1 ){
		interruptNumber = TIM1_CC_IRQn ;
	}
	else if (Timer == TIM2 ){
		interruptNumber = TIM2_IRQn;
	}
	else if (Timer == TIM3){
		interruptNumber = TIM3_IRQn;
	}
	else if (Timer == TIM4){
		interruptNumber = TIM4_IRQn;
	}
	
	NVIC_EnableIRQ(interruptNumber);
	NVIC_SetPriority(interruptNumber, Prio);
	
	ptFonction = IT_function;
}


int My_Timer_Get_CRR(TIM_TypeDef * Timer){
	return Timer->ARR;
}
int My_Timer_Get_CNT(TIM_TypeDef * Timer){
	return Timer->CNT;
}


void My_Timer_Set_ARR(TIM_TypeDef * Timer,int value){
	Timer->ARR = value;
}

void My_Timer_Set_PSC(TIM_TypeDef * Timer,int value){
	Timer->PSC = value;
}

void My_Timer_Set_CNT(TIM_TypeDef * Timer,int value){
	Timer->CNT = value;
}

void MyTimer_Mode_Compteur_Incremental(TIM_TypeDef * Timer){
	//on met sms a 011
	Timer->SMCR |= TIM_SMCR_SMS_0;
	Timer->SMCR |= TIM_SMCR_SMS_1;
	Timer->CCMR1 |= TIM_CCMR1_CC1S_1; 
	Timer->CCMR1 |= TIM_CCMR1_CC2S_1;
	Timer->CCER  &= ~TIM_CCER_CC1P ;
	Timer->CCER  &= ~TIM_CCER_CC2P;
	Timer->CCER  &= ~TIM_CCER_CC1NP;
	Timer->CCER  &= ~TIM_CCER_CC2NP ;
	Timer->CCMR1  &= ~TIM_CCMR1_IC1F;
	Timer->CCMR1  &= ~TIM_CCMR1_IC2F;
	//Timer->CR1  |= TIM_CR1_CEN;	
	// déjà fait dans start

}

void MyGPIO_ActiveIT_EXTI2_PB2 ( char Prio, void (*IT_function ) ( void )) 
{
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_SetPriority(EXTI2_IRQn, Prio);
	
	ptFonction_EXTI2 = IT_function;
}

void TIM2_IRQHandler(void)
{
	// désactivation de UIF
	TIM2->SR &= ~(0x01);
	(*ptFonction)();
	
}

void EXTI2_IRQHandler(void)
{
	// désactivation de UIF
	EXTI->PR |= EXTI_PR_PR2;
	(*ptFonction_EXTI2)();
	
}
