#include "md2model.h"
#include "singletons.h"
#include <string.h>
#include <stdio.h>

using namespace std;

namespace 
{
	float NORMALS[486] =
	{ -0.525731f,  0.000000f,  0.850651f,
		-0.442863f,  0.238856f,  0.864188f,
		-0.295242f,  0.000000f,  0.955423f,
		-0.309017f,  0.500000f,  0.809017f,
		-0.162460f,  0.262866f,  0.951056f,
		0.000000f,  0.000000f,  1.000000f,
		0.000000f,  0.850651f,  0.525731f,
		-0.147621f,  0.716567f,  0.681718f,
		0.147621f,  0.716567f,  0.681718f,
		0.000000f,  0.525731f,  0.850651f,
		0.309017f,  0.500000f,  0.809017f,
		0.525731f,  0.000000f,  0.850651f,
		0.295242f,  0.000000f,  0.955423f,
		0.442863f,  0.238856f,  0.864188f,
		0.162460f,  0.262866f,  0.951056f,
		-0.681718f,  0.147621f,  0.716567f,
		-0.809017f,  0.309017f,  0.500000f,
		-0.587785f,  0.425325f,  0.688191f,
		-0.850651f,  0.525731f,  0.000000f,
		-0.864188f,  0.442863f,  0.238856f,
		-0.716567f,  0.681718f,  0.147621f,
		-0.688191f,  0.587785f,  0.425325f,
		-0.500000f,  0.809017f,  0.309017f,
		-0.238856f,  0.864188f,  0.442863f,
		-0.425325f,  0.688191f,  0.587785f,
		-0.716567f,  0.681718f, -0.147621f,
		-0.500000f,  0.809017f, -0.309017f,
		-0.525731f,  0.850651f,  0.000000f,
		0.000000f,  0.850651f, -0.525731f,
		-0.238856f,  0.864188f, -0.442863f,
		0.000000f,  0.955423f, -0.295242f,
		-0.262866f,  0.951056f, -0.162460f,
		0.000000f,  1.000000f,  0.000000f,
		0.000000f,  0.955423f,  0.295242f,
		-0.262866f,  0.951056f,  0.162460f,
		0.238856f,  0.864188f,  0.442863f,
		0.262866f,  0.951056f,  0.162460f,
		0.500000f,  0.809017f,  0.309017f,
		0.238856f,  0.864188f, -0.442863f,
		0.262866f,  0.951056f, -0.162460f,
		0.500000f,  0.809017f, -0.309017f,
		0.850651f,  0.525731f,  0.000000f,
		0.716567f,  0.681718f,  0.147621f,
		0.716567f,  0.681718f, -0.147621f,
		0.525731f,  0.850651f,  0.000000f,
		0.425325f,  0.688191f,  0.587785f,
		0.864188f,  0.442863f,  0.238856f,
		0.688191f,  0.587785f,  0.425325f,
		0.809017f,  0.309017f,  0.500000f,
		0.681718f,  0.147621f,  0.716567f,
		0.587785f,  0.425325f,  0.688191f,
		0.955423f,  0.295242f,  0.000000f,
		1.000000f,  0.000000f,  0.000000f,
		0.951056f,  0.162460f,  0.262866f,
		0.850651f, -0.525731f,  0.000000f,
		0.955423f, -0.295242f,  0.000000f,
		0.864188f, -0.442863f,  0.238856f,
		0.951056f, -0.162460f,  0.262866f,
		0.809017f, -0.309017f,  0.500000f,
		0.681718f, -0.147621f,  0.716567f,
		0.850651f,  0.000000f,  0.525731f,
		0.864188f,  0.442863f, -0.238856f,
		0.809017f,  0.309017f, -0.500000f,
		0.951056f,  0.162460f, -0.262866f,
		0.525731f,  0.000000f, -0.850651f,
		0.681718f,  0.147621f, -0.716567f,
		0.681718f, -0.147621f, -0.716567f,
		0.850651f,  0.000000f, -0.525731f,
		0.809017f, -0.309017f, -0.500000f,
		0.864188f, -0.442863f, -0.238856f,
		0.951056f, -0.162460f, -0.262866f,
		0.147621f,  0.716567f, -0.681718f,
		0.309017f,  0.500000f, -0.809017f,
		0.425325f,  0.688191f, -0.587785f,
		0.442863f,  0.238856f, -0.864188f,
		0.587785f,  0.425325f, -0.688191f,
		0.688191f,  0.587785f, -0.425325f,
		-0.147621f,  0.716567f, -0.681718f,
		-0.309017f,  0.500000f, -0.809017f,
		0.000000f,  0.525731f, -0.850651f,
		-0.525731f,  0.000000f, -0.850651f,
		-0.442863f,  0.238856f, -0.864188f,
		-0.295242f,  0.000000f, -0.955423f,
		-0.162460f,  0.262866f, -0.951056f,
		0.000000f,  0.000000f, -1.000000f,
		0.295242f,  0.000000f, -0.955423f,
		0.162460f,  0.262866f, -0.951056f,
		-0.442863f, -0.238856f, -0.864188f,
		-0.309017f, -0.500000f, -0.809017f,
		-0.162460f, -0.262866f, -0.951056f,
		0.000000f, -0.850651f, -0.525731f,
		-0.147621f, -0.716567f, -0.681718f,
		0.147621f, -0.716567f, -0.681718f,
		0.000000f, -0.525731f, -0.850651f,
		0.309017f, -0.500000f, -0.809017f,
		0.442863f, -0.238856f, -0.864188f,
		0.162460f, -0.262866f, -0.951056f,
		0.238856f, -0.864188f, -0.442863f,
		0.500000f, -0.809017f, -0.309017f,
		0.425325f, -0.688191f, -0.587785f,
		0.716567f, -0.681718f, -0.147621f,
		0.688191f, -0.587785f, -0.425325f,
		0.587785f, -0.425325f, -0.688191f,
		0.000000f, -0.955423f, -0.295242f,
		0.000000f, -1.000000f,  0.000000f,
		0.262866f, -0.951056f, -0.162460f,
		0.000000f, -0.850651f,  0.525731f,
		0.000000f, -0.955423f,  0.295242f,
		0.238856f, -0.864188f,  0.442863f,
		0.262866f, -0.951056f,  0.162460f,
		0.500000f, -0.809017f,  0.309017f,
		0.716567f, -0.681718f,  0.147621f,
		0.525731f, -0.850651f,  0.000000f,
		-0.238856f, -0.864188f, -0.442863f,
		-0.500000f, -0.809017f, -0.309017f,
		-0.262866f, -0.951056f, -0.162460f,
		-0.850651f, -0.525731f,  0.000000f,
		-0.716567f, -0.681718f, -0.147621f,
		-0.716567f, -0.681718f,  0.147621f,
		-0.525731f, -0.850651f,  0.000000f,
		-0.500000f, -0.809017f,  0.309017f,
		-0.238856f, -0.864188f,  0.442863f,
		-0.262866f, -0.951056f,  0.162460f,
		-0.864188f, -0.442863f,  0.238856f,
		-0.809017f, -0.309017f,  0.500000f,
		-0.688191f, -0.587785f,  0.425325f,
		-0.681718f, -0.147621f,  0.716567f,
		-0.442863f, -0.238856f,  0.864188f,
		-0.587785f, -0.425325f,  0.688191f,
		-0.309017f, -0.500000f,  0.809017f,
		-0.147621f, -0.716567f,  0.681718f,
		-0.425325f, -0.688191f,  0.587785f,
		-0.162460f, -0.262866f,  0.951056f,
		0.442863f, -0.238856f,  0.864188f,
		0.162460f, -0.262866f,  0.951056f,
		0.309017f, -0.500000f,  0.809017f,
		0.147621f, -0.716567f,  0.681718f,
		0.000000f, -0.525731f,  0.850651f,
		0.425325f, -0.688191f,  0.587785f,
		0.587785f, -0.425325f,  0.688191f,
		0.688191f, -0.587785f,  0.425325f,
		-0.955423f,  0.295242f,  0.000000f,
		-0.951056f,  0.162460f,  0.262866f,
		-1.000000f,  0.000000f,  0.000000f,
		-0.850651f,  0.000000f,  0.525731f,
		-0.955423f, -0.295242f,  0.000000f,
		-0.951056f, -0.162460f,  0.262866f,
		-0.864188f,  0.442863f, -0.238856f,
		-0.951056f,  0.162460f, -0.262866f,
		-0.809017f,  0.309017f, -0.500000f,
		-0.864188f, -0.442863f, -0.238856f,
		-0.951056f, -0.162460f, -0.262866f,
		-0.809017f, -0.309017f, -0.500000f,
		-0.681718f,  0.147621f, -0.716567f,
		-0.681718f, -0.147621f, -0.716567f,
		-0.850651f,  0.000000f, -0.525731f,
		-0.688191f,  0.587785f, -0.425325f,
		-0.587785f,  0.425325f, -0.688191f,
		-0.425325f,  0.688191f, -0.587785f,
		-0.425325f, -0.688191f, -0.587785f,
		-0.587785f, -0.425325f, -0.688191f,
		-0.688191f, -0.587785f, -0.425325f };

