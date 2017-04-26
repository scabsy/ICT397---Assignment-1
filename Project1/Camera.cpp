#include "Camera.h"
#include "freeglut.h"
#include "singletons.h"
#include <iostream>

Camera::Camera()
{
	size = gameWorld.terrain.getSize();
	dArray = new unsigned char [size*size];
	SetPos(10, 0, 10);
	SetLA(0, 0, -1);
	SetAcc(0, 0, 0);
	SetVel(0, 0, 0);

	yaw = 95;
	pitch = 0;
	/*for (int i = 0; i < size * size; i++)
	{
		dArray[i] = gameWorld.terrain.terrainData[i];
		
	}*/

}

Camera::Camera(vec3 *newPos)
{
	SetPos(newPos->x,newPos->y, newPos->z);
	SetLA(0, 0, 1);
	SetAcc(0, 0, 0);
	SetVel(0, 0, 0);

	yaw = 0;
	pitch = 0;
}

/*void Camera::SetTerrain(BruteForce ter)
{
	terrain = ter;
}*/

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
	vel.x += a;
	vel.y += b;
	vel.z += c;
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

	float speed = vel.z*deltaT;
	float strafespeed = vel.x*deltaT;

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
		accel.x = -vel.x * 1.5;
		accel.y = -vel.y * 1.5;
		accel.z = -vel.z * 1.5;
	}

	vel.x += accel.x*deltaT;
	vel.y += accel.y*deltaT;
	vel.z += accel.z*deltaT;
	
	pos.x += float(cos(degToRad(yaw + 90)))*strafespeed;
	pos.z += float(sin(degToRad(yaw + 90)))*strafespeed;
	pos.x += float(cosYaw)*speed;
	pos.z += float(sinYaw)*speed;
	pos.y = gameWorld.getWorldXZHeight(pos.x,pos.z) / 4 + 2;

	lookAt.x = (pos.x + cosYaw);
	lookAt.y = (pos.y + sinPitch);
	lookAt.z = (pos.z + sinYaw);

	gluLookAt(pos.x, pos.y, pos.z, lookAt.x, lookAt.y, lookAt.z, 0, 1, 0);
}