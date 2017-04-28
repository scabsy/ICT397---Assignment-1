#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vec3.h"
#include "freeglut.h"
#include "Mesh.h"
#include "Camera.h"
#include "AABB.h"
#include <string>
#include <iostream>

class GameObject
{
private:
	vec3 pos;
	float scale;
	Mesh model;
protected:
	void onCollision(GameObject &collisionObject);
	void onCollision(Camera &collisionObject);
	AABB boundingBox;
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

	void setModel(Mesh modelNum);
	Mesh getModel() { return model; }

	void processCollision(GameObject &obj);
	void processCollision(Camera &obj);

	void render();
};

#endif