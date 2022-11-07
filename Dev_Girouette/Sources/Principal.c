#include "Girouette.h"
#include "Driver_GPIO.h"

// test
int main ( void )
{
	MyTimer_Struct_TypeDef Timer;
		
	girouette_init(&Timer);
	do
	{
		float angle = girouette_Calcul_Angle(Timer);
	}while ( 1 );
}


