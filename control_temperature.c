#include "control_temperature.h"


void conTemInit(void)
{
	P2  = 0xff;
}
void coldDown(void)
{
	P20 = 1;
	P21 = 1;
	P22 = 0;
	P23 = 0;
}
void warmUp(void)
{
	P20 = 0;
	P21 = 0;
	P22 = 1;
	P23 = 1;
}
