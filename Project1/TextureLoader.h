#ifndef TEXTLOADER_H
#define TEXTLOADER_H
#include <fstream>
#include <iostream>
#include "freeglut.h"

class TextureLoader
{
public:
	GLuint LoadTexture(const char* filename, int size);
};
#endif