#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <fstream>
#include <iostream>
#include "freeglut.h"
#include "Terrain.h"
using namespace std;

class BruteForce:public Terrain
{	
private:
	int flatten;

public:	
	int getFlatten() {return flatten;};
	void Render(void);
	BruteForce(void){};
	~BruteForce(void){};
};
#endif