#ifndef _CAMERA_H
#define _CAMERA_H
#pragma once

#include "Math.h"
#include "vec3.h"
#include "AABB.h"
/**
*Define players camera
*/
class Camera
{
private:
protected:

public:
	bool isColliding;///check if camera is colliding with other object
	float size;///Size of the camera in the world
	Camera();///basic constructor to initialize 
	Camera(Vector::vec3 *newPos);/// overload constucto to initialize with a vector 3 given
	AABB aabb;///Collison box
	/**
	* Called every frame to update the position of the camera
	* @param cosYaw cameras left and right calculation
	* @param sinYaw cameras left and right calculation
	* @param sinPitch cameras up and down calculation
	* @param Speed how fast the camera moves
	* @param strafespeed how fast teh camera moves left and right
	* returns void
	*/
	void Update(double deltaT);

	/**
	* Sets the positon of the camera
	* @param a is x
	* @param b is y
	* @param c is z
	*/
	void SetPos(float a, float b, float c);

	/**
	* Sets the the view point of the camera
	* @param a is x
	* @param b is y
	* @param c is z
	*/
	void SetLA(float a, float b, float c);

	/**
	* Sets how fast the camera is increasing in movement
	* @param a is x
	* @param b is y
	* @param c is z
	*/
	void SetAcc(float a, float b, float c);

	/**
	* Sets how fast the camera is moving
	* @param a is x
	* @param b is y
	* @param c is z
	*/
	void SetVel(float a, float b, float c);

	/**
	* increases speed
	* @param a is x
	* @param b is y
	* @param c is z
	*/
	void AddVel(float a, float b, float c);

	Vector::vec3 pos;/// position of camera
	Vector::vec3 prevPos;/// previous position of camera
	Vector::vec3 lookAt;/// focal point of camera
	Vector::vec3 accel; /// how fast the camera increases in speed
	Vector::vec3 vel;/// how fast the camera is moving
	float yaw; /// vertical view
	float pitch;/// horizontal view
};

#endif