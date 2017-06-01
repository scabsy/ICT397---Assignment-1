#ifndef __MYMATH_H
#define __MYMATH_H


#define PI 3.14159265358979323846
#define piOver180 PI/180

#include <stdlib.h>
#include <time.h>

double degToRad(double radians);///converts degrees to radians
double radToDeg(double radians);///converts radians to degrees

int getRand(int maxNum);///return random number between 1 and maxNum
#endif
