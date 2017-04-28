#include "GameObject.h"
#include "singletons.h"

GameObject::GameObject()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	scale = 1;

	model = 0;
}


GameObject::GameObject(vec3 loc, float nscale)
{
	pos = loc;

	scale = nscale;

	model = 0;
}

GameObject::GameObject(float x, float y, float z,float nscale)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	scale = nscale;

	model = 0;
}

GameObject::GameObject(char * nmodel, float x, float y, float z, float nscale)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	scale = nscale;

	model = objLoad.loadObject(nmodel);
}

void GameObject::setPosition(float x, float y, float z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}


void GameObject::setPosition(vec3 newPos)
{
	pos = newPos;
}

void GameObject::setPosX(float x)
{
	pos.x = x;
}

void GameObject::setPosY(float y)
{
	pos.y = y;
}

void GameObject::setPosZ(float z)
{
	pos.z = z;
}


void GameObject::setScale(float newScale)
{
	scale = newScale;
}

void GameObject::setModel(int modelNum)
{
	model = modelNum;
}

void GameObject::render()
{
	glTranslatef(pos.x, gameWorld.terrain.getHeight(pos.x,pos.z)/gameWorld.terrain.getFlatten()+1, pos.z);
	glScalef(scale,scale,scale);
	glCallList(model);
}
