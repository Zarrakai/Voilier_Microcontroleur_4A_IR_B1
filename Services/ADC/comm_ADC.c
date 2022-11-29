#include "stm32f10x.h"
#include "comm_ADC.h"
#include "MyADC.h"


void comm_ADC_config(ADC_TypeDef * myADC){
	ADC_config(myADC);
}

uint16_t comm_get_value_ADC_DR(ADC_TypeDef * myADC) {
	return ADC_get_value_DR(myADC);
}





