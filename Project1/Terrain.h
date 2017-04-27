#ifndef TERRAIN_H
#define TERRAIN_H

#include <fstream>
#include <iostream>
#include "freeglut.h"
#include "Image.h"
#include "TextureGenerator.h"
using namespace std;

struct Texture
{
	GLuint id;
	int size;
};

class Terrain
{
	protected:		
		unsigned char *textData;
		float scaleX;
		float scaleY;
		float scaleZ;
		bool textureMapping;
		TextureGenerator tex;
		int numTerrainTexRepeat;
		Image* texture;
	private:
		int size;

	public:
		unsigned char *terrainData;
		bool loadHeightfield(char *filename, const int size);
		void loadTexture(char *filename, const int w,const int h);
		void setScalingFactor(float xScale, float yScale, float zScale);
		float getHeight(int xpos, int zpos);
		unsigned char getHeightColor(int xpos, int zpos);
		int getSize() { return size; }
		bool inbounds(int xp, int yp);
		void printdata();
		void normaliseTerrain(unsigned char* terrainData);
		bool addProceduralTexture(char* filename);
		bool createProceduralTexture();
		void getTexCoords(int texNum, unsigned int& x, unsigned int& y);
};
#endif