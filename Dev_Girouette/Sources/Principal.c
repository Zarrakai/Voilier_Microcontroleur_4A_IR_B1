#include "Girouette.h"
#include "Driver_GPIO.h"


float angleServoMoteur = 0.0;
float angle = 0.0;

int main ( void )
{
	MyTimer_Struct_TypeDef Timer;
	MyTimer_Struct_TypeDef TimerPWM;
		
	girouette_init(&Timer,&TimerPWM);
	do
	{
		angle = girouette_Calcul_Angle();
		angleServoMoteur = girouette_calcul_angle_Servo_moteur(angle);
		girouette_envoie_periode_Servo_moteur(angleServoMoteur);
		
	}while ( 1 );
}


