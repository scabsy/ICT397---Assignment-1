#ifndef VEC3_H
#define VEC3_H

class vec3
{
public:
	vec3() : x(0), y(0), z(0) {}
	vec3(float nx, float ny, float nz);
	float x;
	float y;
	float z;

	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }

	void setX(float f) { x=f; }
	void setY(float f) { y = f; }
	void setZ(float f) { z = f; }
	void set(float nx, float ny, float nz);
	vec3 operator + (const vec3 &right)const;
};

#endif