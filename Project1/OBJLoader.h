#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <freeglut.h>
#include "Mesh.h"

using namespace std;

struct coordinates
{
	float x, y, z;
	coordinates(float a, float b, float c) : x(a), y(b), z(c) {};
};

struct face
{
	int face_num;
	bool four;
	int faces[4];
	face(int facen, int f1, int f2, int f3) : face_num(facen)
	{
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		four = false;
	}
	face(int facen, int f1, int f2, int f3,int f4) : face_num(facen)
	{
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		faces[3] = f4;
		four = true;
	}
};


/**
* Define loader for 3d models
*/
class OBJLoader
{
private:
	vector<string*> coord;
	vector<coordinates*> vertex;
	vector<face*> faces;
	vector<coordinates*> normals;
public:
	/**
	* @brief Loads 3D model at location
	* @param filename - 3d model to load
	*/
	Mesh loadObject(const char* filename);
};


#endif
