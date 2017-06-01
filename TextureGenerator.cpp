#include "TextureGenerator.h"
#include "singletons.h"

TextureGenerator::TextureGenerator()
{
	for (int i = 0; i < 4; i++)
	{
		tex[i] = NULL;
	}
	numTextures = 0;
	newTex = NULL;
	newTexW = 0;
	newTexH = 0;
	newTexBPP = 3;
}

TextureGenerator::~TextureGenerator() 
{
	delete newTex;
	for (int i = 0; i < 4; i++)
	{
		delete tex[i];
	}
}

bool TextureGenerator::addTex(char* filename,int w,int h) 
{
	if (numTextures < 4)
	{
		numTextures++;
		if (tex[numTextures - 1] = texLoad.LoadTexture(filename, w, h))
		{
			return true;
		}
	}
	return false;
}

bool TextureGenerator::isLoaded(int index)
{
	if (index<4 && index>-1)
	{
		return(tex[index] != NULL);
	}
	return false;
}

RGB<unsigned char> TextureGenerator::getColour(int texNum, int x, int y)
{
	RGB<unsigned char> val = { 0,0,0 };
	if (texNum > 3 || texNum < 0)
	{
		return val;
	}
	return tex[texNum]->GetColour(x, y);
}

void TextureGenerator::setColour(int x, int y, RGB<unsigned char> colour)
{
	if ((x < newTexW) && (y < newTexH))
	{
		newTex[((y*newTexH) + x)*newTexBPP] = colour.r;
		newTex[((y*newTexH) + x)*newTexBPP + 1] = colour.g;
		newTex[((y*newTexH) + x)*newTexBPP + 2] = colour.b;
	}
}

bool TextureGenerator::setupNewTex(int w, int h)
{
	//to add - ensure power of 2
	newTexH = w;
	newTexW = h;
	newTex = new unsigned char[newTexH*newTexW*newTexBPP];
	if (!newTex)
		return false;
	return true;
}

float TextureGenerator::getRange()
{
	if (numTextures>0)
		return 255.0 / (float)numTextures;
	return 0.0;
}

float TextureGenerator::getTexMax(int texNum)
{
	if (texNum>numTextures - 1)
		return 0.0;
	else
		return((255.0 / (float)numTextures)*(texNum + 1));
}

unsigned int TextureGenerator::getTexWidth(int texNo)
{
	if (texNo>0 && texNo <numTextures)
		return tex[texNo]->GetWidth();
	return -1;
}

unsigned int TextureGenerator::getTexHeight(int texNo)
{
	if (texNo>0 && texNo <numTextures)
		return tex[texNo]->GetHeight();
	return -1;
}

