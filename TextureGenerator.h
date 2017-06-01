#ifndef TEXTUREGEN_H
#define TEXTUREGEN_H
#include "freeglut.h"
#include "Image.h"

/**
* Loaded and combined texture to be used on terrain
*/
class TextureGenerator
{
private:
	Image* tex[4]; ///image to be used for texture 
	unsigned char* newTex;/// data for texture 
	int newTexW;/// width of texture
	int newTexH;/// height of texture 
	int newTexBPP;///bytes per pixel
	int numTextures;///number of textures being mixed
public:
	TextureGenerator();///basic constructor
	~TextureGenerator();/// basic destructor

	/**
	* @brief returns true if texture was found and loaded.
	* @param filename is the .raw where the texture file is
	* @param int w and h are height and width of texture
	*/
	bool addTex(char* filename,int w, int h);

	/**
	* @brief returns the number of textures
	*/
	int getNumTextures() { return numTextures; }

	///checks if texture has been loaded on this index 
	bool isLoaded(int index);

	///returns the color of texture
	RGB<unsigned char> getColour(int texNum, int x, int y);

	///sets the color of the texture
	void setColour(int x, int y, RGB<unsigned char> colour);

	/// returns the texture data
	unsigned char* getTex() { return newTex; }

	/**
	* @brief builds the new texture
	* @param int w and h and height and width of texture
	*/
	bool setupNewTex(int w, int h);

	///returns the range 
	float getRange();

	///returns size
	float getTexMax(int texNum);

	///returns width of texture by textures ID
	unsigned int getTexWidth(int texNo);

	///returns height of texture by textures ID
	unsigned int getTexHeight(int texNo);

};

#endif
