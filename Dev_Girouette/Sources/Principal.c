#include "Girouette.h"

// test
int main ( void )
{
	MyTimer_Struct_TypeDef Timer;
	init_girouette(&Timer);
	do
	{
		float angle = Calcul_Angle_Girouette(Timer);
	}while ( 1 );
}


