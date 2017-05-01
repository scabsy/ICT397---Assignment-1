#include "Camera.h"
#include "freeglut.h"
#include "singletons.h"
#include <iostream>

Camera::Camera()
{
	SetPos(10, 0, 10);
	SetLA(0, 0, -1);
	SetAcc(0, 0, 0);
	SetVel(0, 0, 0);

	yaw = 95;
	pitch = 0;

	size = 2;

	isColliding = false;
}

Camera::Camera(vec3 *newPos)
{
	SetPos(newPos->x,newPos->y, newPos->z);
	SetLA(0, 0, 1);
	SetAcc(0, 0, 0);
	SetVel(0, 0, 0);

	yaw = 0;
	pitch = 0;

	size = 2;

	isColliding = false;
}

void Camera::SetPos(float a, float b, float c)
{
	pos.x = a;
	pos.y = b;
	pos.z = c;
}

void Camera::SetLA(float a, float b, float c)
{
	lookAt.x = a;
	lookAt.y = b;
	lookAt.z = c;
}

void Camera::SetAcc(float a, float b, float c)
{
	accel.x = a;
	accel.y = b;
	accel.z = c;
}

void Camera::SetVel(float a, float b, float c)
{
	vel.x = a;
	vel.y = b;
	vel.z = c;
}

void Camera::AddVel(float a, float b, float c)
{
	if (!isColliding)
	{
		vel.x += a;
		vel.y += b;
		vel.z += c;
	}
}

void Camera::Update(double deltaT)
{
	if (yaw >= 360 || yaw <= -360)
	{
		yaw = 0;
	}

	if (pitch > 60)
	{
		pitch = 60;
	}
	if (pitch < -60)
	{
		pitch = -60;
	}

	float cosYaw = (float)cos(degToRad(yaw));
	float sinYaw = (float)sin(degToRad(yaw));
	float sinPitch = (float)sin(degToRad(pitch));

	float speed = vel.z*(float)deltaT;
	float strafespeed = vel.x*(float)deltaT;

	if (speed > 15)
		speed = 15;
	if (speed < -15)
		speed = -15;
	if (strafespeed > 15)
		strafespeed = 15;
	if (strafespeed < -15)
		strafespeed = -15;

	if (sqrt((vel.x*vel.x) + (vel.y*vel.y) + (vel.z*vel.z)) > 0)
	{
		accel.x = -vel.x * 1.5f;
		accel.y = -vel.y * 1.5f;
		accel.z = -vel.z * 1.5f;
	}

	vel.x += accel.x*(float)deltaT;
	vel.y += accel.y*(float)deltaT;
	vel.z += accel.z*(float)deltaT;
	
	pos.x += float(cos(degToRad(yaw + 90)))*strafespeed;
	pos.z += float(sin(degToRad(yaw + 90)))*strafespeed;
	pos.x += float(cosYaw)*speed;
	pos.z += float(sinYaw)*speed;
	pos.y = gameWorld.getWorldXZHeight((int)pos.x,(int)pos.z) / 4 + 5;

	lookAt.x = (pos.x + cosYaw);
	lookAt.y = gameWorld.getWorldXZHeight((int)pos.x, (int)pos.z) / 4 + 5;//(pos.y + sinPitch);
	lookAt.z = (pos.z + sinYaw);

	/*if (pos.y < lookAt.y)
	{
		pos.y = lookAt.y;
	}*/

	gluLookAt(pos.x, pos.y, pos.z, lookAt.x, lookAt.y, lookAt.z, 0, 1, 0);
}