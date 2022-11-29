#ifndef ADC_H
#define ADC_H
#include "stm32f10x.h"
#include "MyADC.h"

/*************************** Partie Service *******************************************************/

/* Configurer l'ADC */
void comm_ADC_config(ADC_TypeDef * myADC);

/* permet de récupérer la valeur de DR de l'ADC */
uint16_t comm_get_value_ADC_DR(ADC_TypeDef * myADC);


#endif

