#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <fstream>
#include <iostream>
#include "freeglut.h"
#include "Terrain.h"
using namespace std;

/**
*Renders the terrain in a brute force way
*/
class BruteForce:public Terrain
{	
private:
	int flatten;///flattens terrain

public:	
	int getFlatten() {return flatten;};///return flatten
	void Render(void);///draws terrain
	BruteForce(void){};
	~BruteForce(void){};
};
#endif