	bool littleEndian()
	{
		short s = 1;
		return (((char*)&s)[0]) == 1;
	}

	int toInt(const char* bytes)
	{
		return (int)((	( unsigned char)bytes[3] << 24) |
						((unsigned char)bytes[2] << 16) |
						((unsigned char)bytes[1] << 8)  |
						( unsigned char)bytes[0]);
	}

	short toShort(const char* bytes)
	{
		return (short)(((unsigned char)bytes[1] << 8) | (unsigned char)bytes[0]);
	}

	unsigned short toUShort(const char* bytes)
	{
		return (unsigned short)(((unsigned char)bytes[1] << 8) | (unsigned char)bytes[0]);
	}

	float toFloat(const char* bytes)
	{
		float f;
		if (littleEndian())
		{
			((char*)&f)[0] = bytes[0];
			((char*)&f)[1] = bytes[1];
			((char*)&f)[2] = bytes[2];
			((char*)&f)[3] = bytes[3];
		}
		else
		{
			((char*)&f)[0] = bytes[3];
			((char*)&f)[1] = bytes[2];
			((char*)&f)[2] = bytes[1];
			((char*)&f)[3] = bytes[0];
		}
		return f;
	}

	int readInt(ifstream &input)
	{
		char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);
	}

	short readShort(ifstream &input)
	{
		char buffer[2];
		input.read(buffer, 2);
		return toShort(buffer);
	}

	unsigned short readUShort(ifstream &input)
	{
		char buffer[2];
		input.read(buffer, 2);
		return toUShort(buffer);
	}

	float readFloat(ifstream &input)
	{
		char buffer[4];
		input.read(buffer, 4);
		return toFloat(buffer);
	}

	Vec3f readVec3(ifstream &input)
	{
		float x = readFloat(input);
		float y = readFloat(input);
		float z = readFloat(input);
		return Vec3f(x, y, z);
	}

	GLuint loadTexture(Image* image)
	{
		GLuint textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->GetWidth(), image->GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image->texData);
		return textureID;
	}
}

