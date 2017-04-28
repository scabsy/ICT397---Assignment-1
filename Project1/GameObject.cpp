#include "GameObject.h"
#include "singletons.h"

GameObject::GameObject()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	scale = 1;

	//model = NULL;
}


GameObject::GameObject(vec3 loc, float nscale)
{
	pos = loc;

	scale = nscale;

	//model = NULL;
}

GameObject::GameObject(float x, float y, float z,float nscale)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	scale = nscale;

	//model = NULL;
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

void GameObject::setModel(Mesh modelNum)
{
	model = modelNum;
}


void GameObject::processCollision(GameObject &obj)
{
	if (boundingBox.checkCollison(pos, obj.boundingBox, obj.getPos()))
	{
		onCollision(obj);
	}
}


void GameObject::processCollision(Camera &obj)
{
	vec3 min(obj.pos.x - obj.size, obj.pos.y - obj.size, obj.pos.z - obj.size);
	vec3 max(obj.pos.x + obj.size, obj.pos.y + obj.size, obj.pos.z + obj.size);
	AABB ab(min, max);
	if (boundingBox.checkCollison(pos,ab, obj.pos))
	{
		onCollision(obj);
	}
}

void GameObject::onCollision(GameObject &collisionObject)
{
	//code that performs actions in response to a collision.
	cout << "collision" << endl;
}


void GameObject::onCollision(Camera &collisionObject)
{
	//code that performs actions in response to a collision.
	cout << "collision" << endl;
}

void GameObject::render()
{
	//glClearColor(1.0, 0.0, 1.0, 1.0);
	//glTranslatef(pos.x, gameWorld.terrain.getHeight(pos.x,pos.z)/gameWorld.terrain.getFlatten(), pos.z);
	glPushMatrix();
		glTranslatef(pos.x, pos.y, pos.z);
		glScalef(scale,scale,scale);
		glColor3ub(255, 10, 10);
		glCallList(model.GetID());
	glPopMatrix();
}