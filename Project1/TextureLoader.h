#ifndef TEXTLOADER_H
#define TEXTLOADER_H
#include <fstream>
#include <iostream>
#include "freeglut.h"
#include "Image.h"

class TextureLoader
{
public:
	Image* LoadTexture(const char* filename, int w,int h);
	Image* CreateTexture(unsigned char* data, int w, int h);
};
#endif