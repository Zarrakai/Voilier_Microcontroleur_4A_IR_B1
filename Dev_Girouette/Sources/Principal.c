#include "comm_GIROUETTE.h"


int main ( void )
{
	comm_girouette_init();
	do
	{
		comm_servo_moteur_update();
	}while ( 1 );
}
