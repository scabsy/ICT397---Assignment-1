#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vec3.h"
#include "freeglut.h"
#include <string>
#include <iostream>

class GameObject
{
private:
	vec3 pos;
	float scale;
	int model;
protected:
	
public:
	GameObject();
	GameObject(vec3 loc, float nscale);
	GameObject(float x, float y, float z,float nscale);
	GameObject(char * model,float x, float y, float z, float nscale);

	vec3 getPos() { return pos; }
	float getPosX() { return pos.x; }
	float getPosY() { return pos.y; }
	float getPosZ() { return pos.z; }

	void setPosition(float x, float y, float z);
	void setPosition(vec3 newPos);
	void setPosX(float x);
	void setPosY(float y);
	void setPosZ(float z);

	float getScale() { return scale; }
	void setScale(float newScale);

	void setModel(int modelNum);

	void render();
};

#endif