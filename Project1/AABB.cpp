#include "AABB.h"
#include <iostream>
using namespace std;

AABB::AABB()
{
	min.set(0,0,0);
	max.set(0,0,0);
}

AABB::AABB(vec3 minVals, vec3 maxVals)
{
	min=minVals;
	max=maxVals;
}

void AABB::createAABB(vec3 vertices[], int numVertices)
{
	 for(int i=0;i<numVertices;i++)
	 {
		 if(vertices[i].getX()<min.getX())
		 {
			 min.setX(vertices[i].getX());
		 }
		 if(vertices[i].getX()>max.getX())
		 {
			 max.setX(vertices[i].getX());
		 }
		 if(vertices[i].getY()<min.getY())
		 {
			 min.setY(vertices[i].getY());
		 }
		 if(vertices[i].getY()>max.getY())
		 {
			 max.setY(vertices[i].getY());
		 }
         if(vertices[i].getZ()<min.getZ())
		 {
			 min.setZ(vertices[i].getZ());
		 }
		 if(vertices[i].getZ()>max.getZ())
		 {
			 max.setZ(vertices[i].getZ());
		 }
	 }
}

AABB AABB::createWorldAABB(AABB aabb, vec3 worldXYZ)
{
    AABB worldAABB;
    float temp;

    temp=(float)(aabb.max.getX()-aabb.min.getX())/2.0;
	worldAABB.min.setX(worldXYZ.getX()-temp);
	worldAABB.max.setX(worldXYZ.getX()+temp);

	temp=(float)(aabb.max.getY()-aabb.min.getY())/2.0;
	worldAABB.min.setY(worldXYZ.getY()-temp);
	worldAABB.max.setY(worldXYZ.getY()+temp);

	temp=(float)(aabb.max.getZ()-aabb.min.getZ())/2.0;
	worldAABB.min.setZ(worldXYZ.getZ()-temp);
	worldAABB.max.setZ(worldXYZ.getZ()+temp);

    return worldAABB;
}

bool AABB::checkCollisonWithPoint(vec3 &point, vec3 worldXYZ)
{
     AABB worldAABB=createWorldAABB(*this,worldXYZ);
     return((point.getX()>= worldAABB.min.getX())&&(point.getX()<=worldAABB.max.getX())&&
	   (point.getY()>= worldAABB.min.getY())&&(point.getY()<=worldAABB.max.getY())&&
	   (point.getZ()>= worldAABB.min.getZ())&&(point.getZ()<=worldAABB.max.getZ()));
}


bool AABB::checkCollisonWithPoint(vec3 &point,AABB &aabb)
{
     return((point.getX()>= aabb.min.getX())&&(point.getX()<=aabb.max.getX())&&
	   (point.getY()>= aabb.min.getY())&&(point.getY()<=aabb.max.getY())&&
	   (point.getZ()>= aabb.min.getZ())&&(point.getZ()<=aabb.max.getZ()));
}

bool AABB::checkCollison(vec3 worldXYZ,AABB &aabb2, vec3 worldXYZ2)
{
    AABB obj1=createWorldAABB(*this,worldXYZ);
    AABB obj2=createWorldAABB(aabb2,worldXYZ2);
	vec3 p[8];

	p[0].set(obj1.min.getX(),obj1.min.getY(),obj1.min.getZ());
	p[1].set(obj1.max.getX(),obj1.min.getY(),obj1.min.getZ());
	p[2].set(obj1.max.getX(),obj1.max.getY(),obj1.min.getZ());
	p[3].set(obj1.min.getX(),obj1.max.getY(),obj1.min.getZ());
	p[4].set(obj1.min.getX(),obj1.min.getY(),obj1.max.getZ());
	p[5].set(obj1.max.getX(),obj1.min.getY(),obj1.max.getZ());
	p[6].set(obj1.max.getX(),obj1.max.getY(),obj1.max.getZ());
	p[7].set(obj1.min.getX(),obj1.max.getY(),obj1.max.getZ());
	for(int i=0;i<8;i++)
    {
		if(checkCollisonWithPoint(p[i],obj2))
			  return  true;
	}
    return false;
}

const AABB &AABB::operator=(const AABB &aabb2)
{
	min=aabb2.min;
	max=aabb2.max;
    return *this;
}