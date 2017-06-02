#include "GameObject.h"
#include "singletons.h"
#include "math.h"

GameObject::GameObject()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	scale = 1;

	valid = false;
	rot = (float)getRand(360);
	isAnimated = false;

	//model = NULL;
}


GameObject::GameObject(Vector::vec3 loc, float nscale)
{
	pos = loc;

	scale = nscale;


	rot = (float)getRand(360);

	//model = NULL;
}

GameObject::GameObject(float x, float y, float z,float nscale)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	scale = nscale;

	rot = (float)getRand(360);

	//model = NULL;
}

GameObject::GameObject(char* nmodel, float x, float y, float z, float nscale, bool aii, string filename, bool destory, string t, bool isAnimated)
{
	destoryed = destory;
	pos.x = x;
	pos.y = y;
	pos.z = z;
	tag = t;
	scale = nscale;

	isMoving = true;

	this->isAnimated = isAnimated;
	rot = getRand(360);
	AICheck = aii;
	aiFilename = filename;

	//model = objLoad.loadObject(nmodel);
	cout << "Model: " << nmodel << endl;
	model = md2model::load(nmodel);

	if (model != NULL)
	{
		cout << "texIDCon: " << model->textureID << endl;
		
		model->setAnimation("attaka");

		model->minVals = model->minVals*scale;
		model->maxVals = model->maxVals*scale;

		float xdif = (model->maxVals.x - model->minVals.x) / 2;
		float ydif = (model->maxVals.y - model->minVals.y) / 2;
		float zdif = (model->maxVals.z - model->minVals.z) / 2;

		model->minVals.x = -(xdif);
		model->maxVals.x = (xdif);
		model->minVals.y = -(ydif);
		model->maxVals.y = (ydif);
		model->minVals.z = -(zdif);
		model->maxVals.z = (zdif);

		boundingBox = AABB(model->minVals, model->maxVals);
		cout << model->minVals.x << " " << model->maxVals.x << endl;
		cout << model->minVals.y << " " << model->maxVals.y << endl;
		cout << model->minVals.z << " " << model->maxVals.z << endl;
		valid = true;
	}
	isColliding = false;
}


void GameObject::setPosition(float x, float y, float z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}


void GameObject::setPosition(Vector::vec3 newPos)
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

void GameObject::setModel(md2model* modelNum)
{
	model = modelNum;
}


void GameObject::processCollision(GameObject &obj)
{
	//Vector::vec3 min2(obj.pos.x + obj.model->minVals.x*scale, obj.pos.y + obj.model->minVals.y, obj.pos.z + obj.model->minVals.z*scale);
	//Vector::vec3 max2(obj.pos.x + obj.model->maxVals.x*scale, obj.pos.y + obj.model->maxVals.y, obj.pos.z + obj.model->maxVals.z*scale);
	//boundingBox.setMin(min2);
	//boundingBox.setMax(max2);
	//Vector::vec3 min2(pos.x + model->minVals.x*scale, pos.y + model->minVals.y, pos.z + model->minVals.z*scale);
	//Vector::vec3 max2(pos.x + model->maxVals.x*scale, pos.y + model->maxVals.y, pos.z + model->maxVals.z*scale);
	//boundingBox.setMin(min2);
	//boundingBox.setMax(max2);

	if (boundingBox.checkCollison(pos, obj.boundingBox, obj.getPos()))
	{
		onCollision(obj);
		obj.isColliding = true;
	}
	else
	{
		obj.isColliding = false;
	}
}


void GameObject::processCollision(Camera &obj)
{
	Vector::vec3 min1(obj.pos.x - obj.size, obj.pos.y - obj.size, obj.pos.z - obj.size);
	Vector::vec3 max1(obj.pos.x + obj.size, obj.pos.y + obj.size, obj.pos.z + obj.size);
	obj.aabb.setMin(min1);// = AABB(min1, max1);
	obj.aabb.setMax(max1);
	Vector::vec3 min2(pos.x + model->minVals.x*scale, pos.y + model->minVals.y*scale, pos.z + model->minVals.z*scale);
	Vector::vec3 max2(pos.x + model->maxVals.x*scale, pos.y + model->maxVals.y*scale, pos.z + model->maxVals.z*scale);
	boundingBox.setMin(min2);
	boundingBox.setMax(max2);

	if (boundingBox.checkCollison(pos,obj.aabb, obj.pos))
	{
		onCollision(obj);
		obj.isColliding = true;
	}
	else
	{
		obj.isColliding = false;
	}
}

void GameObject::onCollision(GameObject &collisionObject)
{
	//code that performs actions in response to a collision.
	collisionObject.pos.x = collisionObject.prevPos.x;
	collisionObject.pos.y = collisionObject.prevPos.y;
	collisionObject.pos.z = collisionObject.prevPos.z;
	cout << "collision with obj" << endl;
}


void GameObject::onCollision(Camera &collisionObject)
{
	//code that performs actions in response to a collision.
	collisionObject.pos.x = collisionObject.prevPos.x;
	collisionObject.pos.y = collisionObject.prevPos.y;
	collisionObject.pos.z = collisionObject.prevPos.z;
	cout << "collision with camera" << endl;
}

void GameObject::Update(Camera &obj)
{
	if (AICheck == true)
	{
		prevPos = pos;
		AI::ReadAIFile(aiFilename, this, obj);
	}
}

void GameObject::render(float deltaT)
{
	if (pos.x != NULL)
	{
		pos.y = gameWorld.getWorldXZHeight((int)pos.x, (int)pos.z) / gameWorld.terrain.getFlatten() + ((model->maxVals.y - model->minVals.y) / 2);
		glPushMatrix();
			glTranslatef(pos.x, pos.y, pos.z);
			glRotatef(-90, 1, 0, 0);
			glRotatef(rot, 0,0 , 1);
			glScalef(scale, scale, scale);
			glColor3ub(255, 10, 10);
			if (isAnimated)
				model->advance(deltaT/3);
			model->draw();
		glPopMatrix();
	}
}

bool GameObject::isDestoryed()
{
	return destoryed;
}

//Checks if this gameObject Has AI
bool GameObject::hasAI()
{
	return AICheck;
}

float GameObject::getRot()
{
	return rot;
}

void GameObject::setRot(float rott)
{
	rot = rott;
}

void GameObject::setIsMoving(bool move)
{
	isMoving = move;
}

bool GameObject::getIsMoving()
{
	return isMoving;
}

string GameObject::getTag()
{
	return tag;
}

void GameObject::setTag(string t)
{
	tag = t;
}

bool GameObject::getAnimation()
{
	return isAnimated;
}