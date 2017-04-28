#ifndef VEC3_H
#define VEC3_H

class vec3
{
public:
	vec3() : x(0), y(0), z(0) {}
	float x;
	float y;
	float z;

	vec3 operator + (const vec3 &right)const;
};

#endif