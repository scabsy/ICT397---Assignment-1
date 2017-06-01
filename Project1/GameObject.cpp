#include "GameObject.h"
#include "singletons.h"
#include "math.h"

#define PI 3.14159265

GameObject::GameObject()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	scale = 1;

	rot = getRand(360);

	//model = NULL;
}


GameObject::GameObject(Vector::vec3 loc, float nscale)
{
	pos = loc;

	scale = nscale;


	rot = getRand(360);

	//model = NULL;
}

GameObject::GameObject(float x, float y, float z,float nscale)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	scale = nscale;

	rot = getRand(360);

	//model = NULL;
}

GameObject::GameObject(char* nmodel, float x, float y, float z, float nscale)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;

	scale = nscale;

	rot = getRand(360);


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

		boundingBox = AABB(model->minVals,model->maxVals);
		cout << model->minVals.x << " " << model->maxVals.x << endl;
		cout << model->minVals.y << " " << model->maxVals.y << endl;
		cout << model->minVals.z << " " << model->maxVals.z << endl;
	}
	valid = true;
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
	Vector::vec3 min(obj.pos.x - obj.size, obj.pos.y - obj.size, obj.pos.z - obj.size);
	Vector::vec3 max(obj.pos.x + obj.size, obj.pos.y + obj.size, obj.pos.z + obj.size);
	AABB ab(min, max);
	if (boundingBox.checkCollison(pos,ab, obj.pos))
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
	prevPos = pos;
	if (!isColliding)
	{
		if (pos.x != NULL)
		{
			if ((pos.x - obj.pos.x > 10 || pos.x - obj.pos.x < -10) || (pos.z - obj.pos.z > 10 || pos.z - obj.pos.z < -10))
			{
				model->setAnimation("stand");
				if (pos.x < obj.pos.x)
				{
					pos.x += 0.03;
				}
				else
				{
					pos.x -= 0.03;
				}

				if (pos.z < obj.pos.z)
				{
					pos.z += 0.03;
				}
				else
				{
					pos.z -= 0.03;
				}
			}
			else
			{
				model->setAnimation("attak");
			}

			double dx = obj.pos.x - pos.x;
			double dz = obj.pos.z -pos.z;
			double inRad(atan2(dz, dx));
			if (inRad < 0)
			{
				inRad = abs(inRad);
			}
			else
			{
				inRad = 2 * PI - inRad;
			}

			rot = radToDeg(inRad);
		}

	}
}

void GameObject::render(float deltaT)
{
	if (pos.x != NULL)
	{
		glPushMatrix();
			glTranslatef(pos.x, gameWorld.getWorldXZHeight(pos.x, pos.z) / 4, pos.z);
			glRotatef(-90, 1, 0, 0);
			glRotatef(rot, 0,0 , 1);
			glScalef(scale, scale, scale);
			glColor3ub(255, 10, 10);
			model->advance(deltaT/3);
			model->draw();
		glPopMatrix();
	}
}
