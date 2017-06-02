#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vec3.h"
#include "freeglut.h"
#include "Mesh.h"
#include "Math.h"
#include "Camera.h"
#include "AABB.h"
#include "md2model.h"
#include <string>
#include <iostream>
#include "AI.h"

using namespace std;
/**
* Defines all objects in the game
*/
class GameObject
{
private:
	Vector::vec3 pos;///position of game object
	Vector::vec3 prevPos;///position of game object
	float rot;/// rotation in game
	float scale;/// objects scale in game
				//Mesh model;///3d model for object
	md2model* model;///3d model for object
	bool AICheck;///Whether object has ai or not
	string aiFilename;///Path to AI file 
	bool destoryed, isAnimated;
	bool isMoving;
	string tag;
protected:
	/**
	*@brief Checks foer collision with other objects
	*@param collisionObject - object to check collision with
	*/
	void onCollision(GameObject &collisionObject);

	/**
	*@brief Checks foer collision with camera
	*@param collisionObject - camera to check collision with
	*/
	void onCollision(Camera &collisionObject);

	AABB boundingBox;///Collision box
public:
	GameObject();///basic constuctor
	GameObject(Vector::vec3 loc, float nscale);/// overload constructor
	GameObject(float x, float y, float z, float nscale); /// overload constructor
	GameObject(char * model, float x, float y, float z, float nscale, bool aii, string filename, bool destory, string t, bool isAnimated); /// overload constructor
	bool isDestoryed();
	bool valid;
	bool isColliding;
	float getRot();
	void setRot(float rott);
	void setIsMoving(bool move);
	bool getIsMoving();

	/**
	* @brief Returns the position of the game object
	*/
	Vector::vec3 getPos() { return pos; }

	/**
	* @brief Returns the x position of the game object
	*/
	float getPosX() { return pos.x; }

	/**
	* @brief Returns the y position of the game object
	*/
	float getPosY() { return pos.y; }

	/**
	* @brief Returns the z position of the game object
	*/
	float getPosZ() { return pos.z; }

	/**
	* @brief Sets the position of the game object
	* @param x is pos x
	* @param y is pos y
	* @param z is pos z
	*/
	void setPosition(float x, float y, float z);

	/**
	* @brief Sets the position of the game object
	* @param vector containing x y z
	*/
	void setPosition(Vector::vec3 newPos);

	/**
	* @brief Sets the x position of the game object
	* @param float containing x
	*/
	void setPosX(float x);

	/**
	* @brief Sets the y position of the game object
	* @param float containing y
	*/
	void setPosY(float y);

	/**
	* @brief Sets the z position of the game object
	* @param float containing z
	*/
	void setPosZ(float z);

	/**
	* @brief Returns the Scale of the game object
	*/
	float getScale() { return scale; }

	/**
	* @brief Sets the scale of the game object
	* @param float containing the inputed scale
	*/
	void setScale(float newScale);

	/**
	* @brief Sets the model of the game object
	* @param Mesh object containing the inputed model
	*/
	void setModel(md2model* modelNum);

	/**
	* @brief Returns the model of the game object
	*/
	md2model* getModel() { return model; }

	/**
	* @brief Check for collision with the given game object
	* @param game object to check collision
	*/
	void processCollision(GameObject &obj);

	/**
	* @brief Check for collision with the given camera object
	* @param camera object to check collision
	*/
	void processCollision(Camera &obj);

	void Update(Camera &obj);

	/**
	* @brief creates the objects model in game by translating and inputing the scale information then calling methods in opengl
	*/
	void render(float deltaT);

	/**
	* @brief Returns AICheck
	*/
	bool hasAI();

	string getTag();
	void setTag(string t);
	bool getAnimation();
};

#endif