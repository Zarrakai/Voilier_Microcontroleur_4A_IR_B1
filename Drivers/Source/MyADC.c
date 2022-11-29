#include "MyADC.h"
#include "stm32f10x.h"

void ADC_config(ADC_TypeDef * myADC){	
	if (myADC == ADC1) {
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	}
	else if(myADC == ADC2) {
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	} 
	
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6; 			// diviser par 6 la fréquence d'entrée
	myADC->CR2 |= ADC_CR2_ADON;							// lancer l'ADC
	myADC->SQR1 |= (0<<20);									// pour une seule conversion
	myADC->SQR3 |= 8;												// la conversion s'effectue au niveau de la 8ème voie
	myADC->SMPR1 |= (7<<24);									// la durée d'échanntillonage 	
	myADC->CR2 |= ADC_CR2_CAL;							// lancer la calibration
	
	while(myADC->CR2 & ADC_CR2_CAL);				// attendre la correction des erreurs de mesure
}

uint16_t ADC_get_value_DR(ADC_TypeDef * myADC){
  myADC->CR2 |= ADC_CR2_ADON;
	//while(!(myADC->SR & ADC_SR_EOC));				// attendre de la fin de conversion
  
	ADC1->SR &= ~ADC_SR_EOC; 								// remettre EOC à 0 pour la prochaine conversion
  return (myADC->DR & 0x0FFF); 						// retourner data convertie, que les 16 bits de DR
}

	
	
	



