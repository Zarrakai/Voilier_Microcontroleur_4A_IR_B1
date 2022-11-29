#ifndef MYADC_H
#define MYADC_H
#include "stm32f10x.h"


 /*
**************************************************************************************************
* @param : ADC_TypeDef * myADC : ADC concerné
* Permet de : - configuer clock d'ADC
							- configurer l'ADC
							- activer l'ADC 
							- lancer une conversion
							- lancer la calibration de l'ADC et attendre la correction des erreurs
***************************************************************************************************/
void ADC_config(ADC_TypeDef * myADC);

 /*
**************************************************************************************************
* @param : ADC_TypeDef * myADC : ADC concerné
* Permet de : récupérer la data convertie de l'ADC
***************************************************************************************************/
uint16_t ADC_get_value_DR(ADC_TypeDef * myADC);


#endif

