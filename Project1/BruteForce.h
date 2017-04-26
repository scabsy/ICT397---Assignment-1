#include <fstream>
#include <iostream>
#include "freeglut.h"
#include "Terrain.h"
using namespace std;

class BruteForce:public Terrain
{		
public:
	void Render(void);
	BruteForce(void){};
	~BruteForce(void){};
};