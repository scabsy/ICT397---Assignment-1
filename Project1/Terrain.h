#ifndef TERRAIN_H
#define TERRAIN_H

#include <fstream>
#include <iostream>
#include "freeglut.h"
#include "Image.h"
#include "TextureGenerator.h"
using namespace std;

/**
* Defines terrain for level
*/
class Terrain
{
	protected:		
		unsigned char *textData;///data about texture
		float scaleX;/// x scale of texture 
		float scaleY;/// y scale of texture
		float scaleZ;/// z scale of texture
		bool textureMapping;/// statement to check if it worked or not
		TextureGenerator tex;///instance of a texture
		int numTerrainTexRepeat;///dont repreat this texture
		Image* texture; /// image to be used 
	private:
		int size;/// size of this.

	public:
		unsigned char *terrainData; ///data of terrain

		/**
		* @brief returns true if heightfield was found and loaded.
		* @param filename is the .raw where the heightfield is
		* @param size is how big it is
		*/
		bool loadHeightfield(char *filename, const int size);
		
		/**
		* @brief reads in the texture to be used
		* @param filename is the .raw where the texture is
		* @param w and h are width and height of texture
		*/
		void loadTexture(char *filename, const int w,const int h);

		/**
		* @brief sets the scale for the terrain texture
		*/
		void setScalingFactor(float xScale, float yScale, float zScale);

		/**
		* returns the height of the terrain
		*/
		float getHeight(int xpos, int zpos);

		/**
		* returns the height color
		*/
		unsigned char getHeightColor(int xpos, int zpos);

		/**
		* returns the size of this
		*/
		int getSize() { return size; }

		/**
		* @brief checks the bounds of the terrain and textures
		*/
		bool inbounds(int xp, int yp);

		/**
		* @brief used for debugging
		*/
		void printdata();

		/**
		*  @brief will normalise the data in terrain to make sure everything is calucalted the same
		* @param char * terrainData the terrain to be modified
		*/
		void normaliseTerrain(unsigned char* terrainData);

		/**
		* @brief adds procedural texture to the terrain data to be used for terrain generation
		* @param filename of the .raw to be used as the texture for generation of terrain
		*/
		bool addProceduralTexture(char* filename);

		/**
		* @brief returns true if all proceduralTextures are there to be used for generation
		*/
		bool createProceduralTexture();

		/**
		* returns the co-ordinates of the terrain
		*/
		void getTexCoords(int texNum, unsigned int& x, unsigned int& y);
};
#endif