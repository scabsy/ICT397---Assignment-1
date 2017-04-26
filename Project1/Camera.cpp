#include "Camera.h"
#include "freeglut.h"
#include "singletons.h"
#include <iostream>

Camera::Camera()
{
	SetPos(0, 0, 0);
	SetLA(0, 0, -1);
	SetAcc(0, 0, 0);
	SetVel(0, 0, 0);

	yaw = 95;
	pitch = 0;
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

void Camera::Update()
{
	if (yaw >= 360 || yaw <= -360)
	{
		yaw = 0.0f;
	}

	if (pitch > 60.0f)
	{
		pitch = 60.0f;
	}
	if (pitch < -60.0f)
	{
		pitch = -60.0f;
	}

	float cosYaw = (float)cos(degToRad(yaw));
	float sinYaw = (float)sin(degToRad(yaw));
	float sinPitch = (float)sin(degToRad(pitch));

	float speed = vel.z;
	float strafespeed = vel.x;

	if (speed > 15.0)
		speed = 15.0;
	if (speed < -15.0)
		speed = -15.0;
	if (strafespeed > 15.0)
		strafespeed = 15.0;
	if (strafespeed < -15.0)
		strafespeed = -15.0;

	if (sqrt((vel.x*vel.x) + (vel.y*vel.y) + (vel.z*vel.z)) > 0.0)
	{
		accel.x = -vel.x * 1.5f;
		accel.y = -vel.y * 1.5f;
		accel.z = -vel.z * 1.5f;
	}

	vel.x += accel.x;
	vel.y += accel.y;
	vel.z += accel.z;

	pos.x += float(cos(degToRad(yaw + 90.0)))*strafespeed;
	cout << pos.x << endl;
	pos.z += float(sin(degToRad(yaw + 90.0)))*strafespeed;
	pos.x += float(cosYaw)*speed;
	pos.z += float(sinYaw)*speed;
	pos.y = gameWorld.terrain.getHeight(pos.x, pos.y) + 0.1;

	lookAt.x = (pos.x + cosYaw);
	lookAt.y = (pos.y + sinPitch);
	lookAt.z = (pos.z + sinYaw);

	gluLookAt(pos.x, pos.y, pos.z, lookAt.x, lookAt.y, lookAt.z, 0.0, 1.0, 0.0);
}