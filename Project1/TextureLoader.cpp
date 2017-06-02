#include "TextureLoader.h"
using namespace std;


Image* TextureLoader::LoadTexture(const char* filename, int w,int h)
{
	Image* newImg = new Image();
	GLuint texture;
	RGB<unsigned char>* rgbData = new RGB<unsigned char>[w*h];
	unsigned char *data;
	FILE *file;

	// open texture data
	file = fopen(filename, "rb");
	if (file == NULL)
	{
		cout << "Text not load" << endl;
		return NULL;
	}
	// allocate buffer
	data = (unsigned char*)malloc(w * h * 3);

	// read texture data
	fread(data, w * h * 3, 1, file);
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
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, w, h, GL_RGB, GL_UNSIGNED_BYTE, data);

	int counter = 0;
	for (int i = 0; i < w*h; i += 3)
	{
		RGB<unsigned char> val = { data[i], data[i + 1], data[i + 2] };
		rgbData[counter].set(val);
		counter++;
	}

	newImg->SetID(texture);
	newImg->SetWidth(w);
	newImg->SetHeight(h);
	newImg->SetData(rgbData);

	// free buffer
	free(data);
	return newImg;
}


Image* TextureLoader::CreateTexture(unsigned char* data, int w, int h)
{
	Image* newImg = new Image();
	GLuint texture;
	RGB<unsigned char>* rgbData = new RGB<unsigned char>[w*h];
	int counter = 0;

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
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, w, h, GL_RGB, GL_UNSIGNED_BYTE, data);

	for (int i = 0; i < w*h; i += 3)
	{
		RGB<unsigned char> val = { data[i], data[i + 1], data[i + 2] };
		rgbData[counter].set(val);
		counter++;
	}

	newImg->SetID(texture);
	newImg->SetWidth(w);
	newImg->SetHeight(h);
	newImg->SetData(rgbData);

	return newImg;
}