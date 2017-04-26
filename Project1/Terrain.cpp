#include "terrain.h"


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
	//GLuint texture;
	unsigned char *data;
	FILE *file;

	// open texture data
	file = fopen(filename, "rb");
	if (file == NULL)
	{
		cout << "Text not load" << endl; 
		return;
	}
	cout << "Text load" << endl;
	// allocate buffer
	data = (unsigned char*)malloc(size * size * 3);

	// read texture data
	fread(data, size * size * 3, 1, file);
	fclose(file);
	// allocate a texture name
	glGenTextures(1, &texture);

	// select our current texture
	glBindTexture(GL_TEXTURE_2D, texture);

	// select modulate to mix texture with color for shading
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);

	// when texture area is small, bilinear filter the closest mipmap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	// when texture area is large, bilinear filter the first mipmap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// texture should tile
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// build our texture mipmaps
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, size, size, GL_RGB, GL_UNSIGNED_BYTE, data);

	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << i*size + j<<": " <<(float)data[i*size + j] << endl;
		}
	}*/

	// free buffer
	free(data);

	textureMapping = true;
	//return texture;
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
		//return (terrainData[(zpos / ((size / scaleZ)*size))*size) + (xpos)]);
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