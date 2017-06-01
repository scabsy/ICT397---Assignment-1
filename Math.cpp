#include "Math.h"

double degToRad(double degrees)
{
	return degrees * piOver180;
}

double radToDeg(double radians)
{
	return radians * (180/PI);
}


int getRand(int maxNum)
{
	srand(time(NULL));
	return rand() % maxNum + 1;
}