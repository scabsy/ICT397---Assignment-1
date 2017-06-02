#ifndef __AABB_H
#define __AABB_H
#include "vec3.h"

class AABB
{
private:
	Vector::vec3 min;
	Vector::vec3 max;
	AABB createWorldAABB(AABB aabb, Vector::vec3 worldXYZ);
	bool checkCollisonWithPoint(Vector::vec3 &point, AABB &aabb);

public:
	AABB();
	AABB(Vector::vec3 minVals, Vector::vec3 maxVals);
	void createAABB(Vector::vec3 vertices[], int numVertices);
	bool checkCollisonWithPoint(Vector::vec3 &point, Vector::vec3 worldXYZ);
	bool checkCollison(Vector::vec3 worldXYZ, AABB &aabb2, Vector::vec3 worldXYZ2);
	const AABB &operator=(const AABB &aabb2);
	void setMin(Vector::vec3 minn);
	void setMax(Vector::vec3 maxx);
};

#endif