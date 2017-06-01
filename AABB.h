#ifndef __AABB_H
#define __AABB_H
#include "vec3.h"

class AABB
{
private:
   vec3 min;
   vec3 max;
   AABB createWorldAABB(AABB aabb,vec3 worldXYZ);
   bool checkCollisonWithPoint(vec3 &point,AABB &aabb);

public:
	AABB();
	AABB(vec3 minVals, vec3 maxVals);
	void createAABB(vec3 vertices[], int numVertices);
	bool checkCollisonWithPoint(vec3 &point, vec3 worldXYZ);
    bool checkCollison(vec3 worldXYZ,AABB &aabb2, vec3 worldXYZ2);
	const AABB &operator=(const AABB &aabb2);
};

#endif