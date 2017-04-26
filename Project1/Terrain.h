<<<<<<< HEAD
#include <fstream>
#include <iostream>
#include "freeglut.h"
using namespace std;

struct Texture
{
	GLuint id;
	int size;
};

class Terrain
{
	protected:
		
		unsigned char *textData;
		float scaleX;
		float scaleY;
		float scaleZ;
		bool textureMapping;
		GLuint texture;
		int texCount;
	private:
		int size;

	public:
		unsigned char *terrainData;
		bool loadHeightfield(char *filename, const int size);
		void loadTexture(char *filename, const int size);
		void setScalingFactor(float xScale, float yScale, float zScale);
		float getHeight(int xpos, int zpos);
		unsigned char getHeightColor(int xpos, int zpos);
		int getSize() { return size; }
		bool inbounds(int xp, int yp);
		void printdata();
=======
#include <fstream>
#include <iostream>
#include "freeglut.h"
using namespace std;

struct Texture
{
	GLuint id;
	int size;
};

class Terrain
{
	protected:
		
		unsigned char *textData;
		float scaleX;
		float scaleY;
		float scaleZ;
		bool textureMapping;
		GLuint texture;
		int texCount;
	private:
		int size;

	public:
		unsigned char *terrainData;
		bool loadHeightfield(char *filename, const int size);
		void loadTexture(char *filename, const int size);
		void setScalingFactor(float xScale, float yScale, float zScale);
		float getHeight(int xpos, int zpos);
		unsigned char getHeightColor(int xpos, int zpos);
		int getSize() { return size; }
		bool inbounds(int xp, int yp);
		void printdata();
>>>>>>> origin/master
};