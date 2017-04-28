#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

void Mesh::SetID(int newid)
{
	id = newid;
}

void Mesh::SetMinMax(float miX, float miY, float miZ, float maX, float maY, float maZ)
{
	minX = miX;
	minY = miY;
	minZ = miZ;
	maxX = maX;
	maxY = maY;
	maxZ = maZ;
}

float Mesh::getSizeX()
{
	return maxX - minX;
}

float Mesh::getSizeY()
{
	return maxY - minY;
}

float Mesh::getSizeZ()
{
	return maxZ - minZ;
}