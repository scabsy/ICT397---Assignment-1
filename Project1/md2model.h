#pragma once
#ifndef MD2MODEL_H
#define MD2MODEL_H

#include "freeglut.h"
#include "vec3f.h"
#include "vec3.h"

using namespace std;

struct MD2Vertex
{
	Vec3f pos;
	Vec3f normal;
};

struct MD2Frame
{
	char name[16];
	MD2Vertex *vertices;
};

struct MD2TexCoord
{
	float texCoordX;
	float texCoordY;
};

struct MD2Triangle
{
	int vertices[3];
	int texCoords[3];
};

class md2model
{
private:
	MD2Frame* frames;
	int numFrames;
	MD2TexCoord *texCoords;
	MD2Triangle *triangles;
	int numTriangles;

	int startFrame;
	int endFrame;


	md2model();
public:
	~md2model();
	float time;
	GLuint textureID;
	void setAnimation(const char *name);

	void advance(float dt);
	void draw();
	static md2model* load(const char *filename);

	Vector::vec3 minVals;
	Vector::vec3 maxVals;
};
#endif // !MD2MODEL_H
