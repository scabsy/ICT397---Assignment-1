#include "Image.h"

Image::Image()
{
	sizeH = 0;
	sizeW = 0;
	id = 0;
}

Image::~Image()
{

}

void Image::SetID(GLuint newId)
{
	id = newId;
}

RGB<unsigned char>  Image::GetColour(int x, int y)
{
	return texData[y*sizeH + x];
}

void Image::SetColour(int x, int y, RGB<unsigned char> rgb)
{
	texData[y*sizeH + x] = rgb;
}

void  Image::SetWidth(int w)
{
	sizeW = w;
}

void  Image::SetHeight(int h)
{
	sizeH = h;
}

void  Image::SetData(RGB<unsigned char>* newData)
{
	texData = newData;
}