#ifndef GIROUETTE_H
#define GIROUETTE_H
#include "stm32f10x.h"
#include "MyTimer.h"



void init_girouette ( MyTimer_Struct_TypeDef *Timer );
float Calcul_Angle_Girouette(MyTimer_Struct_TypeDef Timer);

#endif
