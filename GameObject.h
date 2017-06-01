#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vec3.h"
#include "freeglut.h"
#include "Mesh.h"
#include "Math.h"
#include "Camera.h"
#include "AABB.h"
#include "AI.h"
#include <string>
#include <iostream>
using namespace std;
/**
* Defines all objects in the game
*/
class GameObject
{
private:
	vec3 pos;///position of game object
	float rot;/// rotation in game
	float scale;/// objects scale in game
	Mesh model;///3d model for object
	bool AICheck;
	string aiFilename;
protected:
	void onCollision(GameObject &collisionObject);
	void onCollision(Camera &collisionObject);
	AABB boundingBox;
public:
	GameObject();///basic constuctor
	GameObject(vec3 loc, float nscale);/// overload constructor
	GameObject(float x, float y, float z,float nscale); /// overload constructor
	GameObject(char * model,float x, float y, float z, float nscale); /// overload constructor
	GameObject(char * nmodel, float x, float y, float z, float nscale, bool aii, string filename);/// overload constructor MT

	/**
	* @breif Returns the position of the game object
	*/
	vec3 getPos() { return pos; }

	/**
	* @breif Returns the x position of the game object
	*/
	float getPosX() { return pos.x; }

	/**
	* @breif Returns the y position of the game object
	*/
	float getPosY() { return pos.y; }

	/**
	* @breif Returns the z position of the game object
	*/
	float getPosZ() { return pos.z; }

	/**
	* @breif Sets the position of the game object
	* @param x is pos x
	* @param y is pos y
	* @param z is pos z
	*/
	void setPosition(float x, float y, float z);

	/**
	* @breif Sets the position of the game object
	* @param vector containing x y z
	*/
	void setPosition(vec3 newPos);

	/**
	* @breif Sets the x position of the game object
	* @param float containing x
	*/
	void setPosX(float x);

	/**
	* @breif Sets the y position of the game object
	* @param float containing y
	*/
	void setPosY(float y);

	/**
	* @breif Sets the z position of the game object
	* @param float containing z
	*/
	void setPosZ(float z);

	/**
	* @breif Returns the Scale of the game object
	*/
	float getScale() { return scale; }

	/**
	* @breif Sets the scale of the game object
	* @param float containing the inputed scale
	*/
	void setScale(float newScale);

	/**
	* @breif Sets the model of the game object
	* @param Mesh object containing the inputed model
	*/
	void setModel(Mesh modelNum);

	/**
	* @breif Returns the model of the game object
	*/
	Mesh getModel() { return model; }

	/**
	* @breif Check for collision with the given game object
	* @param game object to check collision
	*/
	void processCollision(GameObject &obj);

	/**
	* @breif Check for collision with the given camera object
	* @param camera object to check collision
	*/
	void processCollision(Camera &obj);

	/**
	* @breif creates the objects model in game by translating and inputing the scale information then calling methods in opengl
	*/
	void render();

	/**
	* @breif Returns AICheck
	*/
	bool hasAI();
	void Update(Camera &cam);
};

#endif