md2model::md2model()
{
	frames = NULL;
	texCoords = NULL;
	triangles = NULL;
	time = 0;
	minVals = Vector::vec3(0, 0, 0);
	maxVals = Vector::vec3(0, 0, 0);
}

md2model::~md2model()
{
	if (frames != NULL)
	{
		for (int i = 0; i < numFrames; i++)
		{
			delete[] frames[i].vertices;
		}
		delete[] frames;
	}

	if (texCoords != NULL)
	{
		delete[] texCoords;
	}
	if (triangles != NULL)
	{
		delete[] triangles;
	}
}

md2model* md2model::load(const char *filename)
{
	ifstream input;
	input.open(filename, istream::binary);

	char buffer[64];
	input.read(buffer, 4);
	if (buffer[0] != 'I' || buffer[1] != 'D' || buffer[2] != 'P' || buffer[3] != '2')
	{
		cout << "wrong format" << endl;
		return NULL;
	}

	if (readInt(input) != 8)
	{
		cout << "wrong version" << endl;
		return NULL;
	}

	int textureWidth = readInt(input);
	int textureHeight = readInt(input);
	readInt(input);
	int numTextures = readInt(input);
	if (numTextures != 1)
	{
		cout << "too many textures" << endl;
		//return NULL;
	}
	int numVertices = readInt(input);
	int numTexCoords = readInt(input);
	int numTriangles = readInt(input);
	readInt(input);
	int numFrames = readInt(input);

	int textureOffset = readInt(input);
	int texCoordsOffset = readInt(input);
	int triangleOffset = readInt(input);
	int frameOffset = readInt(input);
	readInt(input);
	readInt(input);

	input.seekg(textureOffset, ios_base::beg);
	input.read(buffer, 64);
	if (strlen(buffer) < 5)// strcmp(buffer + strlen(buffer) - 4, ".pcx") != 0)
	{
		cout << "wrong texture format" << endl;
		return NULL;
	}

	if (strcmp(buffer + strlen(buffer) - 4, ".raw")!=0)
	{
		buffer[strlen(buffer) - 3] = 'r';
		buffer[strlen(buffer) - 2] = 'a';
		buffer[strlen(buffer) - 1] = 'w';
	}

	string md2Name(filename);
	string texName(buffer);
	string path = md2Name.substr(0, md2Name.find_last_of('/')+1);
	cout << "Path:" << path << endl;
	string fname;
	if (texName.find_last_of('/')+2 >= 0)
	{
		fname = texName.substr(texName.find_last_of('/')+1);
	}
	else
	{
		fname = texName;
	}
	 
	cout << fname << endl;
	string texFName = path + fname;
	cout << "Texture file: " << texFName << endl;
	Image* image = texLoad.LoadTexture(texFName.c_str(),textureWidth,textureHeight);
	GLuint textureID = loadTexture(image);
	delete image;
	md2model* model = new md2model();
	model->textureID = textureID;

	input.seekg(texCoordsOffset, ios_base::beg);
	model->texCoords = new MD2TexCoord[numTexCoords];
	for (int i = 0; i < numTexCoords; i++)
	{
		MD2TexCoord* texCoord = model->texCoords + i;
		texCoord->texCoordX = (float)readShort(input) / textureWidth;
		texCoord->texCoordY = 1 - (float)readShort(input) / textureHeight;
	}

	input.seekg(triangleOffset, ios_base::beg);
	model->triangles = new MD2Triangle[numTriangles];
	model->numTriangles = numTriangles;
	for (int i = 0; i < numTriangles; i++) {
		MD2Triangle* triangle = model->triangles + i;
		for (int j = 0; j < 3; j++) {
			triangle->vertices[j] = readUShort(input);
		}
		for (int j = 0; j < 3; j++) {
			triangle->texCoords[j] = readUShort(input);
		}
	}

	input.seekg(frameOffset, ios_base::beg);
	model->frames = new MD2Frame[numFrames];
	model->numFrames = numFrames;
	for (int i = 0; i < numFrames; i++)
	{
		MD2Frame* frame = model->frames + i;
		frame->vertices = new MD2Vertex[numVertices];
		Vec3f scale = readVec3(input);
		Vec3f translation = readVec3(input);
		input.read(frame->name, 16);
		cout << frame->name << endl;
		for (int j = 0; j < numVertices; j++)
		{
			MD2Vertex* vertex = frame->vertices + j;
			input.read(buffer, 3);
			Vec3f v((unsigned char)buffer[0], (unsigned char)buffer[1], (unsigned char)buffer[2]);
			vertex->pos = translation + Vec3f(scale[0] * v[0], scale[1] * v[1], scale[2] * v[2]);
			input.read(buffer, 1);
			int normalIndex = (int)((unsigned char)buffer[0]);
			vertex->normal = Vec3f(NORMALS[3 * normalIndex], NORMALS[3 * normalIndex] + 1, NORMALS[3 * normalIndex] + 2);

			if (vertex->pos[0] > model->maxVals.x)
			{
				model->maxVals.x = vertex->pos[0];
			}
			else if (vertex->pos[0] < model->maxVals.x)
			{
				model->minVals.x = vertex->pos[0];
			}

			if (vertex->pos[1] > model->maxVals.y)
			{
				model->maxVals.y = vertex->pos[1];
			}
			else if (vertex->pos[1] < model->maxVals.y)
			{
				model->minVals.y = vertex->pos[1];
			}

			if (vertex->pos[2] > model->maxVals.z)
			{
				model->maxVals.z = vertex->pos[2];
			}
			else if (vertex->pos[2] < model->maxVals.z)
			{
				model->minVals.z = vertex->pos[2];
			}
		}
	}

	model->startFrame = 0;
	model->endFrame = numFrames - 1;
	cout << "TimeL: " << model->time << endl;
	return model;
}

