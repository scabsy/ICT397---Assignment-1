#ifndef IMAGE_H
#define IMAGE_H
#include "freeglut.h"

template<class T>
struct RGB
{
	T r;
	T g;
	T b;
	void set(RGB<T> rgb) { r = rgb.r; g = rgb.g; b = rgb.b; }
	void reset() { r = 0; g = 0; b = 0; }
};

class Image
{
private:
	int id;
	RGB<unsigned char>* texData;
	int sizeW;
	int sizeH;

public:
	Image();
	~Image();
	int GetID() { return id; }
	void SetID(GLuint newId);
	RGB<unsigned char> GetColour(int x, int y);
	void SetColour(int x, int y,RGB<unsigned char> rgb);

	int GetWidth() { return sizeW; }
	int GetHeight() { return sizeH; }
	void SetWidth(int w);
	void SetHeight(int h);
	void SetData(RGB<unsigned char>* newData);
};

#endif