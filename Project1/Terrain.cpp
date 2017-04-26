#include "terrain.h"
#include "singletons.h"

bool Terrain::loadHeightfield(char *filename, const int size)
{
	//open for binary read
	ifstream infile(filename, ios::binary);
	if (!infile) { 
		cerr << "Cannot open file : " << filename << endl;
		return false;
	}
	//allocate memory
	if (terrainData)
		delete[] terrainData;
	if (size>0)
		terrainData = new unsigned char[size*size];
	if (terrainData == NULL)
		return false;
	//read in heightfield.
	// get length of file:
	infile.seekg(0, ios::end);
	int length = infile.tellg();
	// read data as a block:
	infile.seekg(0, ios::beg);
	infile.read(reinterpret_cast<char *>(terrainData), length);
	infile.close();
	this->size = size;
	return true;
}


void Terrain::loadTexture(char *filename, const int size)
{
	texture = texLoad.LoadTexture(filename, size);
	if (texture != -1)
	{
		textureMapping = true;
	}
}

void Terrain::setScalingFactor(float xScale, float yScale, float zScale) 
{
	scaleX = xScale;
	scaleY = yScale;
	scaleZ = zScale;
}

float Terrain::getHeight(int xpos, int zpos) {
	if (inbounds(xpos, zpos)) {
		return ((float)(terrainData[(zpos*size) + xpos])*scaleY);
	}
	else {
		return 0;
	}
}

unsigned char Terrain::getHeightColor(int xpos, int zpos) {
	if (inbounds(xpos, zpos)) {
		return (terrainData[((int)(zpos/(size*scaleZ)*size)) + (int)(xpos / (size*scaleZ))]);
	}
	return 1;
}

bool Terrain::inbounds(int xp, int yp)
{
	if (xp >= 0 && xp < size && yp >= 0 && yp < size)
	{
		return true;
	}
	return false;
}

void Terrain::printdata()
{
	for (int z = 0; z<getSize() - 1; z++)
		for (int x = 0; x<getSize(); x++)
			cout << ((float)(terrainData[(z*size) + x])*scaleY) << endl;

}