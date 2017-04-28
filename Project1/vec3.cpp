#include "vec3.h"

vec3 vec3::operator + (const vec3 &right)const
{
	vec3 newVec;

	newVec.x = x + right.x;
	newVec.y = y + right.y;
	newVec.z = z + right.z;

	return newVec;
}