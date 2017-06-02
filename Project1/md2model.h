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
	MD2Frame* frames;///each frame in animation
	int numFrames;///Number of total frames
	MD2TexCoord *texCoords;///Texture coordinates
	MD2Triangle *triangles;///coordinates for each triangle
	int numTriangles;///number of triangles

	int startFrame;///Start frame of current animation
	int endFrame;///End frame of current animation

	/**
	* @brief Initialised MD2Model
	*/
	md2model();
public:
	~md2model();///Deletes pointers on destroy
	float time;///percentage value of animation between 0 and 1
	GLuint textureID;///ID of texture

	/**
	*@brief Sets current animation to name
	*@param name - name of the animation to be set
	*/
	void setAnimation(const char *name);

	/**
	*@brief Move the state of the animation forward by dt
	*@param dt - time passed since last advancement
	*/
	void advance(float dt);

	/**
	*@brief draws the model to the screen
	*/
	void draw();

	/**
	*@brief Load a model and returns a md2model
	*@param filename - path of model to load
	*/
	static md2model* load(const char *filename);

	Vector::vec3 minVals;///minimum values of model
	Vector::vec3 maxVals;///maximum values of model
};
#endif // !MD2MODEL_H
