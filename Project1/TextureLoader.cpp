#include "TextureLoader.h"
using namespace std;


GLuint TextureLoader::LoadTexture(const char* filename, int size)
{
	GLuint texture;
	unsigned char *data;
	FILE *file;

	// open texture data
	file = fopen(filename, "rb");
	if (file == NULL)
	{
		cout << "Text not load" << endl;
		return -1;
	}
	cout << "Text load" << endl;
	// allocate buffer
	data = (unsigned char*)malloc(size * size * 3);

	// read texture data
	fread(data, size * size * 3, 1, file);
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
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, size, size, GL_RGB, GL_UNSIGNED_BYTE, data);

	

	// free buffer
	free(data);

	return texture;
}