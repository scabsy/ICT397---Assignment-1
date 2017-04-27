#ifndef TEXTUREGEN_H
#define TEXTUREGEN_H
#include "freeglut.h"
#include "Image.h"

class TextureGenerator
{
private:
	Image* tex[4];
	unsigned char* newTex;
	int newTexW;
	int newTexH;
	int newTexBPP;
	int numTextures;
public:
	TextureGenerator();
	~TextureGenerator();
	bool addTex(char* filename,int w, int h);
	int getNumTextures() { return numTextures; }
	bool isLoaded(int index);
	RGB<unsigned char> getColour(int texNum, int x, int y);
	void setColour(int x, int y, RGB<unsigned char> colour);
	unsigned char* getTex() { return newTex; }
	bool setupNewTex(int w, int h);
	float getRange();
	float getTexMax(int texNum);
	unsigned int getTexWidth(int texNo);
	unsigned int getTexHeight(int texNo);
};

#endif
