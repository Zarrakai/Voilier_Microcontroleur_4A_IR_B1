#ifndef GIROUETTE_H
#define GIROUETTE_H
#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"


void girouette_init ( MyTimer_Struct_TypeDef *t, MyTimer_Struct_TypeDef *timerPWM);
float girouette_Calcul_Angle(void);
void girouette_envoie_periode_Servo_moteur(float periode);
float girouette_calcul_angle_Servo_moteur(float angle_girouette);

#endif
