#ifndef IMAGE_H
#define IMAGE_H
#include "freeglut.h"

template<class T>
/// Represents Red Green Blue 
struct RGB
{
	T r;
	T g;
	T b;
	void set(RGB<T> rgb) { r = rgb.r; g = rgb.g; b = rgb.b; }
	void reset() { r = 0; g = 0; b = 0; }
};

/**
*Define image to be used for textures
*/
class Image
{
private:
	int id;///reference for the model to be loaded in int form
	
	int sizeW; /// size of terrain
	int sizeH;/// size of terrain

public:
	Image();///basic constructor
	~Image(); /// basic destructor 
	RGB<unsigned char>* texData;/// represents the data needed for texture
	/**
	* @brief Returns the id of the current terrain model
	*/
	int GetID() { return id; }

	/**
	* @brief Sets the id for the model to be used
	* @param int reperestents a new ID
	*/
	void SetID(GLuint newId);

	/**
	* @brief Returns the color of the image
	*/
	RGB<unsigned char> GetColour(int x, int y);

	/**
	* @brief Sets the color for the model to be used
	* @param x, positon x
	* @param y, position y
	* @param RGB, color of image
	*/
	void SetColour(int x, int y,RGB<unsigned char> rgb);

	/**
	* @brief Returns the width of the image
	*/
	int GetWidth() { return sizeW; }

	/**
	* @brief Returns the height of the image
	*/
	int GetHeight() { return sizeH; }

	/**
	* @brief Sets the width of the image
	* @param int w is width
	*/
	void SetWidth(int w);

	/**
	* @brief Sets the height of the image
	* @param int h is height
	*/
	void SetHeight(int h);

	/**
	* @brief Sets the color and data of the image
	* @param RGB is the color
	*/
	void SetData(RGB<unsigned char>* newData);
};

#endif