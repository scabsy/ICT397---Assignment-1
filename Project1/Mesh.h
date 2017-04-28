#ifndef MESH_H
#define MESH_H

#include <vector>
class Mesh
{
private:
	int id;
	float minX, minY, minZ;
	float maxX, maxY, maxZ;

public:
	Mesh();
	~Mesh();
	int GetID() { return id; }
	void SetID(int newid);

	void SetMinMax(float miX, float miY, float miZ, float maX, float maY, float maZ);
	float getSizeX();
	float getSizeY();
	float getSizeZ();

};

#endif