void md2model::setAnimation(const char *name)
{
	bool found = false;
	for (int i = 0; i < numFrames; i++)
	{
		MD2Frame* frame = frames + i;
		if (strlen(frame->name) > strlen(name) && strncmp(frame->name, name, strlen(name)) == 0 && !isalpha(frame->name[strlen(name)]))
		{
			if (!found)
			{
				found = true;
				startFrame = i;
			}
			else
			{
				endFrame = i;
			}
		}
		else if (found)
		{
			break;
		}
	}
}

void md2model::advance(float dt)
{
	if (dt < 0)
	{
		return;
	}

	time += dt;
	if (time < 1000000000)
	{
		time -= (int)time;
	}
	else
	{
		time = 0;
	}
}

void md2model::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int frameIndex1 = (int)(time*(endFrame - startFrame + 1)) + startFrame;
	if (frameIndex1 > endFrame)
	{
		frameIndex1 = startFrame;
	}

	int frameIndex2;
	if (frameIndex1 < endFrame)
	{
		frameIndex2 = frameIndex1 + 1;
	}
	else
	{
		frameIndex2 = startFrame;
	}
	MD2Frame* frame1 = frames + frameIndex1;
	MD2Frame* frame2 = frames + frameIndex2;

	//Figure out the fraction that we are between the two frames
	float frac = (time - (float)(frameIndex1 - startFrame) /	(float)(endFrame - startFrame + 1)) * (endFrame - startFrame + 1);

	//Draw the model as an interpolation between the two frames
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < numTriangles; i++) {
		MD2Triangle* triangle = triangles + i;
		for (int j = 0; j < 3; j++)
		{
			MD2Vertex* v1 = frame1->vertices + triangle->vertices[j];
			MD2Vertex* v2 = frame2->vertices + triangle->vertices[j];
			Vec3f pos = v1->pos * (1 - frac) + v2->pos * frac;
			Vec3f normal = v1->normal * (1 - frac) + v2->normal * frac;
			if (normal[0] == 0 && normal[1] == 0 && normal[2] == 0) 
			{
				normal = Vec3f(0, 0, 1);
			}
			glNormal3f(normal[0], normal[1], normal[2]);

			MD2TexCoord* texCoord = texCoords + triangle->texCoords[j];
			glTexCoord2f(texCoord->texCoordX, texCoord->texCoordY);
			glVertex3f(pos[0], pos[1], pos[2]);

		}
	}
	glEnd();
}
