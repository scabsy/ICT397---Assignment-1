#include "terrain.h"
#include "singletons.h"

bool Terrain::loadHeightfield(char *filename, const int size)
{
	//open for binary read
	ifstream infile(filename, ios::binary);
	if (!infile) { 
		cerr << "Cannot open file : " << filename << endl;
		return false;
	}
	//allocate memory
	if (terrainData)
		delete[] terrainData;
	if (size>0)
		terrainData = new unsigned char[size*size];
	if (terrainData == NULL)
		return false;
	//read in heightfield.
	// get length of file:
	infile.seekg(0, ios::end);
	int length = infile.tellg();
	// read data as a block:
	infile.seekg(0, ios::beg);
	infile.read(reinterpret_cast<char *>(terrainData), length);
	infile.close();
	this->size = size;

	normaliseTerrain(terrainData);
	return true;
}


void Terrain::normaliseTerrain(unsigned char* terrainData)
{
	float fMin, fMax;
	float fHeight;
	float tmp;
	int i;
	fMin = terrainData[0];
	fMax = terrainData[0];

	for (i = 1; i < size*size; i++)
	{

		if (terrainData[i] > fMax)
		{
			fMax = terrainData[i];
		}
		else if (terrainData[i] < fMin)
		{
			fMin = terrainData[i];
		}
	}

	if (fMax <= fMin)
	{
		return;
	}

	fHeight = fMax - fMin;

	for (i = 0; i < size*size; i++)
	{
		terrainData[i] = ((terrainData[i] - fMin) / fHeight)*255.0f;
	}
}


void Terrain::loadTexture(char *filename, const int w, const int h)
{
	texture = texLoad.LoadTexture(filename, w,h);
	if (texture->GetID() > 0)
	{
		textureMapping = true;
	}
}


bool Terrain::addProceduralTexture(char* filename)
{
	if (tex.getNumTextures() < 4)
	{
		tex.addTex(filename, 512, 512);
		return true;
	}
	return false;
}

bool Terrain::createProceduralTexture()
{
	if (!terrainData || tex.getNumTextures() == 0)
	{
		cout << "vcdfa" << endl;
		return false;
	}
	unsigned char curHeight; //current height in the heightmap
	float weight; //weight of influence of tex to height
				  //setup room for the new texture
	tex.setupNewTex(size, size);
	RGB<unsigned char> color;
	RGB<unsigned char> totalColor;
	float range = tex.getRange();
	//loop through each point in the heightmap and get height value
	for (int z = 0; z<size; z++) {
		for (int x = 0; x<size; x++) {
			totalColor.reset();
			curHeight = getHeight(x, z); //get unscaled heightmap value
			for (int i = 0; i<tex.getNumTextures(); i++)
			{ //calculate weight for each texture map
				weight = (range - abs((float)curHeight - tex.getTexMax(i))) / range;
				if (weight>0.0) { //texture is influenced by the height, calculate its color weighting
					unsigned int texX = x;
					unsigned int texZ = z;
					getTexCoords(i,texX, texZ);
					color = tex.getColour(i, texX, texZ);
					totalColor.r += color.r*weight;
					totalColor.g += color.g*weight;
					totalColor.b += color.b*weight;
				}
			} //add the combined color weightings to the new texture.
			tex.setColour(x, z, totalColor);
		}
	}
	//load the new texture into memory ready for use
	texture = texLoad.CreateTexture(tex.getTex(), size, size);
	textureMapping = true;
	//dont repeat this texture
	numTerrainTexRepeat = 0;

	return true;
}

void Terrain::getTexCoords(int texNum, unsigned int& x, unsigned int& y)
{
	unsigned int height = tex.getTexHeight(texNum);
	unsigned int width = tex.getTexWidth(texNum);
	int repeatX = -1; // number of repeats in X direction
	int repeatY = -1; // number of repeats in Y direction
	int i = 0;
	//loop until we figure out how many times the tile has repeated (on the X axis)
	while (repeatX == -1) {
		i++;
		//if x is less than the total width, found
		if (x<(width*i))
			repeatX = i - 1;
	}
	//prepare to figure out the repetition on the Y axis
	i = 0;
	//loop until we figure out how many times the tile has repeated (on the Y axis)
	while (repeatY == -1) {
		i++;
		//if y is less than the total height good
		if (y<(height*i))
			repeatY = i - 1;
	}
	//update the given texture coordinates
	x = x - (width*repeatX);
	y = y - (height*repeatY);
}

void Terrain::setScalingFactor(float xScale, float yScale, float zScale) 
{
	scaleX = xScale;
	scaleY = yScale;
	scaleZ = zScale;
}

float Terrain::getHeight(int xpos, int zpos) {
	if (inbounds(xpos, zpos)) {
		return ((float)(terrainData[(zpos*size) + xpos])*scaleY);
	}
	else {
		return 0;
	}
}

unsigned char Terrain::getHeightColor(int xpos, int zpos) {
	if (inbounds(xpos, zpos)) {
		return (terrainData[((int)(zpos/(size*scaleZ)*size)) + (int)(xpos / (size*scaleZ))]);
	}
	return 1;
}

bool Terrain::inbounds(int xp, int yp)
{
	if (xp >= 0 && xp < size && yp >= 0 && yp < size)
	{
		return true;
	}
	return false;
}

void Terrain::printdata()
{
	for (int z = 0; z<getSize() - 1; z++)
		for (int x = 0; x<getSize(); x++)
			cout << ((float)(terrainData[(z*size) + x])*scaleY) << endl;

}