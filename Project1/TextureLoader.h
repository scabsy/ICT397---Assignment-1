#ifndef TEXTLOADER_H
#define TEXTLOADER_H
#include <fstream>
#include <iostream>
#include "freeglut.h"
#include "Image.h"

/**
* Defines loader for textures
*/
class TextureLoader
{
public:
	/**
	* @brief loads in the texture and uses openGL to manipulate it
	* @param filename is the file to be used for the texture
	* @param w and h are width and height of texture
	*/
	Image* LoadTexture(const char* filename, int w,int h);

	/**
	* @brief loads in the texture and preps it for use by openGL
	* @param data of the texture
	* @param w and h are width and height of texture
	*/
	Image* CreateTexture(unsigned char* data, int w, int h);
};
#endif